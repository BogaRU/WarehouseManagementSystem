//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_main_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_main *form_main;
//---------------------------------------------------------------------------
bool flag_edit = 0;





//---------------------------------------------------------------------------
__fastcall Tform_main::Tform_main(TComponent* Owner)
	: TForm(Owner)
{
	AnsiString pathDB = ".\\DataBase";
	const char* pathDBc = pathDB.c_str();
	mkdir(pathDBc);

	OleVariant ADOEngine;
   if(!FileExists(".\\DataBase\\Workers.mdb")) // Проверка, существует ли файл с таким именем.
   {
	  try
	  {
		Variant vAccess = CreateOleObject("Access.Application");
		vAccess.OleFunction("NewCurrentDatabase", ".\\DataBase\\Workers.mdb");
        vAccess.OleFunction("Quit");
		vAccess = Unassigned;
	  }
	  catch(...)
	  {
         ShowMessage("При создании файла возникла ошибка.");
	  }

   }
}
//---------------------------------------------------------------------------
void __fastcall Tform_main::Button1Click(TObject *Sender)
{
	const char*	   szSourceString = QRCODE_TEXT;
	unsigned int   unWidth, x, y, l, n, unWidthAdjusted, unDataBytes;
	unsigned char* pRGBData, *pSourceData, *pDestData;
	QRcode*	   pQRC;
	FILE*	   f;

/*
 * Создание символа из строки. Библиотека автоматически
 * парсит входную строку и кодирует ее в символ QR-кода.
 * WARNING: Эта функция THREAD-UNSAFE, когда pthread отключен.
 * Параметры:
 * string: входная строка; должна завершаться нулем
 * version: версия символа; если 0, библиотека выбирает минимальную версию входных данных
 * level: уровень коррекции ошибок
 * hint: указывает библиотеке на то, как должны кодироваться не алфавитные символы
 *       QR_MODE_KANJI - иероглифы будут кодироваться как Shif-JIS
 *       QR_MODE_8 - все не алфавитные символы будут кодироваться как есть. Для UTF-8, выбирайте этот режим
 * casesensitive: case-sensitive(1) или нет(0).
 * return: экземпляр класса QRcode; при ошибке возвращается NULL и errno устанавливает ошибку
 *         EINVAL: некорректный входной объект
 *         ENOMEM: не удается выделить память для входных объектов
 *         ERANGE: входные данные слишком большие
 */

	// Вычисление QRcode
	if ((pQRC = QRcode_encodeString(szSourceString, 0, QR_ECLEVEL_H, QR_MODE_8, 1)))
	{
		unWidth = pQRC->width;
		unWidthAdjusted = unWidth * OUT_FILE_PIXEL_PRESCALER * 3;
		if (unWidthAdjusted % 4)
			unWidthAdjusted = (unWidthAdjusted / 4 + 1) * 4;
		unDataBytes = unWidthAdjusted * unWidth * OUT_FILE_PIXEL_PRESCALER;

		if (!(pRGBData = (unsigned char*)malloc(unDataBytes)))
		{

			exit(1);
		}

		memset(pRGBData, 0xff, unDataBytes);

		// Подготовка заголовков bmp
		BITMAPFILEHEADER kFileHeader;
		kFileHeader.bfType = 0x4d42;  // "BM"
		kFileHeader.bfSize =	sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + unDataBytes;
		kFileHeader.bfReserved1 = 0;
		kFileHeader.bfReserved2 = 0;
		kFileHeader.bfOffBits =	sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

		BITMAPINFOHEADER kInfoHeader;
		kInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
		kInfoHeader.biWidth = unWidth * OUT_FILE_PIXEL_PRESCALER;
		kInfoHeader.biHeight = -((int)unWidth * OUT_FILE_PIXEL_PRESCALER);
		kInfoHeader.biPlanes = 1;
		kInfoHeader.biBitCount = 24;
		kInfoHeader.biCompression = BI_RGB;
		kInfoHeader.biSizeImage = 0;
		kInfoHeader.biXPelsPerMeter = 0;
		kInfoHeader.biYPelsPerMeter = 0;
		kInfoHeader.biClrUsed = 0;
		kInfoHeader.biClrImportant = 0;

		// Конвертирование битов QrCode в bmp пиксели
		pSourceData = pQRC->data;
		for(y = 0; y < unWidth; y++)
		{
			pDestData = pRGBData + unWidthAdjusted * y * OUT_FILE_PIXEL_PRESCALER;
			for(x = 0; x < unWidth; x++)
			{
				if (*pSourceData & 1)
					for(l = 0; l < OUT_FILE_PIXEL_PRESCALER; l++)
						for(n = 0; n < OUT_FILE_PIXEL_PRESCALER; n++)
						{
							*(pDestData + n * 3 + unWidthAdjusted * l) = PIXEL_COLOR_B;
							*(pDestData + 1 + n * 3 + unWidthAdjusted * l) = PIXEL_COLOR_G;
							*(pDestData + 2 + n * 3 + unWidthAdjusted * l) = PIXEL_COLOR_R;
						}
				pDestData += 3 * OUT_FILE_PIXEL_PRESCALER;
				pSourceData++;
			}
		}

		if (!(fopen_s(&f, OUT_FILE, "wb")))
		{
			fwrite(&kFileHeader, sizeof(BITMAPFILEHEADER), 1, f);
			fwrite(&kInfoHeader, sizeof(BITMAPINFOHEADER), 1, f);
			fwrite(pRGBData, sizeof(unsigned char), unDataBytes, f);

			fclose(f);
		}
		else
		{
			 //unable to open file
			exit(1);
		}

		free(pRGBData);
		QRcode_free(pQRC);
	}
	else
	{
			// NULL returned
		exit(1);
	}

}
//---------------------------------------------------------------------------

void __fastcall Tform_main::DBGrid1CellClick(TColumn *Column)
{
	//Узнать номер строки *код снизу*
	//ShowMessage(DBGrid1->DataSource->DataSet->RecNo);
	ADOTable1->Edit();
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::bt_enterClick(TObject *Sender)
{
	//    Показывает значение столбца "код" выделенной строки
	//ShowMessage(ADOTable1->Fields->Fields[0]->AsString);
	if (edit_pas->Text == ADOTable1->Fields->Fields[2]->AsString) {
			form_storage->Show();
			form_main->Hide();
	}
	else ShowMessage("Пароль неверный");
}
//---------------------------------------------------------------------------


void __fastcall Tform_main::bt_adminClick(TObject *Sender)
{
		if (bt_add->Visible == false) {
			if (edit_pas->Text == "useR") {
				bt_admin->Caption = "Выйти из режима администратора";
				form_main->Width += 140;
				edit_pas->Left += 140;
				//edit_pas->Top += 30;
				bt_admin->Left  += 140;
				//bt_admin->Top += 30;
				bt_enter->Left += 140;
				//bt_enter->Top += 30;
				text_pas->Left += 140;
				StaticText2->Left += 200;
				StaticTextCount->Left += 200;
				//text_pas->Top += 30;
				DBGrid1->Width = 342;
				DBGrid1->Columns->Items[2]->Width = 139;
				DBGrid1->Columns->Items[2]->Visible = true;
				bt_add->Visible = true;
				bt_del->Visible = true;
				bt_edit->Visible = true;
				}
			else ShowMessage("Пароль администратора неверный");
		}
		else {
			bt_admin->Caption = "Войти как администратор";
			form_main->Width -= 140;
			edit_pas->Left -= 140;
			//edit_pas->Top -= 30;
			bt_admin->Left  -= 140;
			//bt_admin->Top -= 30;
			bt_enter->Left -= 140;
			//bt_enter->Top -= 30;
			text_pas->Left -= 140;
			StaticText2->Left -= 200;
			StaticTextCount->Left -= 200;
			//text_pas->Top -= 30;
			DBGrid1->Width = 202;
			DBGrid1->Columns->Items[2]->Visible = false;
			bt_add->Visible = false;
			bt_del->Visible = false;
			bt_edit->Visible = false;
		}
}
//---------------------------------------------------------------------------


void __fastcall Tform_main::edit_pasKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN)
	bt_enter->Click();
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::bt_addClick(TObject *Sender)
{
	form_add->ShowModal();
	//ADOTable1->Fields->Fields[0]->AsString
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::bt_delClick(TObject *Sender)
{
	ADOTable1->Delete();
	StaticTextCount->Caption = ADOTable1->RecordCount;
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::DBGrid1TitleClick(TColumn *Column)
{
	ADOTable1->IndexFieldNames = Column->FieldName;
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::bt_editClick(TObject *Sender)
{
	bt_edit->Flat = !bt_edit->Flat;
	if (bt_edit->Flat) {
	DBGrid1->Options >> dgRowSelect;
	DBGrid1->ReadOnly = false;
	DBGrid1->Options = TDBGridOptions(DBGrid1->Options) << dgEditing;
	}
	else {
	DBGrid1->Options << dgRowSelect;
	DBGrid1->ReadOnly = true;
	DBGrid1->Options = TDBGridOptions(DBGrid1->Options) >> dgEditing;
    }
}
//---------------------------------------------------------------------------




void __fastcall Tform_main::FormCreate(TObject *Sender)
{
	StaticTextCount->Caption = ADOTable1->RecordCount;
}
//---------------------------------------------------------------------------


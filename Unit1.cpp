//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_main *form_main;
//---------------------------------------------------------------------------
__fastcall Tform_main::Tform_main(TComponent* Owner)
	: TForm(Owner)
{
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
			Form2->Show();
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
			Form3->Show(); //unable to open file
			exit(1);
		}

		free(pRGBData);
		QRcode_free(pQRC);
	}
	else
	{
		Form4->Show();// NULL returned
		exit(1);
	}

}
//---------------------------------------------------------------------------

void __fastcall Tform_main::DBGrid1CellClick(TColumn *Column)
{
	//Узнать номер строки *код снизу*
	//ShowMessage(DBGrid1->DataSource->DataSet->RecNo);
	/*ADOTable1->Edit;
	ADOTable1->FieldByName('Текущее кол-во книг')->Value:=ADOTable1.FieldByName('Текущее кол-во книг').Value;
	ADOTable1->Post;  */
	ADOTable1->Edit();
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::bt_enterClick(TObject *Sender)
{
	//    Показывает значение столбца "код" выделенной строки
	//ShowMessage(ADOTable1->Fields->Fields[0]->AsString);
	if (WorkPass->Text == ADOTable1->Fields->Fields[2]->AsString) {
			Form2->Show();
	}
	else ShowMessage("Пароль неверный");
}
//---------------------------------------------------------------------------


void __fastcall Tform_main::Button2Click(TObject *Sender)
{
	DBGrid1->Width = 342;
	DBGrid1->Columns->Items[2]->Width = 139;
	DBGrid1->Columns->Items[2]->Visible = true;
	bt_add->Visible = true;
	bt_del->Visible = true;
    bt_edit->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall Tform_main::WorkPassKeyPress(TObject *Sender, System::WideChar &Key)
{
    if (Key == VK_RETURN)
	bt_enter->Click();
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::bt_addClick(TObject *Sender)
{
	form_add->Show();
	//ADOTable1->Fields->Fields[0]->AsString
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::bt_delClick(TObject *Sender)
{
	ADOTable1->Delete();
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::DBGrid1TitleClick(TColumn *Column)
{
	ADOTable1->IndexFieldNames = Column->FieldName;
}
//---------------------------------------------------------------------------

void __fastcall Tform_main::bt_editClick(TObject *Sender)
{
    DBGrid1->ReadOnly = false;
	DBGrid1->Options = TDBGridOptions(DBGrid1->Options) << dgEditing;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_storage_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_storage *form_storage;
//---------------------------------------------------------------------------
//bool flag_storage_edit = 0;

std::string cp1251_to_utf8(const char *str){
	std::string res;
    int result_u, result_c;
	result_u = MultiByteToWideChar(1251, 0, str, -1, 0, 0);
    if(!result_u ){return 0;}
    wchar_t *ures = new wchar_t[result_u];
    if(!MultiByteToWideChar(1251, 0, str, -1, ures, result_u)){
        delete[] ures;
        return 0;
    }
    result_c = WideCharToMultiByte(65001, 0, ures, -1, 0, 0, 0, 0);
    if(!result_c){
        delete [] ures;
        return 0;
    }
    char *cres = new char[result_c];
    if(!WideCharToMultiByte(65001, 0, ures, -1, cres, result_c, 0, 0)){
        delete[] cres;
        return 0;
    }
    delete[] ures;
    res.append(cres);
    delete[] cres;
    return res;
}

bool is_valid_utf8(const char * string){
    if(!string){return true;}
	const unsigned char * bytes = (const unsigned char *)string;
    unsigned int cp;
    int num;
    while(*bytes != 0x00){
        if((*bytes & 0x80) == 0x00){
            // U+0000 to U+007F
            cp = (*bytes & 0x7F);
            num = 1;
        }
        else if((*bytes & 0xE0) == 0xC0){
            // U+0080 to U+07FF
            cp = (*bytes & 0x1F);
            num = 2;
        }
        else if((*bytes & 0xF0) == 0xE0){
            // U+0800 to U+FFFF
            cp = (*bytes & 0x0F);
            num = 3;
        }
        else if((*bytes & 0xF8) == 0xF0){
            // U+10000 to U+10FFFF
            cp = (*bytes & 0x07);
            num = 4;
        }
        else{return false;}
        bytes += 1;
        for(int i = 1; i < num; ++i){
            if((*bytes & 0xC0) != 0x80){return false;}
            cp = (cp << 6) | (*bytes & 0x3F);
            bytes += 1;
        }
        if( (cp > 0x10FFFF) ||
            ((cp <= 0x007F) && (num != 1)) ||
            ((cp >= 0xD800) && (cp <= 0xDFFF)) ||
            ((cp >= 0x0080) && (cp <= 0x07FF)  && (num != 2)) ||
            ((cp >= 0x0800) && (cp <= 0xFFFF)  && (num != 3)) ||
            ((cp >= 0x10000)&& (cp <= 0x1FFFFF)&& (num != 4)) ){return false;}
    }
    return true;
}


//---------------------------------------------------------------------------
__fastcall Tform_storage::Tform_storage(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tform_storage::bt_storage_delClick(TObject *Sender)
{
	if (DBGridStorage->Visible) ADOTableStorage->Delete();
	else ADOTableSold->Delete();
}
//---------------------------------------------------------------------------
void __fastcall Tform_storage::bt_editClick(TObject *Sender)
{
	bt_edit->Flat = !bt_edit->Flat;
	if (DBGridStorage->Visible) {
		if (bt_edit->Flat) {
		DBGridStorage->Options >> dgRowSelect;
		DBGridStorage->ReadOnly = false;
		DBGridStorage->Options = TDBGridOptions(DBGridStorage->Options) << dgEditing;
		}
		else {
		DBGridStorage->Options << dgRowSelect;
		DBGridStorage->ReadOnly = true;
		DBGridStorage->Options = TDBGridOptions(DBGridStorage->Options) >> dgEditing;
		}
	}
	else {
        if (bt_edit->Flat) {
		DBGridSold->Options >> dgRowSelect;
		DBGridSold->ReadOnly = false;
		DBGridSold->Options = TDBGridOptions(DBGridSold->Options) << dgEditing;
		}
		else {
		DBGridSold->Options << dgRowSelect;
		DBGridSold->ReadOnly = true;
		DBGridSold->Options = TDBGridOptions(DBGridSold->Options) >> dgEditing;
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall Tform_storage::bt_storage_addClick(TObject *Sender)
{
        form_add_storage->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tform_storage::DBGridStorageTitleClick(TColumn *Column)
{
	ADOTableStorage->IndexFieldNames = Column->FieldName;
}
//---------------------------------------------------------------------------
void __fastcall Tform_storage::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (form_main->Visible == false) form_main->Close();
}
//---------------------------------------------------------------------------
void __fastcall Tform_storage::bt_storage_backClick(TObject *Sender)
{
	if (DBGridStorage->Visible == false) {
		form_storage->DBGridSold->Visible = false;
		form_storage->DBGridStorage->Visible = true;
	}
	form_main->Visible = true;
	form_add_storage->text_add_storage_date2->Visible = false;
	form_add_storage->edit_add_storage_date2->Visible = false;
	form_storage->ADOTableSold->Active = False;
	form_storage->ADOTableSold->Active = True;
	form_storage->Close();
}
//---------------------------------------------------------------------------
void __fastcall Tform_storage::bt_qrClick(TObject *Sender)
{
	if (form_storage->DBGridStorage->Visible) {
		// Количество итераций на каждый файл QR + номер в партии
		for (auto i = 1; i < form_storage->ADOTableStorage->Fields->Fields[6]->AsLargeInt + 1; ++i) {
			AnsiString qr_data = form_storage->ADOTableStorage->Fields->Fields[0]->AsAnsiString + " "
											+ form_storage->ADOTableStorage->Fields->Fields[1]->AsAnsiString + " "
											+ form_storage->ADOTableStorage->Fields->Fields[2]->AsAnsiString + " "
											+ form_storage->ADOTableStorage->Fields->Fields[3]->AsAnsiString + " "
											+ form_storage->ADOTableStorage->Fields->Fields[4]->AsAnsiString + " "
											+ form_storage->ADOTableStorage->Fields->Fields[5]->AsAnsiString + " "
											+ form_storage->ADOTableStorage->Fields->Fields[6]->AsAnsiString + " "
											+ IntToStr(i); //qr_data - информация, кодируемая в код
			const char*	   szSourceString = qr_data.c_str();
			const char* decoded = cp1251_to_utf8(szSourceString).c_str();

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
			if ((pQRC = QRcode_encodeString(decoded, 0, QR_ECLEVEL_M, QR_MODE_8, 1)))
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

				AnsiString path2 = ".\\QR";
				const char* path2c = path2.c_str();
				mkdir(path2c);

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

				AnsiString bmp_path = ".\\QR\\№"
								+ form_storage->ADOTableStorage->Fields->Fields[0]->AsAnsiString
								+ " (" + form_storage->ADOTableStorage->Fields->Fields[1]->AsAnsiString
								+ ")\\QR" + IntToStr(i) + ".bmp"; // Путь до самого файла бмп
				AnsiString path = ".\\QR\\№"
								+ form_storage->ADOTableStorage->Fields->Fields[0]->AsAnsiString
								+ " (" + form_storage->ADOTableStorage->Fields->Fields[1]->AsAnsiString
								+ ")"; // Путь до папке с хранением файлов бмп
				const char*	bmp_path_char = bmp_path.c_str();
				const char*	path_char = path.c_str();
				UnicodeString str = cp1251_to_utf8(bmp_path_char).c_str();
				WideString wtxt(path);
				mkdir(path_char);
				if (!(fopen_s(&f, bmp_path_char, "wb")))
				{
					fwrite(&kFileHeader, sizeof(BITMAPFILEHEADER), 1, f);
					fwrite(&kInfoHeader, sizeof(BITMAPINFOHEADER), 1, f);
					fwrite(pRGBData, sizeof(unsigned char), unDataBytes, f);

					fclose(f);
				}
				else
				{
					ShowMessage("unable to open file");
				}

				free(pRGBData);
				QRcode_free(pQRC);
			}
			else
			{
				ShowMessage("NULL returned");
			}
		}
	}
	else ShowMessage("Эта функция не работает в режиме администратора");
}
//---------------------------------------------------------------------------

void __fastcall Tform_storage::bt_graphicsClick(TObject *Sender)
{
	form_graphics->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tform_storage::bt_storage_sellClick(TObject *Sender)
{
	form_sell->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tform_storage::bt_adminClick(TObject *Sender)
{
	if (DBGridStorage->Visible) {
		form_admin->ShowModal();
	}
	else {
		form_storage->DBGridSold->Visible = False;
		form_storage->DBGridStorage->Visible = True;
		form_add_storage->text_add_storage_date2->Visible = False;
		form_add_storage->edit_add_storage_date2->Visible = False;
		ShowMessage("Вы вышли из режима администратора");
	}
}
//---------------------------------------------------------------------------



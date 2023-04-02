//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "form_sell_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_sell *form_sell;
//---------------------------------------------------------------------------
__fastcall Tform_sell::Tform_sell(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tform_sell::bt_sell_okClick(TObject *Sender)
{
	if (edit_sell->Text.ToInt() <= 0 ) {
		ShowMessage("Вы должны ввести положительное число");
	}
	else if (edit_sell->Text.ToInt() > form_storage->ADOTableStorage->Fields->Fields[6]->AsInteger) {
		ShowMessage("В базе нет столько единиц продукции");
	}
	else {

		if (form_storage->DBGridStorage->Visible) {

			bool flag = 1;
			form_storage->ADOTableStorage->Edit();
			form_storage->ADOTableStorage->Fields->Fields[6]->AsInteger -= edit_sell->Text.ToInt();
			form_storage->ADOTableStorage->Post();
			//                              Заполнение SOLD из STORAGE
			form_storage->ADOTableSold->IndexFieldNames = "№";
			TLocateOptions loCaseInsensitive;
			loCaseInsensitive.Clear();
			form_storage->ADOTableSold->Locate("№", form_storage->ADOTableStorage->Fields->Fields[0]->AsLargeInt, loCaseInsensitive);

			for (form_storage->ADOTableSold->RecNo; form_storage->ADOTableSold->Fields->Fields[0]->AsLargeInt == form_storage->ADOTableStorage->Fields->Fields[0]->AsLargeInt; form_storage->ADOTableSold->RecNo++)
			{
				if (form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString == form_storage->ADOTableStorage->Fields->Fields[1]->AsAnsiString
					&& form_storage->ADOTableSold->Fields->Fields[2]->AsAnsiString == form_storage->ADOTableStorage->Fields->Fields[2]->AsAnsiString
					&& form_storage->ADOTableSold->Fields->Fields[3]->AsAnsiString == form_storage->ADOTableStorage->Fields->Fields[3]->AsAnsiString
					&& form_storage->ADOTableSold->Fields->Fields[4]->AsDateTime == form_storage->ADOTableStorage->Fields->Fields[4]->AsDateTime
					&& form_storage->ADOTableSold->Fields->Fields[5]->AsFloat == form_storage->ADOTableStorage->Fields->Fields[5]->AsFloat
					&& form_storage->ADOTableSold->Fields->Fields[7]->AsDateTime == Date() )
				{
				form_storage->ADOTableSold->Edit();
				form_storage->ADOTableSold->Fields->Fields[6]->AsLargeInt += StrToInt64(edit_sell->Text);
				form_storage->ADOTableSold->Post();
				flag = !flag;
				break;
				}
			}
			if (flag) {
				form_storage->ADOTableSold->Last();
				form_storage->ADOTableSold->Insert();
				form_storage->ADOTableSold->Fields->Fields[0]->AsLargeInt = form_storage->ADOTableStorage->Fields->Fields[0]->AsLargeInt;
				form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString = form_storage->ADOTableStorage->Fields->Fields[1]->AsAnsiString;
				form_storage->ADOTableSold->Fields->Fields[2]->AsAnsiString = form_storage->ADOTableStorage->Fields->Fields[2]->AsAnsiString;
				form_storage->ADOTableSold->Fields->Fields[3]->AsAnsiString = form_storage->ADOTableStorage->Fields->Fields[3]->AsAnsiString;
				form_storage->ADOTableSold->Fields->Fields[4]->AsDateTime = form_storage->ADOTableStorage->Fields->Fields[4]->AsDateTime;
				form_storage->ADOTableSold->Fields->Fields[5]->AsFloat = form_storage->ADOTableStorage->Fields->Fields[5]->AsFloat;
				form_storage->ADOTableSold->Fields->Fields[6]->AsLargeInt = StrToInt64(edit_sell->Text);
				form_storage->ADOTableSold->Fields->Fields[7]->AsDateTime = Date();
				form_storage->ADOTableSold->Post();
				form_sell->Close();
				}
				//                                  GRID SOLD STRUCT
				/* sell_grid sell_grid_temp {form_storage->ADOTableStorage->Fields->Fields[0]->AsLargeInt,
										  form_storage->ADOTableStorage->Fields->Fields[1]->AsAnsiString,
										  form_storage->ADOTableStorage->Fields->Fields[2]->AsAnsiString,
										  form_storage->ADOTableStorage->Fields->Fields[3]->AsAnsiString,
										  form_storage->ADOTableStorage->Fields->Fields[4]->AsDateTime,
										  form_storage->ADOTableStorage->Fields->Fields[5]->AsLargeInt,
										  StrToFloat(edit_sell->Text),
										  Date()
				};
				*/
				form_sell->Close();
		}

		else {

			bool flag = 1;
			form_storage->ADOTableSold->Edit();
			form_storage->ADOTableSold->Fields->Fields[6]->AsInteger -= edit_sell->Text.ToInt();
			form_storage->ADOTableSold->Post();
			//                              Заполнение SOLD из STORAGE
			form_storage->ADOTableStorage->IndexFieldNames = "Наименование";
			TLocateOptions loCaseInsensitive;
			loCaseInsensitive.Clear();
			form_storage->ADOTableStorage->Locate("Наименование", form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString, loCaseInsensitive);

		for (form_storage->ADOTableStorage->RecNo; form_storage->ADOTableStorage->Fields->Fields[1]->AsAnsiString == form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString; form_storage->ADOTableStorage->RecNo++)
		{
			if (form_storage->ADOTableStorage->Fields->Fields[2]->AsAnsiString == form_storage->ADOTableSold->Fields->Fields[2]->AsAnsiString
				&& form_storage->ADOTableStorage->Fields->Fields[3]->AsAnsiString == form_storage->ADOTableSold->Fields->Fields[3]->AsAnsiString
				&& form_storage->ADOTableStorage->Fields->Fields[4]->AsDateTime == form_storage->ADOTableSold->Fields->Fields[4]->AsDateTime
				&& form_storage->ADOTableStorage->Fields->Fields[5]->AsFloat == form_storage->ADOTableSold->Fields->Fields[5]->AsFloat)
			{
			form_storage->ADOTableStorage->Edit();
			form_storage->ADOTableStorage->Fields->Fields[6]->AsLargeInt += StrToInt64(edit_sell->Text);
			form_storage->ADOTableStorage->Post();
			flag = !flag;
			break;
			}
		}
		if (flag) {
			form_storage->ADOTableStorage->Last();
			form_storage->ADOTableStorage->Insert();
			//form_storage->ADOTableStorage->Fields->Fields[0]->AsLargeInt = form_storage->ADOTableSold->Fields->Fields[0]->AsLargeInt;
			form_storage->ADOTableStorage->Fields->Fields[1]->AsAnsiString = form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString;
			form_storage->ADOTableStorage->Fields->Fields[2]->AsAnsiString = form_storage->ADOTableSold->Fields->Fields[2]->AsAnsiString;
			form_storage->ADOTableStorage->Fields->Fields[3]->AsAnsiString = form_storage->ADOTableSold->Fields->Fields[3]->AsAnsiString;
			form_storage->ADOTableStorage->Fields->Fields[4]->AsDateTime = form_storage->ADOTableSold->Fields->Fields[4]->AsDateTime;
			form_storage->ADOTableStorage->Fields->Fields[5]->AsFloat = form_storage->ADOTableSold->Fields->Fields[5]->AsFloat;
			form_storage->ADOTableStorage->Fields->Fields[6]->AsLargeInt = StrToInt64(edit_sell->Text);
			form_storage->ADOTableStorage->Post();
			form_sell->Close();
			}
			form_sell->Close();
        }
	}
}

void __fastcall Tform_sell::edit_sellKeyPress(TObject *Sender, System::WideChar &Key)

{
	if((Key!=VK_BACK)&&(Key<'0'||Key>'9'))Key=0;
}
//---------------------------------------------------------------------------


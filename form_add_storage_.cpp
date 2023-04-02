//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "form_add_storage_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_add_storage *form_add_storage;
//---------------------------------------------------------------------------
__fastcall Tform_add_storage::Tform_add_storage(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tform_add_storage::bt_ok_storageClick(TObject *Sender)
{
	if (edit_add_storage_name->Text == ""
			|| edit_add_storage_type->Text == ""
			|| edit_add_storage_condition->Text == ""
			|| edit_add_storage_date->Text == ""
			|| edit_add_storage_price->Text == ""
			|| edit_add_storage_count->Text == "")
			{
			ShowMessage("Все поля должны быть заполнены");
			}
    //                                                           ТУТ ИНТ, А НАДО ЛОНГ ИНТ   |||
	else if (StrToFloat(edit_add_storage_price->Text) <= 0 || edit_add_storage_count->Text.ToInt() <= 0)
			{
			ShowMessage("Числа должны быть неотрицательными");
			}
	else {
			if (form_storage->DBGridStorage->Visible) {
				std::vector<AnsiString> edit_mas = {edit_add_storage_name->Text, edit_add_storage_type->Text,
												edit_add_storage_condition->Text, edit_add_storage_date->Text,
												edit_add_storage_price->Text, edit_add_storage_count->Text};
				for (int i = 1; i < form_storage->ADOTableStorage->RecordCount+1; ++i) {
					int k = 0;
					form_storage->DBGridStorage->DataSource->DataSet->RecNo = i;
					for (int j = 1; j<6; ++j){
						if (edit_mas[j-1] != form_storage->ADOTableStorage->Fields->Fields[j]->AsAnsiString) break;
						k++;
					}
					if (k == 5) {
						form_storage->ADOTableStorage->Edit();
						form_storage->ADOTableStorage->Fields->Fields[6]->AsInteger += std::atoi(edit_mas[5].c_str());
						form_storage->ADOTableStorage->Post();
						ShowMessage("Было добавлено " + edit_mas[5] + " единиц(ы) продукции.");
						break;
					}
					else if (i == form_storage->ADOTableStorage->RecordCount) {
						form_storage->ADOTableStorage->Insert();
						form_storage->ADOTableStorage->FieldByName("Наименование")->Value = edit_add_storage_name->Text;
						form_storage->ADOTableStorage->FieldByName("Тип")->Value = edit_add_storage_type->Text;
						form_storage->ADOTableStorage->FieldByName("Состояние")->Value = edit_add_storage_condition->Text;
						form_storage->ADOTableStorage->FieldByName("Дата поступления")->Value = edit_add_storage_date->Text;
						form_storage->ADOTableStorage->FieldByName("Себестоимость (руб)")->Value = edit_add_storage_price->Text;
						form_storage->ADOTableStorage->FieldByName("Количество")->Value = edit_add_storage_count->Text;
						form_storage->ADOTableStorage->Post();
						form_add_storage->Close();
						break;
					}
				}
			}
			else{
				std::vector<AnsiString> edit_mas = {edit_add_storage_name->Text, edit_add_storage_type->Text,
													edit_add_storage_condition->Text, edit_add_storage_date->Text,
													edit_add_storage_price->Text, edit_add_storage_count->Text,
													edit_add_storage_date2->Text};
				for (int i = 1; i < form_storage->ADOTableSold->RecordCount+1; ++i) {
					int k = 0;
					form_storage->DBGridSold->DataSource->DataSet->RecNo = i;
					for (int j = 1; j<8; ++j){
						if (j != 6 && edit_mas[j-1] != form_storage->ADOTableSold->Fields->Fields[j]->AsAnsiString) break;
						k++;
					}
					if (k == 7) {
						form_storage->ADOTableSold->Edit();
						form_storage->ADOTableSold->Fields->Fields[6]->AsInteger += std::atoi(edit_mas[5].c_str());
						form_storage->ADOTableSold->Post();
						ShowMessage("Было добавлено " + edit_mas[5] + " единиц(ы) продукции.");
						break;
					}
					else if (i == form_storage->ADOTableSold->RecordCount) {
						form_storage->ADOTableSold->Insert();
						form_storage->ADOTableSold->FieldByName("Наименование")->Value = edit_add_storage_name->Text;
						form_storage->ADOTableSold->FieldByName("Тип")->Value = edit_add_storage_type->Text;
						form_storage->ADOTableSold->FieldByName("Состояние")->Value = edit_add_storage_condition->Text;
						form_storage->ADOTableSold->FieldByName("Дата поступления")->Value = edit_add_storage_date->Text;
						form_storage->ADOTableSold->FieldByName("Себестоимость (руб)")->Value = edit_add_storage_price->Text;
						form_storage->ADOTableSold->FieldByName("Количество")->Value = edit_add_storage_count->Text;
						form_storage->ADOTableSold->FieldByName("Дата отгрузки")->Value = edit_add_storage_date2->Text;
						form_storage->ADOTableSold->Post();
						form_add_storage->Close();
						break;
					}
				}
			}
		form_storage->ADOTableSold->Active = False;
		form_storage->ADOTableSold->Active = True;
		}
}
//---------------------------------------------------------------------------

void __fastcall Tform_add_storage::bt_cancel_storageClick(TObject *Sender)
{
	form_add_storage->Close();
}
//---------------------------------------------------------------------------


void __fastcall Tform_add_storage::edit_add_storage_dateKeyPress(TObject *Sender,
		  System::WideChar &Key)
{
	if((Key != VK_BACK)&&(Key != '.')&&(Key<'0'|| Key>'9') )Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall Tform_add_storage::edit_add_storage_priceKeyPress(TObject *Sender,
          System::WideChar &Key)
{
	if( (Key != VK_BACK)&&(Key != ',')&&(Key<'0'|| Key>'9') )Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall Tform_add_storage::edit_add_storage_countKeyPress(TObject *Sender,
          System::WideChar &Key)
{
	if((Key != VK_BACK)&&(Key<'0'|| Key>'9'))Key = 0;
}
//---------------------------------------------------------------------------


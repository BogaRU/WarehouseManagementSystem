//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_admin_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_admin *form_admin;
//---------------------------------------------------------------------------
__fastcall Tform_admin::Tform_admin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tform_admin::bt_adminClick(TObject *Sender)
{
	if (edit_admin->Text == "useR") {
			form_storage->DBGridSold->Visible = true;
			form_storage->DBGridStorage->Visible = false;
			form_add_storage->text_add_storage_date2->Visible = true;
			form_add_storage->edit_add_storage_date2->Visible = true;
			form_storage->ADOTableSold->Active = False;
			form_storage->ADOTableSold->Active = True;
			form_admin->Close();
	}
	else ShowMessage("Пароль администратора неверный");
}
//---------------------------------------------------------------------------
void __fastcall Tform_admin::edit_adminKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == VK_RETURN)
	bt_admin->Click();
}
//---------------------------------------------------------------------------


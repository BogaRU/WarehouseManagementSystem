//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_add_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_add *form_add;
//---------------------------------------------------------------------------
__fastcall Tform_add::Tform_add(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tform_add::bt_add_okClick(TObject *Sender)
{
		if (edit_add_name->Text == ""
			|| edit_add_pas->Text == ""
			|| edit_add_repeat->Text == ""){
			ShowMessage("Все поля должны быть заполнены");
			}
		else if (edit_add_pas->Text == edit_add_repeat->Text) {
			form_main->ADOTable1->Insert();
			form_main->ADOTable1->FieldByName("ФИО")->Value = edit_add_name->Text;
			form_main->ADOTable1->FieldByName("Код")->Value = edit_add_pas->Text;
			form_main->ADOTable1->Post();
			edit_add_name->Text = "";
			edit_add_pas->Text = "";
			edit_add_repeat->Text = "";
			form_main->StaticTextCount->Caption = form_main->ADOTable1->RecordCount;
			form_add->Close();
			}
		else ShowMessage("Пароли не совпадают");
}
//---------------------------------------------------------------------------
void __fastcall Tform_add::bt_add_cancelClick(TObject *Sender)
{
	form_add->Close();
}
//---------------------------------------------------------------------------
void __fastcall Tform_add::edit_add_nameKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == VK_RETURN)
	bt_add_ok->Click();
}
//---------------------------------------------------------------------------

void __fastcall Tform_add::edit_add_pasKeyPress(TObject *Sender, System::WideChar &Key)

{
    if (Key == VK_RETURN)
	bt_add_ok->Click();
}
//---------------------------------------------------------------------------

void __fastcall Tform_add::edit_add_repeatKeyPress(TObject *Sender, System::WideChar &Key)

{
    if (Key == VK_RETURN)
	bt_add_ok->Click();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#ifndef form_admin_H
#define form_admin_H
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
#include "form_storage_.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class Tform_admin : public TForm
{
__published:	// IDE-managed Components
	TEdit *edit_admin;
	TButton *bt_admin;
	TStaticText *StaticText1;
	void __fastcall bt_adminClick(TObject *Sender);
	void __fastcall edit_adminKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_admin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_admin *form_admin;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef form_add_H
#define form_add_H
#include "form_main_.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class Tform_add : public TForm
{
__published:	// IDE-managed Components
	TEdit *edit_add_name;
	TEdit *edit_add_pas;
	TEdit *edit_add_repeat;
	TButton *bt_add_ok;
	TButton *bt_add_cancel;
	TStaticText *text_add_name;
	TStaticText *text_add_pas;
	TStaticText *text_add_repeat;
	void __fastcall bt_add_okClick(TObject *Sender);
	void __fastcall bt_add_cancelClick(TObject *Sender);
	void __fastcall edit_add_nameKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall edit_add_pasKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall edit_add_repeatKeyPress(TObject *Sender, System::WideChar &Key);

private:	// User declarations
public:		// User declarations
	__fastcall Tform_add(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_add *form_add;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef form_sell_H
#define form_sell_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "form_storage_.h"
//---------------------------------------------------------------------------
class Tform_sell : public TForm
{
__published:	// IDE-managed Components
	TEdit *edit_sell;
	TUpDown *UpDown1;
	TButton *bt_sell_ok;
	void __fastcall bt_sell_okClick(TObject *Sender);
	void __fastcall edit_sellKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_sell(TComponent* Owner);
};
//---------------------------------------------------------------------------
/*              SOLD STRUCT
struct sell_grid {
	long long int N;
	AnsiString name;
	AnsiString type;
	AnsiString condition;
	TDate date;
	long long int count;
	long double price;
	TDate date_sell;
};
*/
//---------------------------------------------------------------------------
extern PACKAGE Tform_sell *form_sell;
//---------------------------------------------------------------------------
#endif

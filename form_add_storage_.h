//---------------------------------------------------------------------------

#ifndef form_add_storage_H
#define form_add_storage_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <cstdlib>
#include <vector>
#include "form_storage_.h"
//---------------------------------------------------------------------------
class Tform_add_storage : public TForm
{
__published:	// IDE-managed Components
	TEdit *edit_add_storage_name;
	TEdit *edit_add_storage_type;
	TEdit *edit_add_storage_condition;
	TEdit *edit_add_storage_date;
	TEdit *edit_add_storage_count;
	TEdit *edit_add_storage_price;
	TStaticText *text_add_storage_name;
	TStaticText *text_add_storage_type;
	TStaticText *text_add_storage_condition;
	TStaticText *text_add_storage_date;
	TStaticText *text_add_storage_price;
	TStaticText *text_add_storage_count;
	TButton *bt_ok_storage;
	TButton *bt_cancel_storage;
	TEdit *edit_add_storage_date2;
	TStaticText *text_add_storage_date2;
	void __fastcall bt_ok_storageClick(TObject *Sender);
	void __fastcall bt_cancel_storageClick(TObject *Sender);
	void __fastcall edit_add_storage_dateKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall edit_add_storage_priceKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall edit_add_storage_countKeyPress(TObject *Sender, System::WideChar &Key);



private:	// User declarations
public:		// User declarations
	__fastcall Tform_add_storage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_add_storage *form_add_storage;
//---------------------------------------------------------------------------
#endif

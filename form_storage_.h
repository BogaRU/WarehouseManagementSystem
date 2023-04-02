//---------------------------------------------------------------------------

#ifndef form_storage_H
#define form_storage_H
//---------------------------------------------------------------------------
#include "form_add_.h"
#include "form_admin_.h"
#include "form_main_.h"
#include "form_graphics_.h"
#include "form_add_storage_.h"
#include "form_sell_.h"
#include <dir.h>
#include <dirent.h>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.StdCtrls.hpp>
#include <string>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <windows.h>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class Tform_storage : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGridStorage;
	TADOConnection *ADOConnectionStorage;
	TADOTable *ADOTableStorage;
	TDataSource *DataSourceStorage;
	TSpeedButton *bt_storage_add;
	TSpeedButton *bt_storage_del;
	TSpeedButton *bt_edit;
	TSpeedButton *bt_storage_back;
	TSpeedButton *bt_qr;
	TSpeedButton *bt_graphics;
	TSpeedButton *bt_storage_sell;
	TADOConnection *ADOConnectionSold;
	TADOTable *ADOTableSold;
	TSpeedButton *bt_admin;
	TDBGrid *DBGridSold;
	TDataSource *DataSourceSold;
	TAutoIncField *ADOTableStorageAutoIncField;
	TWideStringField *ADOTableStorageÍàèìåíîâàíèå;
	TWideStringField *ADOTableStorageÒèï;
	TWideStringField *ADOTableStorageÑîñòîÿíèå;
	TDateTimeField *ADOTableStorageÄàòàïîñòóïëåíèÿ;
	TFloatField *ADOTableStorageÑåáåñòîèìîñòüğóá;
	TIntegerField *ADOTableStorageÊîëè÷åñòâî;
	void __fastcall bt_storage_delClick(TObject *Sender);
	void __fastcall bt_editClick(TObject *Sender);
	void __fastcall bt_storage_addClick(TObject *Sender);
	void __fastcall DBGridStorageTitleClick(TColumn *Column);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall bt_storage_backClick(TObject *Sender);
	void __fastcall bt_qrClick(TObject *Sender);
	void __fastcall bt_graphicsClick(TObject *Sender);
	void __fastcall bt_storage_sellClick(TObject *Sender);
	void __fastcall bt_adminClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_storage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_storage *form_storage;
//---------------------------------------------------------------------------
#endif

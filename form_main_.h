//---------------------------------------------------------------------------
#ifndef form_main_H
#define form_main_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "form_add_.h"
#include "form_storage_.h"
#include <windows.h>
#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "ComObj.hpp"
#include "System.hpp"
#include "qrencode.h"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#define QRCODE_TEXT			"Metal 25 kg"
#define OUT_FILE			"A:/Cpp/BuilderProjects/Новая папка/2/QR.bmp"
#define OUT_FILE_PIXEL_PRESCALER	16 // Number of pixels in bmp file for each QRCode pixel, on each dimension

#define PIXEL_COLOR_R			0
#define PIXEL_COLOR_G			0
#define PIXEL_COLOR_B			0000

typedef unsigned short	WORD;
typedef unsigned long	DWORD;
typedef signed long	LONG;

#define BI_RGB				0L

#pragma pack(push, 2)



#pragma pack(pop)
//---------------------------------------------------------------------------
class Tform_main : public TForm
{
__published:	// IDE-managed Components
	TButton *bt_admin;
	TButton *bt_enter;
	TDBGrid *DBGrid1;
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TADOTable *ADOTable1;
	TEdit *edit_pas;
	TWideStringField *ADOTable1ФИО;
	TWideStringField *ADOTable1Код;
	TSpeedButton *bt_del;
	TSpeedButton *bt_add;
	TStaticText *text_pas;
	TSpeedButton *bt_edit;
	TAutoIncField *ADOTable1AutoIncField;
	TStaticText *StaticText2;
	TStaticText *StaticTextCount;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall bt_enterClick(TObject *Sender);
	void __fastcall bt_adminClick(TObject *Sender);
	void __fastcall edit_pasKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall bt_addClick(TObject *Sender);
	void __fastcall bt_delClick(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall bt_editClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_main(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_main *form_main;
//---------------------------------------------------------------------------
#endif

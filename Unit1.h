//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "form_add_.h"
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
#include "qrencode.h"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#define QRCODE_TEXT			"Hello, world!"
#define OUT_FILE			"D:/Kurs/QR.bmp"
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
	TButton *Button1;
	TButton *Button2;
	TButton *bt_enter;
	TDBGrid *DBGrid1;
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TADOTable *ADOTable1;
	TEdit *WorkPass;
	TAutoIncField *ADOTable1Номер;
	TWideStringField *ADOTable1ФИО;
	TWideStringField *ADOTable1Код;
	TSpeedButton *bt_del;
	TSpeedButton *bt_add;
	TStaticText *StaticText1;
	TSpeedButton *bt_edit;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall bt_enterClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall WorkPassKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall bt_addClick(TObject *Sender);
	void __fastcall bt_delClick(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall bt_editClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_main(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_main *form_main;
//---------------------------------------------------------------------------
#endif

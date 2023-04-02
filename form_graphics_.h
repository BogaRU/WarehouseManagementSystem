//---------------------------------------------------------------------------

#ifndef form_graphics_H
#define form_graphics_H
//---------------------------------------------------------------------------
#include "form_storage_.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeeData.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <map>
//---------------------------------------------------------------------------
class Tform_graphics : public TForm
{
__published:	// IDE-managed Components
	TChart *ChartGraphics;
	TChartDataSet *ChartDataSet1;
	TListBox *ListBoxGraphics;
	TButton *bt_graphics;
	TComboBox *ComboBoxGraphics;
	TButton *bt_sold_graphics;
	TChart *ChartSoldGraphics;
	TBarSeries *Series2;
	TBarSeries *Series1;
	void __fastcall ListBoxGraphicsClick(TObject *Sender);
	void __fastcall bt_graphicsClick(TObject *Sender);
	void __fastcall bt_sold_graphicsClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_graphics(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_graphics *form_graphics;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_graphics_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_graphics *form_graphics;


std::multimap<AnsiString, std::pair<float, TDateTime> > sold_map;
//---------------------------------------------------------------------------
__fastcall Tform_graphics::Tform_graphics(TComponent* Owner)
	: TForm(Owner)
{
	TDateTime temp_date = 30/12/1899;
	long int temp_N = 0;
	float temp_price = 0;
//-----------------------------------
	form_storage->ADOTableSold->IndexFieldNames = "¹";
	form_storage->ADOTableSold->First();
	for (long int i = 0; i < form_storage->ADOTableSold->RecordCount; ++i, form_storage->ADOTableSold->Next() ) {
		ListBoxGraphics->Items->Add(form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString);
		if (i && form_storage->ADOTableSold->Fields->Fields[0]->AsLargeInt == temp_N) {
			ListBoxGraphics->Items->Delete(i);
			if (form_storage->ADOTableSold->Fields->Fields[7]->AsDateTime == temp_date)
			{
			temp_price = sold_map.find(form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString)->second.first;
			sold_map.erase(sold_map.find(form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString) ) ;
			sold_map.insert(std::pair < AnsiString, std::pair < float, TDateTime > > (form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString, {form_storage->ADOTableSold->Fields->Fields[5]->AsFloat * form_storage->ADOTableSold->Fields->Fields[6]->AsFloat + temp_price, form_storage->ADOTableSold->Fields->Fields[7]->AsDateTime}) );
			}
		}
		temp_date = form_storage->ADOTableSold->Fields->Fields[7]->AsDateTime;
		temp_N = form_storage->ADOTableSold->Fields->Fields[0]->AsLargeInt;
		sold_map.insert(std::pair < AnsiString, std::pair < float, TDateTime > > (form_storage->ADOTableSold->Fields->Fields[1]->AsAnsiString, {form_storage->ADOTableSold->Fields->Fields[5]->AsFloat * form_storage->ADOTableSold->Fields->Fields[6]->AsFloat, form_storage->ADOTableSold->Fields->Fields[7]->AsDateTime}) );
	}

	for (auto i = 0; i < ListBoxGraphics->Count; ++i) {
		if ( i && ListBoxGraphics->Items->Strings[i] == ListBoxGraphics->Items->Strings[i-1]) {
		ListBoxGraphics->Items->Delete(i-1);
		i = 0;
		}
	}

}
//---------------------------------------------------------------------------


void __fastcall Tform_graphics::ListBoxGraphicsClick(TObject *Sender)
{
	/*	for (auto it = sold_map.begin(); it != sold_map.end(); ++it){
	ShowMessage(it->first);
	ShowMessage(it->second.first);
	ShowMessage(it->second.second);
	} 
	if(!(ListBoxGraphics->ItemIndex == -1)){

			while (sold_map.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex)) != sold_map.end()){
				Series1->Add(sold_map.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex))->second.first, sold_map.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex))->second.second);
				//ShowMessage(sold_map.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex))->second.second);
				sold_map.erase(sold_map.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex)));
			}
		}
	*/
}
//---------------------------------------------------------------------------

void __fastcall Tform_graphics::bt_graphicsClick(TObject *Sender)
{
	//ChartGraphics->RemoveAllSeries(); 
	//ChartGraphics->SeriesList->Clear();
	Series1->Clear();
	if(!(ListBoxGraphics->ItemIndex == -1)){
			std::multimap <AnsiString, std::pair <float, TDateTime> > sold_map2(sold_map);
			while (sold_map2.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex)) != sold_map2.end() ){
				Series1->Add(sold_map2.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex))->second.first,
				sold_map2.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex))->second.second);
				//ShowMessage(sold_map.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex))->second.second);
				sold_map2.erase(sold_map2.find(ListBoxGraphics->Items->operator [](ListBoxGraphics->ItemIndex)));
			}
		}	
}
//---------------------------------------------------------------------------


void __fastcall Tform_graphics::bt_sold_graphicsClick(TObject *Sender)
{
	Series2->Clear();
	double period;

	switch (ComboBoxGraphics->ItemIndex) {
	case 0: {
	  period = 7;
	  break;
	}
	case 1: {
	  period = 14;
	  break;
    }
	case 2: {
	  period = 30.4375;
	  break;
	}
	case 3: {
	  period = 91.3125;
	  break;
	}
	case 4: {
	  period = 182.625;
	  break;
	}
	case 5: {
	  period = 365.25;
	  break;
	}
	case 6: {
	  period = 730.5;
	  break;
	}
	case 7: {
	  period = 1095.75;
	  break;
	}
	case 8: {
	  period = 1461;
	  break;
	}
	case 9: {
	  period = 1826.25;
	  break;
	}
	case 10: {
	  period = 3652.5;
	  break;
	}
  }

  std::multimap <AnsiString, std::pair <float, TDateTime> > sold_map2(sold_map);
		for (auto it = sold_map2.begin(); it != sold_map.end(); it = sold_map2.begin()) {
			if (it->second.second >= (Date() - period) && it->second.second <= Date() ) {
				float temp = 0;
				AnsiString temp_name = it->first;
				while (sold_map2.find(temp_name) != sold_map2.end()){
					//Series2->Add(sold_map2.find(it->first)->second.first, sold_map2.find(it->first)->second.second);
					temp += sold_map2.find(temp_name)->second.first;
					temp_name = sold_map2.find(temp_name)->first;
					sold_map2.erase(sold_map2.find(temp_name));
				}
				Series2->Add(temp, temp_name);
				//sold_map2.erase(sold_map2.find(it->first));
			}
			else if (sold_map2.empty()) break;
			else sold_map2.erase(it);
		}


		Series2->XValues->Order = loNone;
		Series2->YValues->Order = loDescending;
		Series2->YValues->Sort();
		Series2->XValues->FillSequence();
		Series2->Repaint();
}
//---------------------------------------------------------------------------


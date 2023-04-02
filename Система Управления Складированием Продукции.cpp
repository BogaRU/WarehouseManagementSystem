//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("form_storage_.cpp", form_storage);
USEFORM("form_sell_.cpp", form_sell);
USEFORM("form_add_.cpp", form_add);
USEFORM("form_add_storage_.cpp", form_add_storage);
USEFORM("form_admin_.cpp", form_admin);
USEFORM("form_graphics_.cpp", form_graphics);
USEFORM("form_main_.cpp", form_main);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(Tform_main), &form_main);
		Application->CreateForm(__classid(Tform_add), &form_add);
		Application->CreateForm(__classid(Tform_storage), &form_storage);
		Application->CreateForm(__classid(Tform_add_storage), &form_add_storage);
		Application->CreateForm(__classid(Tform_graphics), &form_graphics);
		Application->CreateForm(__classid(Tform_sell), &form_sell);
		Application->CreateForm(__classid(Tform_admin), &form_admin);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

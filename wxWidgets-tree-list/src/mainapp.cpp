#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

// Replace
const char *author = wxNT("John J. Hanley");
const char *appTitle = wxNT("Example Application");

//************************************************************
// Global handle to the wxFrame
//************************************************************

MyFrame	*g_frame = NULL;

//************************************************************
// Give wxWidgets the means to create a MyApp object
//************************************************************

wxIMPLEMENT_APP(MyApp);

//************************************************************
// Initialize the application
//************************************************************

bool MyApp::OnInit()
{
	SetVendorName(author);
	SetAppName(appTitle);

	m_locale = wxLocale(wxLANGUAGE_DEFAULT);

	// This is for future internationalization
	// Catalogs is the path to where the translation app.mo files are located.
	// [absolute path]/Catalogs
	// For example, under Catalogs/ja_JP is is the Japanese translation file app.mo.
	// The catalog files are included in the application installer.
	// For exmaple on Windows:
	// - C:/Program Files/My App/
	// -- main.exe
	// -- Catalogs/
	// -- Catalogs/es_ES/app.mo	(Spanish translation)
	// -- Catalogs/ja_JP/app.mo	(Japanese translation)

#if defined(SAVE)
	wxString catalogs = "/path/to/Catalogs";	// Directory path
	m_locale->AddCatalogPrefixPath(catalogs);
	m_locale->AddCatalog(wxNT("app"));		// Loads Catalogs/ja_JP/app.mo
#endif

	new MyFrame( wxT("Hello World"), wxPoint(50, 50), wxSize(450, 340) );

	g_frame->Show( true );

	return true;
}

//************************************************************
// Handle application shutdown and exit
//************************************************************

int
MyApp::OnExit(void)
{
	return 0;
}

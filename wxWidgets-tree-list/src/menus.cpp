#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

int
MyFrame::SetupMenus(void)
{
wxMenu *menuFile;

	menuFile = new wxMenu;

	menuFile->Append(
		ID_Hello,
		"&Hello...\tCtrl-H",
		wxT("Help string shown in status bar for this menu item"));

	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append( menuFile, wxT("&File") );
	menuBar->Append( menuHelp, wxT("&Help") );
	SetMenuBar( menuBar );

	return 0;
}

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

#if defined(__LINUX__)
#define	DEFINE_APP_512_XPM
#include "app_512.xpm"
#endif

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_Hello,	MyFrame::OnHello)
	EVT_MENU(wxID_EXIT,	MyFrame::OnExit)
	EVT_MENU(wxID_ABOUT,	MyFrame::OnAbout)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	SetProgramIcon();

	wxMenu *menuFile = new wxMenu;

	menuFile->Append(
		ID_Hello,
		"&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");

	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append( menuFile, "&File" );
	menuBar->Append( menuHelp, "&Help" );
	SetMenuBar( menuBar );

	CreateStatusBar();
	SetStatusText( "Welcome to wxWidgets!" );
}

#if defined(_WIN32)
void MyFrame::SetProgramIcon()
{
	this->SetIcon(wxIcon("IDI_ICON1"));
}
#elif defined(__APPLE__)
void MyFrame::SetProgramIcon()
{
	// Program icon is not handled here
	// Look at CMakeLists.txt and macos/Info.plist
}
#elif defined(__LINUX__)
void MyFrame::SetProgramIcon()
{
wxBitmap	bmp(app_512_xpm);
wxIcon		icon;

	icon.CopyFromBitmap(bmp);
	this->SetIcon(icon);
}
#else
void MyFrame::SetProgramIcon()
{
}
#endif

void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(
		"This is a wxWidgets' Hello world sample",
		"About Hello World",
		wxOK | wxICON_INFORMATION,
		this);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

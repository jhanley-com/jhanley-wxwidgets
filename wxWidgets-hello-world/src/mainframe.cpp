#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_Hello,	MyFrame::OnHello)
	EVT_MENU(wxID_EXIT,	MyFrame::OnExit)
	EVT_MENU(wxID_ABOUT,	MyFrame::OnAbout)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
wxIcon		icon("IDI_ICON1");

	this->SetIcon(icon);

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

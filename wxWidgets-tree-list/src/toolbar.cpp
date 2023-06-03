#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

int
MyFrame::SetupToolbar(bool force)
{
int		style;
wxToolBar	*oldToolBar;
#if defined(_WIN32)
wxBitmap	bmp_about(wxNT("IDI_ICON1"), wxBITMAP_TYPE_ICO_RESOURCE);
wxBitmap	bmp_refresh(wxNT("IDI_REFRESH"));
#elif defined(__LINUX__)
wxBitmap	bmp_about(app_512_xpm);
wxBitmap	bmp_refresh(refresh_xpm);
#elif defined(__APPLE__)
// FIX - These images should go into the macos/app.icns file
// I am using this to demonstrate XPM icons on Apple
// See how I am using the Apple method in src/mainframe.cpp
wxBitmap	bmp_about(app_512_xpm);
wxBitmap	bmp_refresh(refresh_xpm);
#endif


	style = wxTB_HORIZONTAL | wxNO_BORDER | wxTB_TEXT;

	m_toolbar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, style);

	if (m_toolbar == NULL)
	{
		return 1;
	}

	m_toolbar->SetToolBitmapSize(wxSize(32, 32));

	oldToolBar = GetToolBar();

	this->SetToolBar(m_toolbar);

	delete oldToolBar;

	m_toolbar->AddTool(ID_MENU_REFRESH,		wxT("Refresh"),		bmp_refresh, wxT("Refresh"));
	m_toolbar->AddTool(wxID_ABOUT,			wxT("About"),		bmp_about, wxT("About"));

	m_toolbar->Realize();

	return 0;
}

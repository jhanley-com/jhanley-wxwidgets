#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

#if defined(__LINUX__) || defined(__APPLE__)
#define	DEFINE_APP_512_XPM
#include "app_512.xpm"
#define	DEFINE_REFRESH_XPM
#include "refresh.xpm"
#endif

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_CLOSE(				MyFrame::OnWindowClose)

	EVT_MENU(ID_Hello,			MyFrame::OnHello)
	EVT_MENU(wxID_EXIT,			MyFrame::OnExit)
	EVT_MENU(wxID_ABOUT,			MyFrame::OnAbout)

	EVT_TIMER(ID_CLOCK_TIMER,		MyFrame::OnClockTimerEvent)

	EVT_MENU(ID_MENU_REFRESH,		MyFrame::OnRefresh)

	EVT_TREE_ITEM_RIGHT_CLICK(ID_TREE,	MyFrame::OnTreeRightClick)
	EVT_MENU(ID_MENU_TREE_COLLAPSE,		MyFrame::OnTreeCollapse)
	EVT_MENU(ID_MENU_TREE_EXPAND,		MyFrame::OnTreeExpand)

	EVT_LIST_ITEM_RIGHT_CLICK(ID_LIST,	MyFrame::OnListRightClick)
	EVT_MENU(ID_MENU_LIST_MSG,		MyFrame::OnListMsg)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
int		ret;

	g_frame = this;

	m_clock_timer = NULL;

	m_msplitter = NULL;
	m_tree = NULL;
	m_list = NULL;
	m_panel = NULL;
	m_sizer = NULL;
	m_toolbar = NULL;
	m_status = NULL;

	// --------------------------------------------------------
	// Set Program Icon
	// --------------------------------------------------------

	SetProgramIcon();

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

	ret = CreateMainWindow();

	if (ret != 0)
	{
		Close();

		return;
	}
}

void
MyFrame::OnWindowClose(wxCloseEvent &event)
{
	if (m_clock_timer != NULL)
	{
		m_clock_timer->Stop();

		delete m_clock_timer;

		m_clock_timer = NULL;
	}

	event.Skip();

	return;
}

#if defined(_WIN32)
void MyFrame::SetProgramIcon()
{
	this->SetIcon(wxIcon(wxNT("IDI_ICON1")));
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
		wxT("This is a wxWidgets' Hello world sample"),
		wxT("About Hello World"),
		wxOK | wxICON_INFORMATION,
		this);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage(wxT("Hello world from wxWidgets!"));
}

// --------------------------------------------------------
//
// --------------------------------------------------------

int
MyFrame::CreateMainWindow(void)
{
int		height;
int		ret;
int		width;

	// --------------------------------------------------------
	// Set our main window size
	// --------------------------------------------------------

	// SetMainWindowSize();
	this->SetSize(1024, 748);	// width, height

	// --------------------------------------------------------
	// Center Window
	// --------------------------------------------------------

	this->Centre();

	// --------------------------------------------------------
	// Add our Menus
	// --------------------------------------------------------

	ret = SetupMenus();

	if (ret != 0)
	{
		return 1;
	}

	// --------------------------------------------------------------------------------
	// Create the toolbar
	// --------------------------------------------------------------------------------

	ret = SetupToolbar(true);

	if (ret != 0)
	{
		return 1;
	}

	// --------------------------------------------------------
	// Create a Master Master splitter window
	// This window splits the screen into a left and right window
	// --------------------------------------------------------

	m_msplitter = new wxSplitterWindow(
					this,
					wxID_ANY,
					wxDefaultPosition,
					wxDefaultSize,
					wxSP_3D);

	if (m_msplitter == NULL)
	{
		return 1;
	}

	// --------------------------------------------------------
	// Create the Tree Window
	// --------------------------------------------------------

	ret = CreateTreeWindow();

	if (ret != 0)
	{
		return 1;
	}

	// --------------------------------------------------------
	// Create the List Window
	// --------------------------------------------------------

	ret = CreateListWindow();

	if (ret != 0)
	{
		return 1;
	}

	// --------------------------------------------------------
	// Get the program window width
	// --------------------------------------------------------

	this->GetSize(&width, &height);

	// --------------------------------------------------------
	// Setup Tree / List Splitter
	// --------------------------------------------------------

	m_msplitter->SplitVertically(m_tree_window.m_panel, m_panel);
	m_msplitter->SetMinimumPaneSize(75);
	m_msplitter->SetSashGravity(0.25);
	m_msplitter->SetSashPosition(200, true);
	m_msplitter->UpdateSize();

	// --------------------------------------------------------
	// Add our Status Bar
	// --------------------------------------------------------

	int	widths[4] = { -1, 100, 100, 100 };

	m_status = CreateStatusBar(1, wxST_SIZEGRIP);

	if (m_status == NULL)
	{
		return 1;
	}

	m_status->SetFieldsCount(4, widths);

	m_status->SetStatusText(wxT("Welcome to wxWidgets!"), 0);
	m_status->SetStatusText(wxT("Field 1"), 1);
	m_status->SetStatusText(wxT("Field 2"), 2);
	m_status->SetStatusText(wxT("Field 3"), 3);

	// --------------------------------------------------------
	// Run the clock
	// --------------------------------------------------------

	ret = StartClock();

	if (ret != 0)
	{
		return 1;
	}

	// --------------------------------------------------------
	// Test Code
	// --------------------------------------------------------
wxTreeItemId	itemId;
wxTreeItemId	rootId;

	rootId = m_tree->AddRoot(wxT("Root Node"), -1, -1, NULL);

	itemId = m_tree->AppendItem(rootId, wxT("Parent Node 1"), -1, -1, NULL);
	m_tree->AppendItem(itemId, wxT("1 Child Node"), -1, -1, NULL);
	itemId = m_tree->AppendItem(rootId, wxT("Parent Node 2"), -1, -1, NULL);
	m_tree->AppendItem(itemId, wxT("2 Child Node"), -1, -1, NULL);

	int	row = 0;
	m_list->InsertItem(row, wxT("Column 0"), -1);
	m_list->SetItem(row, 1, wxT("Column 1"));
	row++;
	m_list->InsertItem(row, wxT("Column 0"), -1);
	m_list->SetItem(row, 1, wxT("Column 1"));

	return 0;
}

void
MyFrame::OnRefresh(wxCommandEvent &event)
{
	wxMessageBox(
		wxT("Refresh Button Pressed"),
		wxT("About Hello World"),
		wxOK | wxICON_INFORMATION,
		this);
}

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

// --------------------------------------------------------
// Create the List Window
// --------------------------------------------------------

int
MyFrame::CreateListWindow(void)
{
int		col;
int		ret;
int		style;

	// --------------------------------------------------------
	// Create the Panel Control for the Right List Window
	// --------------------------------------------------------

	m_panel = new wxPanel(m_msplitter);

	if (m_panel == NULL)
	{
		return 1;
	}

	// --------------------------------------------------------
	// FIX - This sizer is just used by wxPanel, we don't need to save it
	// FIX - Also check that we are using m_sizer correctly (html.cpp), local_system...
	// --------------------------------------------------------

	m_sizer = new wxBoxSizer(wxVERTICAL);

	if (m_sizer == NULL)
	{
		return 1;
	}

	m_panel->SetSizer(m_sizer);

	// --------------------------------------------------------
	// Create the List Control in the Right Window
	// --------------------------------------------------------

	style = wxLC_REPORT;

	m_list = new wxListCtrl(m_panel, ID_LIST, wxDefaultPosition, wxDefaultSize, style);

	if (m_list == NULL)
	{
		return 1;
	}

	m_list->Show(true);

	m_sizer->Add(m_list, 1, wxEXPAND | wxALL, 0);

	col = 0;

	m_list->InsertColumn(col, wxT("Field"));
	m_list->SetColumnWidth(col, 175);
	col++;

	m_list->InsertColumn(col, wxT("Value"));
	m_list->SetColumnWidth(col, 350);
	col++;

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

// FIX - implement
	// m_list->SetImageList(m_imageList, wxIMAGE_LIST_NORMAL);
	// m_list->SetImageList(m_imageList, wxIMAGE_LIST_SMALL);

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

// FIX - implement
	// Connect(ID_LIST, wxEVT_COMMAND_RIGHT_CLICK, wxMouseEventHandler(MyFrame::RightClick));

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

	return 0;
}

// --------------------------------------------------------
// Handler for wxListCtrl the right-click event
// --------------------------------------------------------

void
MyFrame::OnListRightClick(wxListEvent &event)
{
int		sel;
int		ret;
wxMenu		*menu;

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

	sel = event.GetIndex();

	if (sel < 0)
	{
		event.Skip();

		return;
	}

	menu = new wxMenu;

	if (menu == NULL)
	{
		event.Skip();

		return;
	}

	menu->Append(ID_MENU_LIST_MSG,	wxT("Message Box"));

	m_rc_list.m_valid = true;
	m_rc_list.m_selection = sel;

	m_list->PopupMenu(menu, event.GetPoint());

	m_rc_list.m_valid = false;

	delete menu;

	event.Skip();

	return;
}

void
MyFrame::OnListMsg(wxCommandEvent &event)
{
int		sel;
wxString	msg;

	sel = m_rc_list.m_selection;

	msg << wxNT("ListCtrl Right Click Message\n");
	msg << "\n";
	msg << wxNT("Item selected ") << sel;

	wxMessageBox(
		msg,
		wxT("Example Program"),
		wxOK | wxICON_INFORMATION,
		this);

	event.Skip();
}

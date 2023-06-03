#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

// --------------------------------------------------------
// Create the Tree Window
// --------------------------------------------------------

int
MyFrame::CreateTreeWindow()
{
int		style;
wxSize		size;
wxBoxSizer	*sizer;

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

	m_tree_window.m_panel = new wxPanel(m_msplitter);

	if (m_tree_window.m_panel == NULL)
	{
		return 1;
	}

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

	sizer = new wxBoxSizer(wxVERTICAL);

	if (sizer == NULL)
	{
		m_tree_window.m_panel->Destroy();

		return 1;
	}

	m_tree_window.m_panel->SetSizer(sizer);

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

	style = wxBU_LEFT | wxNO_BORDER;

	m_tree_window.m_title = new wxButton(
// FIX cast
					// static_cast<wxWindow *>m_tree_window.m_panel,
					(wxWindow *)m_tree_window.m_panel,
					wxID_ANY,
					wxT("Test Name"),
					wxDefaultPosition,
					wxDefaultSize,
					style);

	if (m_tree_window.m_title == NULL)
	{
		return 1;
	}

	sizer->Add(m_tree_window.m_title, 0, wxEXPAND | wxALL, 0);

	// --------------------------------------------------------
	// Create the Tree Control in the Left Tree Window
	// --------------------------------------------------------

	style = wxTR_DEFAULT_STYLE | wxTR_SINGLE | wxTR_HAS_BUTTONS;

	m_tree = new wxTreeCtrl(m_tree_window.m_panel, ID_TREE, wxPoint(0, 0), wxDefaultSize, style);

	if (m_tree == NULL)
	{
		return 1;
	}

	sizer->Add(m_tree, 1, wxEXPAND | wxALL, 0);

	m_tree_window.m_tree = m_tree;

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

// FIX - implement
	// m_tree->SetImageList(m_imageList);

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

	m_tree->Show(true);

	// --------------------------------------------------------
	//
	// --------------------------------------------------------

	return 0;
}

// --------------------------------------------------------
// Handler for wxTreeCtrl the right-click event
// --------------------------------------------------------

void
MyFrame::OnTreeRightClick(wxTreeEvent &event)
{
wxMenu		*menu;
wxTreeItemId	itemId;

	itemId = event.GetItem();

	menu = new wxMenu;

	if (menu == NULL)
	{
		event.Skip();

		return;
	}

	if (m_tree->IsExpanded(itemId) == false)
	{
		menu->Append(ID_MENU_TREE_EXPAND,	wxT("Expand"));
	}
	else
	{
		menu->Append(ID_MENU_TREE_COLLAPSE,	wxT("Collapse"));
	}

	m_rc.m_valid = true;
	m_rc.m_itemId = itemId;

	m_tree->PopupMenu(menu, event.GetPoint());

	m_rc.m_valid = false;

	delete menu;

	event.Skip();

	return;
}

wxTreeItemId
MyFrame::GetTreeMenuItem(void)
{
	if (m_rc.m_valid == true)
	{
		return m_rc.m_itemId;
	}

	return m_tree->GetSelection();
}

void
MyFrame::OnTreeCollapse(wxCommandEvent &event)
{
	m_tree->Collapse(GetTreeMenuItem());

	event.Skip();
}

void
MyFrame::OnTreeExpand(wxCommandEvent &event)
{
	m_tree->Expand(GetTreeMenuItem());

	event.Skip();
}

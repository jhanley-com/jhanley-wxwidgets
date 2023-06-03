#include "wx/datetime.h"
#include "wx/splitter.h"
#include "wx/treectrl.h"
#include "wx/listctrl.h"
#include "wx/wizard.h"
#include "wx/textctrl.h"
#include "wx/button.h"
#include "wx/sizer.h"
#include "wx/timer.h"

#if defined(__LINUX__) || defined(__APPLE__)
#include "app_512.xpm"
#include "refresh.xpm"
#endif

// This is for future support of localization
// wxNT(param) is used for string meaning "do not translate"
// wxT(param) is used for strings to be translated
#define	wxNT(param)	param

enum
{
	ID_Hello = 1,
	ID_TREE = 100,
	ID_LIST,
	ID_MENU_REFRESH,
	ID_MENU_TREE_COLLAPSE,
	ID_MENU_TREE_EXPAND,

	ID_CLOCK_TIMER,
	ID_MENU_LIST_MSG
};

//************************************************************
// Declare the application class
//************************************************************

class MyApp: public wxApp
{
public:
	virtual bool	OnInit();
	virtual	int	OnExit();

	wxLocale	*m_locale;
};

//************************************************************
// Declare our main frame class
//************************************************************

class MyFrame: public wxFrame
{
	//************************************************************
	// Constructor
	//************************************************************

public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void OnWindowClose(wxCloseEvent &event);

// private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	void SetProgramIcon();

	int SetupMenus(void);
	int SetupToolbar(bool force);
	int CreateMainWindow(void);
	int CreateTreeWindow();
	int CreateListWindow();

	int StartClock(void);
	// void OnClock(wxCommandEvent& event);

	void OnClockTimerEvent(wxTimerEvent &);

	void OnTreeRightClick(wxTreeEvent &event);
	void OnTreeCollapse(wxCommandEvent &event);
	void OnTreeExpand(wxCommandEvent &event);

	wxTreeItemId	GetTreeMenuItem(void);
	wxTreeItemId	GetTreeSelectedItem(void);

	void OnListRightClick(wxListEvent &event);
	void OnListMsg(wxCommandEvent &event);

	wxTimer			*m_clock_timer;

	wxStatusBar		*m_status;
	wxSplitterWindow	*m_msplitter;	// Master Splitter Window
	wxTreeCtrl		*m_tree;
	wxPanel			*m_panel;
	wxListCtrl		*m_list;
	wxSizer			*m_sizer;
	wxToolBar		*m_toolbar;

	class	tree_window
	{
	public:
		tree_window()
		{
			Init();
		}

		void	Init(void)
		{
			m_panel = NULL;
			m_title = NULL;
			m_tree = NULL;
		}

		void	SetTitle(const wxString &value)
		{
			if (m_title == NULL)
			{
				return;
			}

			m_title->SetLabel(value);
		}

		wxPanel			*m_panel;
		wxButton		*m_title;
		wxTreeCtrl		*m_tree;
	};

	tree_window	m_tree_window;

	struct	_rc	{
		bool		m_valid;
		wxTreeItemId	m_itemId;
	} m_rc;

	struct	_list {
		void	Init(void)
		{
			m_valid = false;
			m_selection = -1;
			// m_type = OBJECT_TYPE_NONE;
		}

		bool			m_valid;
		int			m_selection;
		// ObjDataType		m_type;
	} m_rc_list;

	void OnRefresh(wxCommandEvent &event);

	//************************************************************
	// This class handles events
	//************************************************************

	wxDECLARE_EVENT_TABLE();
};

extern	MyFrame	*g_frame;

enum
{
	ID_Hello = 1
};

//************************************************************
// Declare the application class
//************************************************************

class MyApp: public wxApp
{
public:
	virtual bool	OnInit();
	virtual	int	OnExit();
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

private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	//************************************************************
	// This class handles events
	//************************************************************

	wxDECLARE_EVENT_TABLE();
};

extern	MyFrame	*g_frame;

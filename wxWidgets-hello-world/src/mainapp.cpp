#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

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
    g_frame = new MyFrame( "Hello World", wxPoint(50, 50), wxSize(450, 340) );

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

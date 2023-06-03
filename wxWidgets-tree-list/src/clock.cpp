#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "local.h"

int
MyFrame::StartClock(void)
{
	m_clock_timer = new wxTimer;

	if (m_clock_timer != NULL)
	{
		m_clock_timer->SetOwner(this, ID_CLOCK_TIMER);

		m_clock_timer->Start(1000, wxTIMER_CONTINUOUS);
	}

	return 0;
}

void
MyFrame::OnClockTimerEvent(wxTimerEvent &)
{
wxString	msg;
wxDateTime	datetime;

	msg = datetime.Now().FormatTime();

	m_status->SetStatusText(msg, 3);
}

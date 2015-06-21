// software.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "software.h"
#include "softwareDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSoftwareApp

BEGIN_MESSAGE_MAP(CSoftwareApp, CWinApp)
	//{{AFX_MSG_MAP(CSoftwareApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoftwareApp construction

CSoftwareApp::CSoftwareApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSoftwareApp object

CSoftwareApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSoftwareApp initialization

BOOL CSoftwareApp::InitInstance()
{
	if (!SUCCEEDED(CoInitialize(NULL)))
	{
		::AfxMessageBox(_T("Failed to initialize COM!"));
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	InitializeSkin();
	LoadSkinFile("WhiteFire.rss");

	CSoftwareDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

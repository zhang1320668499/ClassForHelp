// software.h : main header file for the SOFTWARE application
//

#if !defined(AFX_SOFTWARE_H__C0907CC6_94E1_4788_9AEE_C44F6D54A97A__INCLUDED_)
#define AFX_SOFTWARE_H__C0907CC6_94E1_4788_9AEE_C44F6D54A97A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSoftwareApp:
// See software.cpp for the implementation of this class
//

class CSoftwareApp : public CWinApp
{
public:
	CSoftwareApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoftwareApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSoftwareApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOFTWARE_H__C0907CC6_94E1_4788_9AEE_C44F6D54A97A__INCLUDED_)

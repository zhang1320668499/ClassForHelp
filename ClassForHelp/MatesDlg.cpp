// MatesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "MatesDlg.h"
#include "DataDlg.h"
#include "Leave.h"
#include "Score.h"
#include "Dorm1Dlg.h"
#include "ScholDlg.h"
#include "About.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMatesDlg dialog


CMatesDlg::CMatesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMatesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMatesDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMatesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMatesDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMatesDlg, CDialog)
	//{{AFX_MSG_MAP(CMatesDlg)
	ON_COMMAND(ID_MENU_CAL, OnMenuCal)
	ON_COMMAND(ID_MENU_NOTEPAD, OnMenuNotepad)
	ON_COMMAND(ID_MENU_SEARCH, OnMenuSearch)
	ON_BN_CLICKED(IDC_BUTTONCLASS, OnButtonclass)
	ON_BN_CLICKED(IDC_BUTTONSCORE, OnButtonscore)
	ON_COMMAND(ID_MENUITEMABOUT, OnMenuitemabout)
	ON_BN_CLICKED(IDC_BUTTONDORM, OnButtondorm)
	ON_BN_CLICKED(IDC_BUTTONLEAVE, OnButtonleave)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_COMMAND(ID_MENUITEMSCORE, OnMenuitemscore)
	ON_COMMAND(ID_MENUITEMLEAVE, OnMenuitemleave)
	ON_COMMAND(ID_MENUITEMJIANGXUEJIN, OnMenuitemjiangxuejin)
	ON_COMMAND(ID_MENUITEMDORM, OnMenuitemdorm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMatesDlg message handlers

void CMatesDlg::OnMenuCal() 
{
	// TODO: Add your command handler code here
	WinExec("calc.exe",SW_SHOW);	
}

void CMatesDlg::OnMenuNotepad() 
{
	// TODO: Add your command handler code here
	WinExec("notepad.exe",SW_SHOW);
	
}

void CMatesDlg::OnMenuSearch() 
{
	// TODO: Add your command handler code here
	CDataDlg dlg;
	dlg.DoModal();
}

void CMatesDlg::OnButtonclass() 
{
	// TODO: Add your control notification handler code here
	CDataDlg dlg;
	dlg.DoModal();
	
}

void CMatesDlg::OnButtonscore() 
{
	// TODO: Add your control notification handler code here
	CScore dlg;
	dlg.DoModal();
	
}

void CMatesDlg::OnMenuitemabout() 
{
	// TODO: Add your command handler code here
	CAbout dlg;
	dlg.DoModal();

	
}

void CMatesDlg::OnButtondorm() 
{
	// TODO: Add your control notification handler code here
	CDorm1Dlg dlg;
	dlg.DoModal();
	
}

void CMatesDlg::OnButtonleave() 
{
	// TODO: Add your control notification handler code here
	CLeave dlg;
	dlg.DoModal();
	
}

void CMatesDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CScholDlg dlg;
	dlg.DoModal();

	
}

void CMatesDlg::OnMenuitemscore() 
{
	// TODO: Add your command handler code here
    CScore dlg;
	dlg.DoModal();
	
	
}

void CMatesDlg::OnMenuitemleave() 
{
	// TODO: Add your command handler code here
    CLeave dlg;
	dlg.DoModal();
	
}

void CMatesDlg::OnMenuitemjiangxuejin() 
{
	// TODO: Add your command handler code here
	CScholDlg dlg;
	dlg.DoModal();
	
}

void CMatesDlg::OnMenuitemdorm() 
{
	// TODO: Add your command handler code here
	CDorm1Dlg dlg;
	dlg.DoModal();
	
}

// ChaxunDlg.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "ChaxunDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChaxunDlg dialog


CChaxunDlg::CChaxunDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChaxunDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChaxunDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CChaxunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChaxunDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChaxunDlg, CDialog)
	//{{AFX_MSG_MAP(CChaxunDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChaxunDlg message handlers

// RegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "RegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RegDlg dialog


RegDlg::RegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(RegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void RegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RegDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RegDlg, CDialog)
	//{{AFX_MSG_MAP(RegDlg)
	ON_BN_CLICKED(IDC_Quxiao, OnQuxiao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RegDlg message handlers

void RegDlg::OnQuxiao() 
{
	CDialog::OnCancel();
}

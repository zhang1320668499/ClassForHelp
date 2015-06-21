// AddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "AddDlg.h"
#include "Score.h"
#include "Leave.h"
#include "ScholDlg.h"
#include "Dorm1Dlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddDlg dialog


CAddDlg::CAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddDlg)
	m_strNumber3 = _T("");
	m_strName3 = _T("");
	m_strUniver3 = _T("");
	m_strStartTime = _T("");
	m_FinalTime = _T("");
	m_strbeizhu = _T("");
	//}}AFX_DATA_INIT
}


void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strNumber3);
	DDX_Text(pDX, IDC_EDIT2, m_strName3);
	DDX_Text(pDX, IDC_EDIT3, m_strUniver3);
	DDX_Text(pDX, IDC_EDIT5, m_strStartTime);
	DDX_Text(pDX, IDC_EDIT6, m_FinalTime);
	DDX_Text(pDX, IDC_EDIT9, m_strbeizhu);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialog)
	//{{AFX_MSG_MAP(CAddDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_COMMAND(ID_MENUITEMSCORE, OnMenuitemscore)
	ON_COMMAND(ID_MENUITEMLEAVE, OnMenuitemleave)
	ON_COMMAND(ID_MENUITEMJIANGXUEJIN, OnMenuitemjiangxuejin)
	ON_COMMAND(ID_MENUITEMDORM, OnMenuitemdorm)
	ON_COMMAND(ID_MENUITEMABOUT, OnMenuitemabout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddDlg message handlers

void CAddDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	//更新数据
	UpdateData(TRUE);
	if (m_strName3.IsEmpty())
	{
		AfxMessageBox((_T("姓名不能为空。")));
		return;
	}
	if(m_FinalTime < m_strStartTime)
	{
		MessageBox("请输入正确的起止时间!");
		return;
	}
	CDialog::OnOK();

	
}

void CAddDlg::OnMenuitemscore() 
{
	// TODO: Add your command handler code here
	CScore dlg;
	dlg.DoModal();

	
}

void CAddDlg::OnMenuitemleave() 
{
	// TODO: Add your command handler code here
	CLeave dlg;
	dlg.DoModal();
	
}

void CAddDlg::OnMenuitemjiangxuejin() 
{
	// TODO: Add your command handler code here
	CScholDlg dlg;
	dlg.DoModal();

	
}

void CAddDlg::OnMenuitemdorm() 
{
	// TODO: Add your command handler code here
	CDorm1Dlg dlg;
	dlg.DoModal();
	
}

void CAddDlg::OnMenuitemabout() 
{
	// TODO: Add your command handler code here

	
}

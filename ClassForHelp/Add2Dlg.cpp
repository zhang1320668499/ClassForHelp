// Add2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "Add2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdd2Dlg dialog


CAdd2Dlg::CAdd2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdd2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdd2Dlg)
	m_Xingbie = _T("");
	m_Beizhu = _T("");
	m_Chuangweihao = _T("");
	m_Louhao = _T("");
	m_Zhuanye = _T("");
	m_Xingming = _T("");
	m_Xuehao = _T("");
	m_Qinshihao = _T("");
	//}}AFX_DATA_INIT
}


void CAdd2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdd2Dlg)
	DDX_CBString(pDX, IDC_COMBO_SEX, m_Xingbie);
	DDX_Text(pDX, IDC_EDIT_BEIZHU, m_Beizhu);
	DDX_Text(pDX, IDC_EDIT_CHUANGWEIHAO, m_Chuangweihao);
	DDX_Text(pDX, IDC_EDIT_LOUHAO, m_Louhao);
	DDX_Text(pDX, IDC_EDIT_MAJOR3, m_Zhuanye);
	DDX_Text(pDX, IDC_EDIT_NAME2, m_Xingming);
	DDX_Text(pDX, IDC_EDIT_NUMBER, m_Xuehao);
	DDX_Text(pDX, IDC_EDIT_QINSHIHAO, m_Qinshihao);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdd2Dlg, CDialog)
	//{{AFX_MSG_MAP(CAdd2Dlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdd2Dlg message handlers

void CAdd2Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	//更新数据
	UpdateData(TRUE);
	if (m_Xingming.IsEmpty())
	{
		AfxMessageBox((_T("姓名不能为空。")));
		return;
	}
	
	CDialog::OnOK();
	
}


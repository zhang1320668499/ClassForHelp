#if !defined(AFX_ADD2DLG_H__F5C91210_58BE_4E2E_92B6_3859350C9A33__INCLUDED_)
#define AFX_ADD2DLG_H__F5C91210_58BE_4E2E_92B6_3859350C9A33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Add2Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdd2Dlg dialog

class CAdd2Dlg : public CDialog
{
// Construction
public:
	CAdd2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdd2Dlg)
	enum { IDD = IDD_DIALOGADD2 };
	CString	m_Xingbie;
	CString	m_Beizhu;
	CString	m_Chuangweihao;
	CString	m_Louhao;
	CString	m_Zhuanye;
	CString	m_Xingming;
	CString	m_Xuehao;
	CString	m_Qinshihao;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdd2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdd2Dlg)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD2DLG_H__F5C91210_58BE_4E2E_92B6_3859350C9A33__INCLUDED_)

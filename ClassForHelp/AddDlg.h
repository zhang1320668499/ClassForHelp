#if !defined(AFX_ADDDLG_H__07239F59_DB39_45CD_9298_CED69C364C0E__INCLUDED_)
#define AFX_ADDDLG_H__07239F59_DB39_45CD_9298_CED69C364C0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddDlg dialog

class CAddDlg : public CDialog
{
// Construction
public:
	CAddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddDlg)
	enum { IDD = IDD_DIALOGADD };
	CString	m_strNumber3;
	CString	m_strName3;
	CString	m_strUniver3;
	CString	m_strStartTime;
	CString	m_FinalTime;
	CString	m_strbeizhu;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddDlg)
	afx_msg void OnButton1();
	afx_msg void OnMenuitemscore();
	afx_msg void OnMenuitemleave();
	afx_msg void OnMenuitemjiangxuejin();
	afx_msg void OnMenuitemdorm();
	afx_msg void OnMenuitemabout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__07239F59_DB39_45CD_9298_CED69C364C0E__INCLUDED_)

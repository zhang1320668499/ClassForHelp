#if !defined(AFX_CHAXUNDLG_H__7DCED25C_4AAA_448A_A837_42EA73F51F0D__INCLUDED_)
#define AFX_CHAXUNDLG_H__7DCED25C_4AAA_448A_A837_42EA73F51F0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChaxunDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChaxunDlg dialog

class CChaxunDlg : public CDialog
{
// Construction
public:
	CChaxunDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChaxunDlg)
	enum { IDD = IDD_DIALOGCHAXUN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChaxunDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChaxunDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAXUNDLG_H__7DCED25C_4AAA_448A_A837_42EA73F51F0D__INCLUDED_)

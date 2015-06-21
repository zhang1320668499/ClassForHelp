#if !defined(AFX_REGDLG_H__7C66C3E4_EE42_485E_B1B0_D21E9D57C8E5__INCLUDED_)
#define AFX_REGDLG_H__7C66C3E4_EE42_485E_B1B0_D21E9D57C8E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RegDlg dialog

class RegDlg : public CDialog
{
// Construction
public:
	RegDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RegDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RegDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RegDlg)
	afx_msg void OnQuxiao();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGDLG_H__7C66C3E4_EE42_485E_B1B0_D21E9D57C8E5__INCLUDED_)

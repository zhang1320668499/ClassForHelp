#if !defined(AFX_MATESDLG_H__2648C37F_7183_44A4_B4BE_B238B64B1FCD__INCLUDED_)
#define AFX_MATESDLG_H__2648C37F_7183_44A4_B4BE_B238B64B1FCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MatesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMatesDlg dialog

class CMatesDlg : public CDialog
{
// Construction
public:
	CMatesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMatesDlg)
	enum { IDD = IDD_MATES_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMatesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMatesDlg)
	afx_msg void OnMenuCal();
	afx_msg void OnMenuNotepad();
	afx_msg void OnMenuSearch();
	afx_msg void OnButtonclass();
	afx_msg void OnButtonscore();
	afx_msg void OnMenuitemabout();
	afx_msg void OnButtondorm();
	afx_msg void OnButtonleave();
	afx_msg void OnButton7();
	afx_msg void OnMenuitemscore();
	afx_msg void OnMenuitemleave();
	afx_msg void OnMenuitemjiangxuejin();
	afx_msg void OnMenuitemdorm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATESDLG_H__2648C37F_7183_44A4_B4BE_B238B64B1FCD__INCLUDED_)

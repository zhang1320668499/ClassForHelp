#if !defined(AFX_LEAVE_H__05B392A3_33B7_41C3_96BB_80C64FCE327E__INCLUDED_)
#define AFX_LEAVE_H__05B392A3_33B7_41C3_96BB_80C64FCE327E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Leave.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeave dialog

class CLeave : public CDialog
{
// Construction
public:
    BOOL OpenDatabase(LPCTSTR lpszConnect, long nOptions=adConnectUnspecified);
	BOOL CloseDatabase();
	BOOL OpenRecordset(LPCTSTR lpszSource, long nCursorType=adOpenDynamic, 
			  long nLockType=adLockOptimistic, long nOptions=adCmdText);
	BOOL CloseRecordset();
	CLeave(CWnd* pParent = NULL);   // standard constructor
	~CLeave();


// Dialog Data
	//{{AFX_DATA(CLeave)
	enum { IDD = IDD_DIALOGLEAVE };
	CListCtrl	m_ctrlList2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeave)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLeave)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonadd1();
	afx_msg void OnButtonadd();
	afx_msg void OnButtondel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEAVE_H__05B392A3_33B7_41C3_96BB_80C64FCE327E__INCLUDED_)

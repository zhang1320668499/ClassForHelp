#if !defined(AFX_SCHOLDLG_H__5EAA32AF_5EA9_4E94_BA57_3B7FA65DC59E__INCLUDED_)
#define AFX_SCHOLDLG_H__5EAA32AF_5EA9_4E94_BA57_3B7FA65DC59E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScholDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScholDlg dialog

class CScholDlg : public CDialog
{
// Construction
public:
	BOOL OpenDatabase(LPCTSTR lpszConnect, long nOptions=adConnectUnspecified);
	BOOL CloseDatabase();
	BOOL OpenRecordset(LPCTSTR lpszSource, long nCursorType=adOpenDynamic, 
		long nLockType=adLockOptimistic, long nOptions=adCmdText);
	BOOL CloseRecordset();
	CScholDlg(CWnd* pParent = NULL);   // standard constructor
	~CScholDlg();

// Dialog Data
	//{{AFX_DATA(CScholDlg)
	enum { IDD = IDD_DIALOGJIANGXUEJIN };
	long	m_shenxin;
	long	m_sixiang;
	long	m_wenhua;
	long	m_zhuanye;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScholDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScholDlg)
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCHOLDLG_H__5EAA32AF_5EA9_4E94_BA57_3B7FA65DC59E__INCLUDED_)

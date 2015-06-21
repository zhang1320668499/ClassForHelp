#if !defined(AFX_DATADLG_H__74DEDDBE_9452_4B30_9CA0_90A7AC11ECFE__INCLUDED_)
#define AFX_DATADLG_H__74DEDDBE_9452_4B30_9CA0_90A7AC11ECFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog

class CDataDlg : public CDialog
{
// Construction
public:
	BOOL OpenDatabase(LPCTSTR lpszConnect, long nOptions=adConnectUnspecified);
	BOOL CloseDatabase();
	BOOL OpenRecordset(LPCTSTR lpszSource, long nCursorType=adOpenDynamic, 
		long nLockType=adLockOptimistic, long nOptions=adCmdText);
	BOOL CloseRecordset();
	CDataDlg(CWnd* pParent = NULL);   // standard constructor
	~CDataDlg();

// Dialog Data
	//{{AFX_DATA(CDataDlg)
	enum { IDD = IDD_DATADLG_DIALOG };
	CListCtrl	m_ctrlList;
	CString	m_str_name;
	CString	m_strUniver;
	CString	m_strPro;
	CString	m_strNumber;
	CString	m_strAge;
	CString	m_strSex;
	CString	m_strMajor;
	CString	m_strTel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTTONbaocun();
	afx_msg void OnButtonDel();
	afx_msg void OnBUTTONedit();
	afx_msg void OnButtonAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATADLG_H__74DEDDBE_9452_4B30_9CA0_90A7AC11ECFE__INCLUDED_)

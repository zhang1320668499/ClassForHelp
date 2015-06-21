#if !defined(AFX_DORM1DLG_H__19CEC8A2_9B7E_49D9_B74E_1D68A1044DD0__INCLUDED_)
#define AFX_DORM1DLG_H__19CEC8A2_9B7E_49D9_B74E_1D68A1044DD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dorm1Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDorm1Dlg dialog

class CDorm1Dlg : public CDialog
{
// Construction
public:
	BOOL OpenDatabase(LPCTSTR lpszConnect, long nOptions=adConnectUnspecified);
	BOOL CloseDatabase();
	BOOL OpenRecordset(LPCTSTR lpszSource, long nCursorType=adOpenDynamic, 
			  long nLockType=adLockOptimistic, long nOptions=adCmdText);
	BOOL CloseRecordset();
	CDorm1Dlg(CWnd* pParent = NULL);   // standard constructor
	~CDorm1Dlg();

// Dialog Data
	//{{AFX_DATA(CDorm1Dlg)
	enum { IDD = IDD_DIALOGDORM };
	CListCtrl	m_ctrlList4;
	CListCtrl	m_ctrlList3;
	CImageList m_imglst;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDorm1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	struct SState
	{
		CString strName;
		DWORD number;
		DWORD dormnum;
	};

	// Generated message map functions
	//{{AFX_MSG(CDorm1Dlg)
	afx_msg void OnButtonAdd();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonChaxun();
	afx_msg void OnButtonDel();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DORM1DLG_H__19CEC8A2_9B7E_49D9_B74E_1D68A1044DD0__INCLUDED_)

// softwareDlg.h : header file
//

#if !defined(AFX_SOFTWAREDLG_H__E6DA614F_7337_4D5B_8C79_6388ADB81D67__INCLUDED_)
#define AFX_SOFTWAREDLG_H__E6DA614F_7337_4D5B_8C79_6388ADB81D67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "xSkinButton.h"

/////////////////////////////////////////////////////////////////////////////
// CSoftwareDlg dialog

class CSoftwareDlg : public CDialog
{
// Construction
public:
	BOOL OpenDatabase(LPCTSTR lpszConnect, long nOptions=adConnectUnspecified);
	BOOL CloseDatabase();
	BOOL OpenRecordset(LPCTSTR lpszSource, long nCursorType=adOpenDynamic, 
		long nLockType=adLockOptimistic, long nOptions=adCmdText);
	BOOL CloseRecordset();
	CSoftwareDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(CSoftwareDlg)
	enum { IDD = IDD_SOFTWARE_DIALOG };
	CButton	m_Dengru;
	CButton	m_strUserName;
	CxSkinButton	m_Xiugai;
	CString	m_strName;
	int		m_strPass;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoftwareDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSoftwareDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDengru();
	afx_msg void OnXiugai();
	afx_msg void OnMenuitemscore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOFTWAREDLG_H__E6DA614F_7337_4D5B_8C79_6388ADB81D67__INCLUDED_)


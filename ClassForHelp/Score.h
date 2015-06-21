#if !defined(AFX_SCORE_H__559BBB4B_D360_49E7_A1F2_F7EBB0F9CC75__INCLUDED_)
#define AFX_SCORE_H__559BBB4B_D360_49E7_A1F2_F7EBB0F9CC75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Score.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScore dialog

class CScore : public CDialog
{
// Construction
public:
	BOOL OpenDatabase(LPCTSTR lpszConnect, long nOptions=adConnectUnspecified);
	BOOL CloseDatabase();
	BOOL OpenRecordset(LPCTSTR lpszSource, long nCursorType=adOpenDynamic, 
		long nLockType=adLockOptimistic, long nOptions=adCmdText);
	BOOL CloseRecordset();
	CScore(CWnd* pParent = NULL);   // standard constructor
	~CScore();

// Dialog Data
	//{{AFX_DATA(CScore)
	enum { IDD = IDD_DIALOGSCORE };
	CListCtrl	m_ctrlList1;
	CString	m_strxingming;
	long	m_longgaoshu;
	long	m_longxuehao;
	long	m_longjindaishi;
	long	m_longyuwen;
	long	m_longcyuyan;
	long	m_longjidao;
	long	m_longyinyu;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScore)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScore)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton3();
	afx_msg void OnButton9();
	afx_msg void OnButton6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCORE_H__559BBB4B_D360_49E7_A1F2_F7EBB0F9CC75__INCLUDED_)

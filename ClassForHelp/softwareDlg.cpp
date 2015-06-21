// softwareDlg.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "softwareDlg.h"
#include "RegDlg.h"
#include "MatesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoftwareDlg dialog

CSoftwareDlg::CSoftwareDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSoftwareDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSoftwareDlg)
	m_strName = _T("");
	m_strPass = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	if (!SUCCEEDED(m_pConnection.CreateInstance(__uuidof(Connection))))
	{
		m_pConnection = NULL;
		TRACE(_T("Database CreateInstance failed"));
	}

	if (!SUCCEEDED(m_pRecordset.CreateInstance(__uuidof(Recordset))))
	{
		m_pRecordset = NULL;
		TRACE(_T("Recordset CreateInstance Failed!"));
	}
	//打开数据库
	CString strConnect = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source= classhelp.mdb");
	if (!OpenDatabase(strConnect))
	{
		AfxMessageBox(_T("数据库打开失败。"));
		return;
	}

	//打开记录集
	CString strSource = _T("SELECT * FROM 用户管理");
	if (!OpenRecordset(strSource))
	{
		AfxMessageBox(_T("记录集打开失败。"));
		return;
	}
}

void CSoftwareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSoftwareDlg)
	DDX_Control(pDX, IDC_Dengru, m_Dengru);
	DDX_Control(pDX, IDC_Xiugai, m_Xiugai);
	DDX_Text(pDX, IDC_EDITNAME, m_strName);
	DDX_Text(pDX, IDC_EDITPASS, m_strPass);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSoftwareDlg, CDialog)
	//{{AFX_MSG_MAP(CSoftwareDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Dengru, OnDengru)
	ON_BN_CLICKED(IDC_Xiugai, OnXiugai)
	ON_COMMAND(ID_MENUITEMSCORE, OnMenuitemscore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoftwareDlg message handlers

BOOL CSoftwareDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSoftwareDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();


	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSoftwareDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSoftwareDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSoftwareDlg::OnDengru() 
{
	UpdateData(TRUE);
	if(m_strPass==1234&&m_strName=="admin")
	{
		CMatesDlg dlg;
	    dlg.DoModal();
		CDialog::OnOK();
	}
	else
	{
        AfxMessageBox(_T("请输入正确的用户名和密码。"));
	}

}

void CSoftwareDlg::OnXiugai() 
{
	RegDlg dlg;
	dlg.DoModal();

}
BOOL CSoftwareDlg::OpenDatabase(LPCTSTR lpszConnect, long nOptions)
{
	ASSERT(m_pConnection != NULL);
	ASSERT(lpszConnect != NULL);
	ASSERT(AfxIsValidString(lpszConnect));
	
	//打开数据库连接
	try
	{
		return SUCCEEDED(m_pConnection->Open(_bstr_t(lpszConnect), 
			_T(""), _T(""), nOptions));
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return FALSE;
	}
}

BOOL CSoftwareDlg::CloseDatabase()
{
	ASSERT(m_pConnection != NULL);

	//关闭数据库连接
	try
	{
		if (m_pConnection->State & adStateOpen) 
		{
			return SUCCEEDED(m_pConnection->Close());
		}
		else
		{
			return TRUE;
		}
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return FALSE;
	} 
}

BOOL CSoftwareDlg::OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions)
{
	ASSERT(m_pConnection != NULL);
	ASSERT(m_pRecordset != NULL);
	ASSERT(lpszSource != NULL);
	ASSERT(AfxIsValidString(lpszSource));

	//打开记录集
	try
	{
		return (SUCCEEDED(m_pRecordset->Open(_variant_t(lpszSource),
										m_pConnection.GetInterfacePtr(),
										(CursorTypeEnum)nCursorType, 
										(LockTypeEnum)nLockType,
										nOptions)));
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return FALSE;
	}
}

BOOL CSoftwareDlg::CloseRecordset()
{
	ASSERT(m_pRecordset != NULL);

	//关闭记录集
	try
	{
		if (m_pRecordset->State & adStateOpen) 
		{
			return SUCCEEDED(m_pRecordset->Close());
		}
		else
		{
			return TRUE;
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return FALSE;
	}
}

void CSoftwareDlg::OnMenuitemscore() 
{
	// TODO: Add your command handler code here
	
}

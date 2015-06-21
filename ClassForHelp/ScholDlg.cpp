// ScholDlg.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "ScholDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScholDlg dialog


CScholDlg::CScholDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScholDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScholDlg)
	m_shenxin = 0;
	m_sixiang = 0;
	m_wenhua = 0;
	m_zhuanye = 0;
	//}}AFX_DATA_INIT
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
	CString strSource = _T("SELECT * FROM 成绩管理");
	if (!OpenRecordset(strSource))
	{
		AfxMessageBox(_T("记录集打开失败。"));
		return;
	}

}
CScholDlg::~CScholDlg()
{
	CloseRecordset();
	CloseDatabase();
}


void CScholDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScholDlg)
	DDX_Text(pDX, IDC_EDIT4, m_shenxin);
	DDX_Text(pDX, IDC_EDIT10, m_sixiang);
	DDX_Text(pDX, IDC_EDIT11, m_wenhua);
	DDX_Text(pDX, IDC_EDIT12, m_zhuanye);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScholDlg, CDialog)
	//{{AFX_MSG_MAP(CScholDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScholDlg message handlers

void CScholDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here

	
}
BOOL CScholDlg::OpenDatabase(LPCTSTR lpszConnect, long nOptions)
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

BOOL CScholDlg::CloseDatabase()
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

BOOL CScholDlg::OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions)
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

BOOL CScholDlg::CloseRecordset()
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

BOOL CScholDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	pListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	pListCtrl->InsertColumn(1, _T("编号"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(2, _T("学号"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(3, _T("姓名"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(4, _T("思想道德分"), LVCFMT_CENTER, 100);
	pListCtrl->InsertColumn(5, _T("身心素质分"), LVCFMT_CENTER, 100);
	pListCtrl->InsertColumn(6, _T("文化素质分"), LVCFMT_CENTER, 100);
	pListCtrl->InsertColumn(7, _T("专业素质分"), LVCFMT_CENTER, 100);
	pListCtrl->InsertColumn(8, _T("综合成绩"), LVCFMT_CENTER, 100);
	//读取记录集
	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
	{
		return FALSE;
	}
	m_pRecordset->MoveFirst();
	int n = 0;
	while (!m_pRecordset->adoEOF)
	{
		_variant_t varValue;
		CString nName = _T("");
		int nNumber=0;
		int nsixiang=0;
		int nshenxin=0;
		int nwenhua=0;
		float nzhuanye=0;
		float nzonghe=0;

		varValue = m_pRecordset->GetCollect(_variant_t(_T("学号")));
		if (varValue.vt != VT_NULL)
		{
			nNumber = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("姓名")));
		if (varValue.vt != VT_NULL)
		{
			nName = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("思想道德分")));
		if (varValue.vt != VT_NULL)
		{
			nsixiang = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("身心素质分")));
		if (varValue.vt != VT_NULL)
		{
			nshenxin = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("文化素质分")));
		if (varValue.vt != VT_NULL)
		{
			nwenhua = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("平均分")));
		if (varValue.vt != VT_NULL)
		{
			nzhuanye = varValue.fltVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("综合成绩")));
		if (varValue.vt != VT_NULL)
		{
			nzonghe = varValue.fltVal;
		}

		//刷新ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1,strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%d"), nsixiang);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%d"), nshenxin);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%d"), nwenhua);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%f"), nzhuanye);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%f"), nzonghe);
		pListCtrl->SetItemText(n, 7, strText);
		n++;

		m_pRecordset->MoveNext();
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CScholDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("记录集未打开。")));
		return;
	}

	//获得记录集当前位置
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		return;
	}
	int nItem = pListCtrl->GetNextSelectedItem(pos);
	//修改记录集
	if (m_pRecordset->BOF && m_pRecordset->adoEOF)            
	{                                                           
		return;
	}
	m_pRecordset->MoveFirst();
	m_pRecordset->Move((long)nItem);
	m_pRecordset->PutCollect(_variant_t(_T("思想道德分")), 
		_variant_t(m_sixiang));
	m_pRecordset->PutCollect(_variant_t(_T("身心素质分")), 
		_variant_t(m_shenxin));
	m_pRecordset->PutCollect(_variant_t(_T("文化素质分")), 
		_variant_t(m_wenhua));
	m_pRecordset->PutCollect(_variant_t(_T("平均分")), 
		_variant_t(m_zhuanye));
	m_pRecordset->PutCollect(_variant_t(_T("综合成绩")), 
		_variant_t((float)m_sixiang*0.2+((float)m_shenxin+(float)m_wenhua)*0.1+m_zhuanye*0.6));
	m_pRecordset->Update();

	//读取记录集
	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
	{
		return ;
	}
	m_pRecordset->MoveFirst();
	int n = 0;
	while (!m_pRecordset->adoEOF)
	{
		_variant_t varValue;
		CString nName = _T("");
		int nNumber=0;
		int nsixiang=0;
		int nshenxin=0;
		int nwenhua=0;
		float nzhuanye=0;
		float nzonghe=0;

		varValue = m_pRecordset->GetCollect(_variant_t(_T("学号")));
		if (varValue.vt != VT_NULL)
		{
			nNumber = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("姓名")));
		if (varValue.vt != VT_NULL)
		{
			nName = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("思想道德分")));
		if (varValue.vt != VT_NULL)
		{
			nsixiang = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("身心素质分")));
		if (varValue.vt != VT_NULL)
		{
			nshenxin = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("文化素质分")));
		if (varValue.vt != VT_NULL)
		{
			nwenhua = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("平均分")));
		if (varValue.vt != VT_NULL)
		{
			nzhuanye = varValue.fltVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("综合成绩")));
		if (varValue.vt != VT_NULL)
		{
			nzonghe = varValue.fltVal;
		}

		//刷新ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1,strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%d"), nsixiang);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%d"), nshenxin);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%d"), nwenhua);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%f"), nzhuanye);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%f"), nzonghe);
		pListCtrl->SetItemText(n, 7, strText);
		n++;

		m_pRecordset->MoveNext();
	}
}

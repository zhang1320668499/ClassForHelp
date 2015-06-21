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

	//�����ݿ�
	CString strConnect = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source= classhelp.mdb");
	if (!OpenDatabase(strConnect))
	{
		AfxMessageBox(_T("���ݿ��ʧ�ܡ�"));
		return;
	}

	//�򿪼�¼��
	CString strSource = _T("SELECT * FROM �ɼ�����");
	if (!OpenRecordset(strSource))
	{
		AfxMessageBox(_T("��¼����ʧ�ܡ�"));
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
	
	//�����ݿ�����
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

	//�ر����ݿ�����
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

	//�򿪼�¼��
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

	//�رռ�¼��
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
	pListCtrl->InsertColumn(1, _T("���"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(2, _T("ѧ��"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(3, _T("����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(4, _T("˼����·�"), LVCFMT_CENTER, 100);
	pListCtrl->InsertColumn(5, _T("�������ʷ�"), LVCFMT_CENTER, 100);
	pListCtrl->InsertColumn(6, _T("�Ļ����ʷ�"), LVCFMT_CENTER, 100);
	pListCtrl->InsertColumn(7, _T("רҵ���ʷ�"), LVCFMT_CENTER, 100);
	pListCtrl->InsertColumn(8, _T("�ۺϳɼ�"), LVCFMT_CENTER, 100);
	//��ȡ��¼��
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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ѧ��")));
		if (varValue.vt != VT_NULL)
		{
			nNumber = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nName = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("˼����·�")));
		if (varValue.vt != VT_NULL)
		{
			nsixiang = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("�������ʷ�")));
		if (varValue.vt != VT_NULL)
		{
			nshenxin = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ļ����ʷ�")));
		if (varValue.vt != VT_NULL)
		{
			nwenhua = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ƽ����")));
		if (varValue.vt != VT_NULL)
		{
			nzhuanye = varValue.fltVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�ۺϳɼ�")));
		if (varValue.vt != VT_NULL)
		{
			nzonghe = varValue.fltVal;
		}

		//ˢ��ListCtrl
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
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

	//��ü�¼����ǰλ��
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		return;
	}
	int nItem = pListCtrl->GetNextSelectedItem(pos);
	//�޸ļ�¼��
	if (m_pRecordset->BOF && m_pRecordset->adoEOF)            
	{                                                           
		return;
	}
	m_pRecordset->MoveFirst();
	m_pRecordset->Move((long)nItem);
	m_pRecordset->PutCollect(_variant_t(_T("˼����·�")), 
		_variant_t(m_sixiang));
	m_pRecordset->PutCollect(_variant_t(_T("�������ʷ�")), 
		_variant_t(m_shenxin));
	m_pRecordset->PutCollect(_variant_t(_T("�Ļ����ʷ�")), 
		_variant_t(m_wenhua));
	m_pRecordset->PutCollect(_variant_t(_T("ƽ����")), 
		_variant_t(m_zhuanye));
	m_pRecordset->PutCollect(_variant_t(_T("�ۺϳɼ�")), 
		_variant_t((float)m_sixiang*0.2+((float)m_shenxin+(float)m_wenhua)*0.1+m_zhuanye*0.6));
	m_pRecordset->Update();

	//��ȡ��¼��
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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ѧ��")));
		if (varValue.vt != VT_NULL)
		{
			nNumber = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nName = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("˼����·�")));
		if (varValue.vt != VT_NULL)
		{
			nsixiang = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("�������ʷ�")));
		if (varValue.vt != VT_NULL)
		{
			nshenxin = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ļ����ʷ�")));
		if (varValue.vt != VT_NULL)
		{
			nwenhua = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ƽ����")));
		if (varValue.vt != VT_NULL)
		{
			nzhuanye = varValue.fltVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�ۺϳɼ�")));
		if (varValue.vt != VT_NULL)
		{
			nzonghe = varValue.fltVal;
		}

		//ˢ��ListCtrl
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

// Leave.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "Leave.h"
#include "AddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeave dialog


CLeave::CLeave(CWnd* pParent /*=NULL*/)
	: CDialog(CLeave::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeave)
		// NOTE: the ClassWizard will add member initialization here
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
	CString strSource = _T("SELECT * FROM ��ٹ���");
	if (!OpenRecordset(strSource))
	{
		AfxMessageBox(_T("��¼����ʧ�ܡ�"));
		return;
	}
}
CLeave::~CLeave()
{
	CloseRecordset();
	CloseDatabase();
}


void CLeave::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeave)
	DDX_Control(pDX, IDC_LIST1, m_ctrlList2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeave, CDialog)
	//{{AFX_MSG_MAP(CLeave)
	ON_BN_CLICKED(IDC_BUTTONADD, OnButtonadd)
	ON_BN_CLICKED(IDC_BUTTONDEL, OnButtondel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeave message handlers

BOOL CLeave::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	pListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	pListCtrl->InsertColumn(1, _T("���"), LVCFMT_CENTER, 80);
	pListCtrl->InsertColumn(2, _T("ѧ��"), LVCFMT_CENTER, 80);
	pListCtrl->InsertColumn(3, _T("����"), LVCFMT_CENTER, 80);
	pListCtrl->InsertColumn(4, _T("Ժϵ"), LVCFMT_CENTER, 80);
	pListCtrl->InsertColumn(5, _T("��ʼ"), LVCFMT_CENTER, 80);
	pListCtrl->InsertColumn(6, _T("����"), LVCFMT_CENTER, 80);
	pListCtrl->InsertColumn(7, _T("��ע"), LVCFMT_CENTER, 100);

	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
	{
		return FALSE;
	}
	m_pRecordset->MoveFirst();
	int n = 0;
	while (!m_pRecordset->adoEOF)
	{
		_variant_t varValue;
		CString nstrName = _T("");
		CString nstrUniver = _T("");
		CString nstrStartTime = _T("");
		CString nstrFinalTime = _T("");
		CString nstrBeizhu = _T("");
		int nAge = 0;
		int nstrNumber=0;

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ѧ��")));
		if (varValue.vt != VT_NULL)
		{
			nstrNumber = varValue.intVal;
		}
		else
		{
			nstrNumber = 0;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nstrName = varValue.bstrVal;
		}
		else
		{
			nstrName = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ժϵ")));
		if (varValue.vt != VT_NULL)
		{
			nstrUniver = varValue.bstrVal;
		}
		else
		{
			nstrUniver = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��ʼ")));
		if (varValue.vt != VT_NULL)
		{
			nstrStartTime = varValue.bstrVal;
		}
		else
		{
			nstrStartTime = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nstrFinalTime = varValue.bstrVal;
		}
		else
		{
			nstrFinalTime = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��ע")));
		if (varValue.vt != VT_NULL)
		{
			nstrBeizhu = varValue.bstrVal;
		}
		else
		{
			nstrBeizhu = _T("");
		}

		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nstrNumber);
		pListCtrl->SetItemText(n, 1, strText);
		strText.Format(_T("%s"), nstrName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), nstrUniver);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%s"), nstrStartTime);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%s"), nstrFinalTime);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%s"), nstrBeizhu);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%s"), nstrBeizhu);
		n++;

		m_pRecordset->MoveNext();
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}




void CLeave::OnButtonadd() 
{
	// TODO: Add your control notification handler code here
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

	CAddDlg dlg;
	if (dlg.DoModal() != IDOK)
	{
		return;
	}
	
	//��Ӽ�¼��
	m_pRecordset->AddNew();
	m_pRecordset->PutCollect(_variant_t(_T("ѧ��")), 
		_variant_t(dlg.m_strNumber3));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(dlg.m_strName3));
	m_pRecordset->PutCollect(_variant_t(_T("Ժϵ")), 
		_variant_t(dlg.m_strUniver3));
	m_pRecordset->PutCollect(_variant_t(_T("��ʼ")), 
		_variant_t(dlg.m_strStartTime));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(dlg.m_FinalTime));
	m_pRecordset->PutCollect(_variant_t(_T("��ע")), 
		_variant_t(dlg.m_strbeizhu));
	m_pRecordset->Update();

	//��ȡ��¼��
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	pListCtrl->DeleteAllItems();
	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
	{
		return;
	}
	m_pRecordset->MoveFirst();
	int n = 0;
	while (!m_pRecordset->adoEOF)
	{
		_variant_t varValue;
		CString nstrName = _T("");
		CString nstrUniver = _T("");
		CString nstrStartTime = _T("");
		CString nstrFinalTime = _T("");
		CString nstrBeizhu = _T("");
		int nAge = 0;
		int nstrNumber=0;

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ѧ��")));
		if (varValue.vt != VT_NULL)
		{
			nstrNumber = varValue.intVal;
		}
		else
		{
			nstrNumber = 0;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nstrName = varValue.bstrVal;
		}
		else
		{
			nstrName = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ժϵ")));
		if (varValue.vt != VT_NULL)
		{
			nstrUniver = varValue.bstrVal;
		}
		else
		{
			nstrUniver = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��ʼ")));
		if (varValue.vt != VT_NULL)
		{
			nstrStartTime = varValue.bstrVal;
		}
		else
		{
			nstrStartTime = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nstrFinalTime = varValue.bstrVal;
		}
		else
		{
			nstrFinalTime = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��ע")));
		if (varValue.vt != VT_NULL)
		{
			nstrBeizhu = varValue.bstrVal;
		}
		else
		{
			nstrBeizhu = _T("");
		}

		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nstrNumber);
		pListCtrl->SetItemText(n, 1, strText);
		strText.Format(_T("%s"), nstrName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), nstrUniver);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%s"), nstrStartTime);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%s"), nstrFinalTime);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%s"), nstrBeizhu);
		pListCtrl->SetItemText(n, 6, strText);
		n++;

		m_pRecordset->MoveNext();
	}
}
BOOL CLeave::OpenDatabase(LPCTSTR lpszConnect, long nOptions)
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

BOOL CLeave::CloseDatabase()
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

BOOL CLeave::OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions)
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

BOOL CLeave::CloseRecordset()
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

void CLeave::OnButtondel() 
{
	// TODO: Add your control notification handler code here
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
	
	//ɾ����¼��
	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
	{
		return;
	}
	m_pRecordset->MoveFirst();
	m_pRecordset->Move((long)nItem);
	m_pRecordset->Delete(adAffectCurrent);
	m_pRecordset->Update();

	//��ȡ��¼��
	pListCtrl->DeleteAllItems();
	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
	{
		return;
	}
	m_pRecordset->MoveFirst();
	int n = 0;
	while (!m_pRecordset->adoEOF)
	{
        _variant_t varValue;
		CString nstrName = _T("");
		CString nstrUniver = _T("");
		CString nstrStartTime = _T("");
		CString nstrFinalTime = _T("");
		CString nstrBeizhu = _T("");
		int nAge = 0;
		int nstrNumber=0;

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ѧ��")));
		if (varValue.vt != VT_NULL)
		{
			nstrNumber = varValue.intVal;
		}
		else
		{
			nstrNumber = 0;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nstrName = varValue.bstrVal;
		}
		else
		{
			nstrName = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ժϵ")));
		if (varValue.vt != VT_NULL)
		{
			nstrUniver = varValue.bstrVal;
		}
		else
		{
			nstrUniver = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��ʼ")));
		if (varValue.vt != VT_NULL)
		{
			nstrStartTime = varValue.bstrVal;
		}
		else
		{
			nstrStartTime = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nstrFinalTime = varValue.bstrVal;
		}
		else
		{
			nstrFinalTime = _T("");
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��ע")));
		if (varValue.vt != VT_NULL)
		{
			nstrBeizhu = varValue.bstrVal;
		}
		else
		{
			nstrBeizhu = _T("");
		}

		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nstrNumber);
		pListCtrl->SetItemText(n, 1, strText);
		strText.Format(_T("%s"), nstrName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), nstrUniver);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%s"), nstrStartTime);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%s"), nstrFinalTime);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%s"), nstrBeizhu);
		pListCtrl->SetItemText(n, 6, strText);
		n++;

		m_pRecordset->MoveNext();
	}
	
}

// DataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "DataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog


CDataDlg::CDataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataDlg)
	m_str_name = _T("");
	m_strUniver = _T("");
	m_strPro = _T("");
	m_strNumber = _T("");
	m_strAge = _T("");
	m_strSex = _T("");
	m_strMajor = _T("");
	m_strTel = _T("");
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
	CString strSource = _T("SELECT * FROM �༶��Ա��Ϣ");
	if (!OpenRecordset(strSource))
	{
		AfxMessageBox(_T("��¼����ʧ�ܡ�"));
		return;
	}

}
CDataDlg::~CDataDlg()
{
	CloseRecordset();
	CloseDatabase();
}


void CDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataDlg)
	DDX_Control(pDX, IDC_LIST, m_ctrlList);
	DDX_Text(pDX, IDC_EDIT_NAME, m_str_name);
	DDX_Text(pDX, IDC_EDIT_Univer, m_strUniver);
	DDX_Text(pDX, IDC_EDIT_pro, m_strPro);
	DDX_Text(pDX, IDC_EDIT_NUMBER, m_strNumber);
	DDX_Text(pDX, IDC_EDIT_age, m_strAge);
	DDX_CBString(pDX, IDC_COMBO_SEX, m_strSex);
	DDX_Text(pDX, IDC_EDIT_Major, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_tel, m_strTel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataDlg, CDialog)
	//{{AFX_MSG_MAP(CDataDlg)
	ON_BN_CLICKED(IDC_BUTTON_baocun, OnBUTTONbaocun)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_edit, OnBUTTONedit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataDlg message handlers

BOOL CDataDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST);
	pListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	pListCtrl->InsertColumn(1, _T("���"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(2, _T("ѧ��"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(3, _T("����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(4, _T("�Ա�"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(5, _T("����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(6, _T("����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(7, _T("Ժϵ"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(8, _T("רҵ"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(9, _T("�绰"), LVCFMT_CENTER, 100);
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
		CString nSex = _T("");
		CString nPro = _T("");
		CString nUniver = _T("");
		CString nMajor = _T("");
		CString nTel = _T("");
		int nAge = 0;
		int nNumber=0;

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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ա�")));
		if (varValue.vt != VT_NULL)
		{
			nSex = varValue.bstrVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nAge = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nPro = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ժϵ")));
		if (varValue.vt != VT_NULL)
		{
			nUniver = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("רҵ")));
		if (varValue.vt != VT_NULL)
		{
			nMajor = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�绰")));
		if (varValue.vt != VT_NULL)
		{
			nTel = varValue.bstrVal;
		}



		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1,strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), nSex);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%d"), nAge);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%s"), nPro);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%s"), nUniver);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%s"), nMajor);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%s"), nTel);
		pListCtrl->SetItemText(n, 8, strText);
		n++;

		m_pRecordset->MoveNext();
	}

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDataDlg::OnBUTTONbaocun() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_str_name.IsEmpty())
	{
		AfxMessageBox((_T("��������Ϊ�ա�")));
		return;
	}
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}
	
	//��Ӽ�¼��
	m_pRecordset->AddNew();
	m_pRecordset->PutCollect(_variant_t(_T("ѧ��")), 
		_variant_t(m_strNumber));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(m_str_name));
	m_pRecordset->PutCollect(_variant_t(_T("�Ա�")), 
		_variant_t(m_strSex));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(m_strAge));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(m_strPro));
	m_pRecordset->PutCollect(_variant_t(_T("Ժϵ")), 
		_variant_t(m_strUniver));
	m_pRecordset->PutCollect(_variant_t(_T("רҵ")), 
		_variant_t(m_strMajor));
	m_pRecordset->PutCollect(_variant_t(_T("�绰")), 
		_variant_t(m_strTel));

	m_pRecordset->Update();

	//��ȡ��¼��
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST);
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
		CString nName = _T("");
		CString nSex = _T("");
		CString nPro = _T("");
		CString nUniver = _T("");
		CString nMajor = _T("");
		CString nTel = _T("");
		int nAge = 0;
		int nNumber=0;
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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ա�")));
		if (varValue.vt != VT_NULL)
		{
			nSex = varValue.bstrVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nAge = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nPro = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ժϵ")));
		if (varValue.vt != VT_NULL)
		{
			nUniver = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("רҵ")));
		if (varValue.vt != VT_NULL)
		{
			nMajor = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�绰")));
		if (varValue.vt != VT_NULL)
		{
			nTel = varValue.bstrVal;
		}



		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1, strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), nSex);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%d"), nAge);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%s"), nPro);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%s"), nUniver);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%s"), nMajor);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%s"), nTel);
		pListCtrl->SetItemText(n, 8, strText);
		n++;

		m_pRecordset->MoveNext();
	}

}
BOOL CDataDlg::OpenDatabase(LPCTSTR lpszConnect, long nOptions)
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

BOOL CDataDlg::CloseDatabase()
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

BOOL CDataDlg::OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions)
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

BOOL CDataDlg::CloseRecordset()
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

void CDataDlg::OnButtonDel() 
{
	// TODO: Add your control notification handler code here
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

	//��ü�¼����ǰλ��
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST);
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
		CString nName = _T("");
		CString nSex = _T("");
		CString nPro = _T("");
		CString nUniver = _T("");
		CString nMajor = _T("");
		CString nTel = _T("");
		int nAge = 0;
		int nNumber=0;
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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ա�")));
		if (varValue.vt != VT_NULL)
		{
			nSex = varValue.bstrVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nAge = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nPro = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ժϵ")));
		if (varValue.vt != VT_NULL)
		{
			nUniver = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("רҵ")));
		if (varValue.vt != VT_NULL)
		{
			nMajor = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�绰")));
		if (varValue.vt != VT_NULL)
		{
			nTel = varValue.bstrVal;
		}



		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1,strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), nSex);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%d"), nAge);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%s"), nPro);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%s"), nUniver);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%s"), nMajor);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%s"), nTel);
		pListCtrl->SetItemText(n, 8, strText);
		n++;

		m_pRecordset->MoveNext();
	}
	
}

void CDataDlg::OnBUTTONedit() 
{
	// TODO: Add your control notification handler code here
	//��������
	UpdateData(TRUE);
	if (m_str_name.IsEmpty())
	{
		AfxMessageBox((_T("��������Ϊ�ա�")));
		return;
	}
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

	//��ü�¼����ǰλ��
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST);
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
	m_pRecordset->PutCollect(_variant_t(_T("ѧ��")), 
		_variant_t(m_strNumber));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(m_str_name));
	m_pRecordset->PutCollect(_variant_t(_T("�Ա�")), 
		_variant_t(m_strSex));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(m_strAge));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(m_strPro));
	m_pRecordset->PutCollect(_variant_t(_T("Ժϵ")), 
		_variant_t(m_strUniver));
	m_pRecordset->PutCollect(_variant_t(_T("רҵ")), 
		_variant_t(m_strMajor));
	m_pRecordset->PutCollect(_variant_t(_T("�绰")), 
		_variant_t(m_strTel));
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
		CString nName = _T("");
		CString nSex = _T("");
		CString nPro = _T("");
		CString nUniver = _T("");
		CString nMajor = _T("");
		CString nTel = _T("");
		int nAge = 0;
		int nNumber=0;
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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ա�")));
		if (varValue.vt != VT_NULL)
		{
			nSex = varValue.bstrVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nAge = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nPro = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ժϵ")));
		if (varValue.vt != VT_NULL)
		{
			nUniver = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("רҵ")));
		if (varValue.vt != VT_NULL)
		{
			nMajor = varValue.bstrVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�绰")));
		if (varValue.vt != VT_NULL)
		{
			nTel = varValue.bstrVal;
		}



		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1, strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), nSex);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%d"), nAge);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%s"), nPro);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%s"), nUniver);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%s"), nMajor);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%d"), nTel);
		pListCtrl->SetItemText(n, 8, strText);
		n++;

		m_pRecordset->MoveNext();
	}
	
}


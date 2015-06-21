// Dorm1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "Dorm1Dlg.h"
#include "Add2Dlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDorm1Dlg dialog


CDorm1Dlg::CDorm1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDorm1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDorm1Dlg)
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
	CString strSource = _T("SELECT * FROM ���ҹ���");
	if (!OpenRecordset(strSource))
	{
		AfxMessageBox(_T("��¼����ʧ�ܡ�"));
		return;
	}
}


void CDorm1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDorm1Dlg)
	DDX_Control(pDX, IDC_LIST2, m_ctrlList4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDorm1Dlg, CDialog)
	//{{AFX_MSG_MAP(CDorm1Dlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDorm1Dlg message handlers

void CDorm1Dlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
		if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

	CAdd2Dlg dlg;
	if (dlg.DoModal() != IDOK)
	{
		return;
	}
	
	//��Ӽ�¼��
	m_pRecordset->AddNew();
	m_pRecordset->PutCollect(_variant_t(_T("ѧ��")), 
		_variant_t(dlg.m_Xuehao));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(dlg.m_Xingming));
	m_pRecordset->PutCollect(_variant_t(_T("�Ա�")), 
		_variant_t(dlg.m_Xingbie));
	m_pRecordset->PutCollect(_variant_t(_T("¥��")), 
		_variant_t(dlg.m_Louhao));
	m_pRecordset->PutCollect(_variant_t(_T("רҵ")), 
		_variant_t(dlg.m_Zhuanye));
	m_pRecordset->PutCollect(_variant_t(_T("���Һ�")), 
		_variant_t(dlg.m_Qinshihao));
	m_pRecordset->PutCollect(_variant_t(_T("��λ��")), 
		_variant_t(dlg.m_Chuangweihao));
	m_pRecordset->PutCollect(_variant_t(_T("��ע")), 
		_variant_t(dlg.m_Beizhu));
	m_pRecordset->Update();

	//��ȡ��¼��
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
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
		CString strName = _T("");
		CString xingbie = _T("");
		CString beizhu = _T("");
		CString zhuanye = _T("");
		int xuehao=0;
		int louhao=0;
		int qinshihao=0;
		int chuangweihao=0;

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ѧ��")));
		if (varValue.vt != VT_NULL)
		{
			xuehao = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			strName = varValue.bstrVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ա�")));
		if (varValue.vt != VT_NULL)
		{
			xingbie = varValue.bstrVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("רҵ")));
		if (varValue.vt != VT_NULL)
		{
			zhuanye = varValue.bstrVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("¥��")));
		if (varValue.vt != VT_NULL)
		{
			louhao = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("���Һ�")));
		if (varValue.vt != VT_NULL)
		{
			qinshihao = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��λ��")));
		if (varValue.vt != VT_NULL)
		{
			chuangweihao = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��ע")));
		if (varValue.vt != VT_NULL)
		{
			beizhu = varValue.bstrVal;
		}

		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), xuehao);
		pListCtrl->SetItemText(n, 1, strText);
		strText.Format(_T("%s"), strName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), xingbie);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%s"), zhuanye);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%d"), louhao);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%d"), qinshihao);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%d"), chuangweihao);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%s"), beizhu);
		pListCtrl->SetItemText(n, 8, strText);
		n++;

		m_pRecordset->MoveNext();
	}
 
}

BOOL CDorm1Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
	pListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	pListCtrl->InsertColumn(1, _T("���"), LVCFMT_CENTER, 80);
	pListCtrl->InsertColumn(2, _T("ѧ��"), LVCFMT_CENTER, 80);
	pListCtrl->InsertColumn(3, _T("����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(4, _T("�Ա�"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(5, _T("רҵ"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(6, _T("¥��"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(7, _T("���Һ�"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(8, _T("��λ��"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(9, _T("��ע"), LVCFMT_CENTER, 160);
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
		CString strName = _T("");
		CString xingbie = _T("");
		CString beizhu = _T("");
		int nAge = 0;
		int xuehao=0;
		int louhao=0;
		int qinshihao=0;
		int chuangweihao=0;

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ѧ��")));
		if (varValue.vt != VT_NULL)
		{
			xuehao = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			strName = varValue.bstrVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ա�")));
		if (varValue.vt != VT_NULL)
		{
			xingbie = varValue.bstrVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("¥��")));
		if (varValue.vt != VT_NULL)
		{
			louhao = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("���Һ�")));
		if (varValue.vt != VT_NULL)
		{
			qinshihao = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��λ��")));
		if (varValue.vt != VT_NULL)
		{
			chuangweihao = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��ע")));
		if (varValue.vt != VT_NULL)
		{
			beizhu = varValue.bstrVal;
		}






		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), xuehao);
		pListCtrl->SetItemText(n, 1, strText);
		strText.Format(_T("%s"), strName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), xingbie);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%d"), louhao);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%d"), qinshihao);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%d"), chuangweihao);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%s"), beizhu);
		pListCtrl->SetItemText(n, 7, strText);
		n++;

		m_pRecordset->MoveNext();
	}
	

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CDorm1Dlg::OnButtonDel() 
{
	// TODO: Add your control notification handler code here
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

	//��ü�¼����ǰλ��
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
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
		CString strName = _T("");
		CString xingbie = _T("");
		CString beizhu = _T("");
		CString zhuanye = _T("");
		int xuehao=0;
		int louhao=0;
		int qinshihao=0;
		int chuangweihao=0;

		varValue = m_pRecordset->GetCollect(_variant_t(_T("ѧ��")));
		if (varValue.vt != VT_NULL)
		{
			xuehao = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			strName = varValue.bstrVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ա�")));
		if (varValue.vt != VT_NULL)
		{
			xingbie = varValue.bstrVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("רҵ")));
		if (varValue.vt != VT_NULL)
		{
			zhuanye = varValue.bstrVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("¥��")));
		if (varValue.vt != VT_NULL)
		{
			louhao = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("���Һ�")));
		if (varValue.vt != VT_NULL)
		{
			qinshihao = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��λ��")));
		if (varValue.vt != VT_NULL)
		{
			chuangweihao = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("��ע")));
		if (varValue.vt != VT_NULL)
		{
			beizhu = varValue.bstrVal;
		}

		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), xuehao);
		pListCtrl->SetItemText(n, 1, strText);
		strText.Format(_T("%s"), strName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%s"), xingbie);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%s"), zhuanye);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%d"), louhao);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%d"), qinshihao);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%d"), chuangweihao);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%s"), beizhu);
		pListCtrl->SetItemText(n, 8, strText);
		n++;

		m_pRecordset->MoveNext();
	}
	
}

void CDorm1Dlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	
	
}
CDorm1Dlg::~CDorm1Dlg()
{
	CloseRecordset();
	CloseDatabase();
}
BOOL CDorm1Dlg::CloseDatabase()
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

BOOL CDorm1Dlg::OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions)
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

BOOL CDorm1Dlg::CloseRecordset()
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
BOOL CDorm1Dlg::OpenDatabase(LPCTSTR lpszConnect, long nOptions)
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

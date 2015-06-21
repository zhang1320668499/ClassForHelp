// Score.cpp : implementation file
//

#include "stdafx.h"
#include "software.h"
#include "Score.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScore dialog


CScore::CScore(CWnd* pParent /*=NULL*/)
	: CDialog(CScore::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScore)
	m_strxingming = _T("");
	m_longgaoshu = 0;
	m_longxuehao = 0;
	m_longjindaishi = 0;
	m_longyuwen = 0;
	m_longcyuyan = 0;
	m_longjidao = 0;
	m_longyinyu = 0;
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


void CScore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScore)
	DDX_Control(pDX, IDC_LIST1, m_ctrlList1);
	DDX_Text(pDX, IDC_EDIT1, m_strxingming);
	DDX_Text(pDX, IDC_EDIT3, m_longgaoshu);
	DDX_Text(pDX, IDC_EDIT2, m_longxuehao);
	DDX_Text(pDX, IDC_EDIT11, m_longjindaishi);
	DDX_Text(pDX, IDC_EDIT10, m_longyuwen);
	DDX_Text(pDX, IDC_EDIT5, m_longcyuyan);
	DDX_Text(pDX, IDC_EDIT6, m_longjidao);
	DDX_Text(pDX, IDC_EDIT9, m_longyinyu);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScore, CDialog)
	//{{AFX_MSG_MAP(CScore)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScore message handlers

BOOL CScore::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	pListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	pListCtrl->InsertColumn(1, _T("���"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(2, _T("ѧ��"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(3, _T("����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(4, _T("�ܷ�"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(5, _T("ƽ����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(6, _T("����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(7, _T("c����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(8, _T("�Ƶ�"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(9, _T("Ӣ��"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(10, _T("����"), LVCFMT_CENTER, 65);
	pListCtrl->InsertColumn(11, _T("����ʷ"), LVCFMT_CENTER, 65);
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
		int nZongfen=0;
	float nPingjunfen=0;
		int nGaoshu=0;
		int nCyuyan=0;
		int nJidao=0;
		int nYinyu=0;
		int nYuwen=0;
		int nJindaishi=0;

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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�ܷ�")));
		if (varValue.vt != VT_NULL)
		{
			nZongfen = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("ƽ����")));
		if (varValue.vt != VT_NULL)
		{
			nPingjunfen = varValue.fltVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nGaoshu = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("c����")));
		if (varValue.vt != VT_NULL)
		{
			nCyuyan = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ƶ�")));
		if (varValue.vt != VT_NULL)
		{
			nJidao = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ӣ��")));
		if (varValue.vt != VT_NULL)
		{
			nYinyu = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nYuwen = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����ʷ")));
		if (varValue.vt != VT_NULL)
		{
			nJindaishi = varValue.intVal;
		}



		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1,strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%d"), nZongfen);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%f"), nPingjunfen);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%d"), nGaoshu);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%d"), nCyuyan);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%d"), nJidao);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%d"), nYinyu);
		pListCtrl->SetItemText(n, 8, strText);
		strText.Format(_T("%d"), nYuwen);
		pListCtrl->SetItemText(n, 9, strText);
		strText.Format(_T("%d"), nJindaishi);
		pListCtrl->SetItemText(n, 10, strText);
		n++;

		m_pRecordset->MoveNext();
	}

	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
BOOL CScore::OpenDatabase(LPCTSTR lpszConnect, long nOptions)
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

BOOL CScore::CloseDatabase()
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

BOOL CScore::OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions)
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

BOOL CScore::CloseRecordset()
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
CScore::~CScore()
{
	CloseRecordset();
	CloseDatabase();
}

void CScore::OnButton3() 
{
	// TODO: Add your control notification handler code here
	float SUM;
	UpdateData(TRUE);
	if (m_strxingming.IsEmpty())
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
		_variant_t((long)m_longxuehao));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(m_strxingming));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t((long)m_longgaoshu));
	m_pRecordset->PutCollect(_variant_t(_T("c����")), 
		_variant_t((long)m_longcyuyan));
	m_pRecordset->PutCollect(_variant_t(_T("�Ƶ�")), 
		_variant_t((long)m_longjidao));
	m_pRecordset->PutCollect(_variant_t(_T("Ӣ��")), 
		_variant_t((long)m_longyinyu));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
	    _variant_t((long)m_longyuwen));
	m_pRecordset->PutCollect(_variant_t(_T("����ʷ")), 
	    _variant_t((long)m_longjindaishi));
	m_pRecordset->PutCollect(_variant_t(_T("�ܷ�")), 
		_variant_t((long)m_longgaoshu+(long)m_longcyuyan+(long)m_longjidao+(long)m_longyinyu+(long)m_longyuwen+(long)m_longjindaishi));
	m_pRecordset->PutCollect(_variant_t(_T("ƽ����")), 
		_variant_t(((float)m_longgaoshu+(float)m_longcyuyan+(float)m_longjidao+(float)m_longyinyu+(float)m_longyuwen+(float)m_longjindaishi)/6));
	SUM=((float)m_longgaoshu+(float)m_longcyuyan+(float)m_longjidao+(float)m_longyinyu+(float)m_longyuwen+(float)m_longjindaishi)/6;
	m_pRecordset->PutCollect(_variant_t(_T("�������ʷ�")), 
	    _variant_t((long)78));
	m_pRecordset->PutCollect(_variant_t(_T("˼����·�")), 
	    _variant_t((long)78));
    m_pRecordset->PutCollect(_variant_t(_T("�Ļ����ʷ�")), 
	    _variant_t((long)78));
	m_pRecordset->PutCollect(_variant_t(_T("�ۺϳɼ�")), 
	    _variant_t(SUM*0.6+(float)78*0.4));





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
		CString nName = _T("");
		int nNumber=0;
		int nZongfen=0;
		float nPingjunfen=0;
		int nGaoshu=0;
		int nCyuyan=0;
		int nJidao=0;
		int nYinyu=0;
		int nYuwen=0;
		int nJindaishi=0;

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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�ܷ�")));
		if (varValue.vt != VT_NULL)
		{
			nZongfen = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("ƽ����")));
		if (varValue.vt != VT_NULL)
		{
			nPingjunfen = varValue.fltVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nGaoshu = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("c����")));
		if (varValue.vt != VT_NULL)
		{
			nCyuyan = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ƶ�")));
		if (varValue.vt != VT_NULL)
		{
			nJidao = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ӣ��")));
		if (varValue.vt != VT_NULL)
		{
			nYinyu = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nYuwen = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����ʷ")));
		if (varValue.vt != VT_NULL)
		{
			nJindaishi = varValue.intVal;
		}



		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1,strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%d"), nZongfen);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%f"), nPingjunfen);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%d"), nGaoshu);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%d"), nCyuyan);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%d"), nJidao);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%d"), nYinyu);
		pListCtrl->SetItemText(n, 8, strText);
		strText.Format(_T("%d"), nYuwen);
		pListCtrl->SetItemText(n, 9, strText);
		strText.Format(_T("%d"), nJindaishi);
		pListCtrl->SetItemText(n, 10, strText);
		n++;

		m_pRecordset->MoveNext();
	}

	
}

void CScore::OnButton9() 
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
		CString nName = _T("");
		int nNumber=0;
		int nZongfen=0;
		float nPingjunfen=0;
		int nGaoshu=0;
		int nCyuyan=0;
		int nJidao=0;
		int nYinyu=0;
		int nYuwen=0;
		int nJindaishi=0;

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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�ܷ�")));
		if (varValue.vt != VT_NULL)
		{
			nZongfen = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("ƽ����")));
		if (varValue.vt != VT_NULL)
		{
			nPingjunfen = varValue.fltVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nGaoshu = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("c����")));
		if (varValue.vt != VT_NULL)
		{
			nCyuyan = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ƶ�")));
		if (varValue.vt != VT_NULL)
		{
			nJidao = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ӣ��")));
		if (varValue.vt != VT_NULL)
		{
			nYinyu = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nYuwen = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����ʷ")));
		if (varValue.vt != VT_NULL)
		{
			nJindaishi = varValue.intVal;
		}
		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1,strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%d"), nZongfen);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%f"), nPingjunfen);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%d"), nGaoshu);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%d"), nCyuyan);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%d"), nJidao);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%d"), nYinyu);
		pListCtrl->SetItemText(n, 8, strText);
		strText.Format(_T("%d"), nYuwen);
		pListCtrl->SetItemText(n, 9, strText);
		strText.Format(_T("%d"), nJindaishi);
		pListCtrl->SetItemText(n, 10, strText);
		n++;

		m_pRecordset->MoveNext();
	}

}

void CScore::OnButton6() 
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
    m_pRecordset->PutCollect(_variant_t(_T("ѧ��")), 
		_variant_t((long)m_longxuehao));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t(m_strxingming));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
		_variant_t((long)m_longgaoshu));
	m_pRecordset->PutCollect(_variant_t(_T("c����")), 
		_variant_t((long)m_longcyuyan));
	m_pRecordset->PutCollect(_variant_t(_T("�Ƶ�")), 
		_variant_t((long)m_longjidao));
	m_pRecordset->PutCollect(_variant_t(_T("Ӣ��")), 
		_variant_t((long)m_longyinyu));
	m_pRecordset->PutCollect(_variant_t(_T("����")), 
	    _variant_t((long)m_longyuwen));
	m_pRecordset->PutCollect(_variant_t(_T("����ʷ")), 
	    _variant_t((long)m_longjindaishi));
	m_pRecordset->PutCollect(_variant_t(_T("�ܷ�")), 
		_variant_t((long)m_longgaoshu+(long)m_longcyuyan+(long)m_longjidao+(long)m_longyinyu+(long)m_longyuwen+(long)m_longjindaishi));
	m_pRecordset->PutCollect(_variant_t(_T("ƽ����")), 
		_variant_t(((float)m_longgaoshu+(float)m_longcyuyan+(float)m_longjidao+(float)m_longyinyu+(float)m_longyuwen+(float)m_longjindaishi)/6));
	
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
		int nZongfen=0;
		float nPingjunfen=0;
		int nGaoshu=0;
		int nCyuyan=0;
		int nJidao=0;
		int nYinyu=0;
		int nYuwen=0;
		int nJindaishi=0;

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

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�ܷ�")));
		if (varValue.vt != VT_NULL)
		{
			nZongfen = varValue.intVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("ƽ����")));
		if (varValue.vt != VT_NULL)
		{
			nPingjunfen = varValue.fltVal;
		}
	
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nGaoshu = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("c����")));
		if (varValue.vt != VT_NULL)
		{
			nCyuyan = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("�Ƶ�")));
		if (varValue.vt != VT_NULL)
		{
			nJidao = varValue.intVal;
		}

		varValue = m_pRecordset->GetCollect(_variant_t(_T("Ӣ��")));
		if (varValue.vt != VT_NULL)
		{
			nYinyu = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����")));
		if (varValue.vt != VT_NULL)
		{
			nYuwen = varValue.intVal;
		}
		varValue = m_pRecordset->GetCollect(_variant_t(_T("����ʷ")));
		if (varValue.vt != VT_NULL)
		{
			nJindaishi = varValue.intVal;
		}
		//ˢ��ListCtrl
		CString strText = _T("");
		strText.Format(_T("%d"), n + 1);
		pListCtrl->InsertItem(n, strText);
		strText.Format(_T("%d"), nNumber);
		pListCtrl->SetItemText(n, 1,strText);
		strText.Format(_T("%s"), nName);
		pListCtrl->SetItemText(n, 2, strText);
		strText.Format(_T("%d"), nZongfen);
		pListCtrl->SetItemText(n, 3, strText);
		strText.Format(_T("%f"), nPingjunfen);
		pListCtrl->SetItemText(n, 4, strText);
		strText.Format(_T("%d"), nGaoshu);
		pListCtrl->SetItemText(n, 5, strText);
		strText.Format(_T("%d"), nCyuyan);
		pListCtrl->SetItemText(n, 6, strText);
		strText.Format(_T("%d"), nJidao);
		pListCtrl->SetItemText(n, 7, strText);
		strText.Format(_T("%d"), nYinyu);
		pListCtrl->SetItemText(n, 8, strText);
		strText.Format(_T("%d"), nYuwen);
		pListCtrl->SetItemText(n, 9, strText);
		strText.Format(_T("%d"), nJindaishi);
		pListCtrl->SetItemText(n, 10, strText);
		n++;

		m_pRecordset->MoveNext();
	}
}

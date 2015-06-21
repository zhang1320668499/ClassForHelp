// MyRecordSet.h: interface for the MyRecordSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYRECORDSET_H__9C33E515_02BF_473A_A24F_6C95E089C29E__INCLUDED_)
#define AFX_MYRECORDSET_H__9C33E515_02BF_473A_A24F_6C95E089C29E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MyRecordSet  
{
public:
	CString GetFieldName(int nCol);
	bool ADOEOF();
	void ADOConnectionClose();
	
	int nFieldCols;

	int nFieldRows;

	CString GetFieldString(int nCol);				
	CString GetFieldString(CString strFieldName);	
	int GetFieldNumber(int nCol);				
	int GetFieldNumber(CString strFieldName);
	float GetFieldFloat(int nCol);				
	float GetFieldFloat(CString strField);
	CString VariantToCString(VARIANT var);	

	CString TimeToString(CTime time);
	CTime	StringToTime(CString s);

	HRESULT MoveNext();
	HRESULT MovePrev();
	HRESULT MoveLast();
	HRESULT MoveFirst();
	MyRecordSet();

	bool ADOOpen(CString strDataType);
	bool ADOOpen();
	bool ADOExcute();				
	bool ADOExcute(CString strSQL);	

	int	 ADOExcuteNoQuery(CString strSQL);

	void ADOClose();

	_ConnectionPtr m_pConn;		
	_RecordsetPtr m_pRst;		

	CString		m_strSQL;				
	CString		m_strDBType;			
	bool		isConn;				
	bool		isOpen;				

	virtual ~MyRecordSet();

};

#endif // !defined(AFX_MYRECORDSET_H__9C33E515_02BF_473A_A24F_6C95E089C29E__INCLUDED_)

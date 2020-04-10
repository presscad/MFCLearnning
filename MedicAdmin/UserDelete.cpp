// UserDelete.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserDelete.h"
#include "afxdialogex.h"



// CUserDelete �Ի���

IMPLEMENT_DYNAMIC(CUserDelete, CDialogEx)

CUserDelete::CUserDelete(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_userCount(_T(""))
{

}

CUserDelete::~CUserDelete()
{
}

void CUserDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_userType);
	DDX_Text(pDX, IDC_EDIT1, m_userCount);
	DDX_Control(pDX, IDC_LIST1, m_listUser);
}


BEGIN_MESSAGE_MAP(CUserDelete, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CUserDelete::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDelete::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDelete::OnBnClickedButton1)
END_MESSAGE_MAP()


// CUserDelete ��Ϣ��������


void CUserDelete::OnOK()
{
	// TODO: �ڴ�����ר�ô����/����û���

	//CDialogEx::OnOK();
}


BOOL CUserDelete::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	m_userType.InsertString(0, TEXT("����Ա"));
	m_userType.InsertString(1, TEXT("ҽ��"));
	m_userType.InsertString(2, TEXT("��ҩԱ"));
	m_userType.SetCurSel(0);

	CString type;
	m_userType.GetLBText(m_userType.GetCurSel(), type);

	m_listUser.SetExtendedStyle(m_listUser.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	CString head[] = {
		TEXT("�û����"),TEXT("�û��˺�"),TEXT("�û�����"),TEXT("�û�����") };

	int n = sizeof(head) / sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		m_listUser.InsertColumn(i, head[i], LVCFMT_CENTER, 80);
	}

	CString initSqlFilter;
	initSqlFilter.Format(TEXT("classification='%s'"), type);
	if (m_userSet.IsOpen() == FALSE) {
		m_userSet.Open(CRecordset::dynaset);
	}
	m_userSet.m_strFilter = initSqlFilter;
	m_userSet.Requery();

	m_userSet.MoveFirst();

	int i = 0;
	while (!m_userSet.IsEOF()) {
		m_listUser.InsertItem(i, CString(m_userSet.m_classification));
		int j = 1;
		m_listUser.SetItemText(i, j++, CString(m_userSet.m_account));
		m_listUser.SetItemText(i, j++, CString(m_userSet.m_name));
		m_listUser.SetItemText(i, j++, CString(m_userSet.m_password));
		i++;
		m_userSet.MoveNext();
	}




	//CString filter = TEXT("classification='%s' and account='%s'", type, m_userCount);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CUserDelete::OnCbnSelchangeCombo1()
{
	CString type;
	m_userType.GetLBText(m_userType.GetCurSel(), type);

	CString initSqlFilter;
	initSqlFilter.Format(TEXT("classification='%s'"), type);
	if (m_userSet.IsOpen() == FALSE) {
		m_userSet.Open(CRecordset::dynaset);
	}

	m_listUser.DeleteAllItems();

	m_userSet.m_strFilter = initSqlFilter;

	m_userSet.Requery();

	m_userSet.MoveFirst();

	int i = 0;
	while (!m_userSet.IsEOF()) {
		m_listUser.InsertItem(i, CString(m_userSet.m_classification));
		int j = 1;
		m_listUser.SetItemText(i, j++, CString(m_userSet.m_account));
		m_listUser.SetItemText(i, j++, CString(m_userSet.m_name));
		m_listUser.SetItemText(i, j++, CString(m_userSet.m_password));
		i++;
		m_userSet.MoveNext();
	}
}

//�˳�
void CUserDelete::OnBnClickedButton2()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������

	CDialogEx::OnOK();

}

//�h���Ñ�
void CUserDelete::OnBnClickedButton1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(TRUE);

	if (m_userSet.IsOpen() == FALSE) {
		m_userSet.Open(CRecordset::dynaset);
	}
	if (!m_userCount.IsEmpty()) {

		CString sql;
		sql.Format(TEXT("account='%s'"), m_userCount);

		m_userSet.m_strFilter = sql;
		int deleteIndex = -1;
		for (int i = 0; i < m_listUser.GetItemCount(); i++)
		{

			CString tempAccount = m_listUser.GetItemText(i, 1);

			if (tempAccount.Compare(m_userCount) == 0) {

				m_listUser.SetCheck(i, TRUE);
				deleteIndex = i;
				break;
			}
		}

		if (deleteIndex != -1 &&
			MessageBox(TEXT("ȷ��ɾ����"), TEXT("ɾ���û�"), MB_OKCANCEL) == IDOK) {

			m_userSet.m_strFilter = sql;
			m_userSet.Requery();
			m_userSet.Delete();

			MessageBox(TEXT("ɾ���ɹ�"));
			m_listUser.DeleteItem(deleteIndex);

		}
	}
	else
	{
		CString delSql = TEXT("account in (");

		CList<int> listInt;

		for (int i = 0; i < m_listUser.GetItemCount(); i++)
		{
			BOOL isCheck = m_listUser.GetCheck(i);

			if (isCheck) {

				CString tempAccount = m_listUser.GetItemText(i, 1);
				CString del;

				del.Format(TEXT(" '%s' ,"), tempAccount);

				delSql += del;

				listInt.AddTail(i);
			}
			
		}
		delSql += TEXT("' ')");
		m_userSet.m_strFilter = delSql;

		m_userSet.Requery();
		while (!m_userSet.IsEOF())
		{
			m_userSet.Delete();
			m_userSet.MoveNext();
		}
		MessageBox(TEXT("ɾ���ɹ�"));

		POSITION pos = listInt.GetHeadPosition();

		int n = 0;
		while (pos != NULL) {

			int m = listInt.GetAt(pos);

			m_listUser.DeleteItem(m - n++);

			listInt.GetNext(pos);
		}
	}

}
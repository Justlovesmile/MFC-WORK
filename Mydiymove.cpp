// Mydiymove.cpp : implementation file
//

#include "stdafx.h"
#include "Group4.h"
#include "Mydiymove.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Mydiymove dialog


Mydiymove::Mydiymove(CWnd* pParent /*=NULL*/)
	: CDialog(Mydiymove::IDD, pParent)
{
	//{{AFX_DATA_INIT(Mydiymove)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Mydiymove::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Mydiymove, CDialog)
	//{{AFX_MSG_MAP(Mydiymove)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO1, OnSetfocusCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Mydiymove message handlers

void Mydiymove::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CComboBox m_combo;
	m_combo.ResetContent();
	m_combo.AddString("上移");
	m_combo.AddString("下移");
	m_combo.AddString("左移");
	m_combo.AddString("右移");
	m_combo.SetCurSel(-1);
}

void Mydiymove::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	//获得当前选择的列表项索引
	CComboBox m_combo;
	int nIndex = m_combo.GetCurSel();
	CString strCBText;
	//根据指定的索引获得该项的数据
	m_combo.GetLBText( nIndex, strCBText);
	MessageBox(strCBText);
}

void Mydiymove::OnSetfocusCombo1() 
{
	// TODO: Add your control notification handler code here

}

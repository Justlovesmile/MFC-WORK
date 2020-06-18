// movetype.cpp : implementation file
//

#include "stdafx.h"
#include "Group4.h"
#include "movetype.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// movetype dialog


movetype::movetype(CWnd* pParent /*=NULL*/)
	: CDialog(movetype::IDD, pParent)
{
	//{{AFX_DATA_INIT(movetype)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void movetype::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(movetype)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(movetype, CDialog)
	//{{AFX_MSG_MAP(movetype)
	ON_CBN_EDITCHANGE(IDC_COMBO2, OnEditchangeCombo2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// movetype message handlers

void movetype::OnEditchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	CComboBox m_cbExample;
	m_cbExample.AddString("◊Û“∆");
	m_cbExample.AddString("”““∆");
	m_cbExample.AddString("…œ“∆");
	m_cbExample.AddString("œ¬“∆");
}

void movetype::OnDIYMove() 
{
	// TODO: Add your command handler code here
		CComboBox m_cbExample;
	m_cbExample.AddString("◊Û“∆");
	m_cbExample.AddString("”““∆");
	m_cbExample.AddString("…œ“∆");
	m_cbExample.AddString("œ¬“∆");
}

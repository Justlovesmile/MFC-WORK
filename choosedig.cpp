// choosedig.cpp : implementation file
//

#include "stdafx.h"
#include "Group4.h"
#include "choosedig.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// Cchoosedig dialog


Cchoosedig::Cchoosedig(CWnd* pParent /*=NULL*/)
	: CDialog(Cchoosedig::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cchoosedig)
	//}}AFX_DATA_INIT
}


void Cchoosedig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cchoosedig)
	//}}AFX_DATA_MAP
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cchoosedig, CDialog)
	//{{AFX_MSG_MAP(Cchoosedig)
	ON_EN_CHANGE(IDC_time, OnChangetime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cchoosedig message handlers

void Cchoosedig::OnChangetime() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
}

void Cchoosedig::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void Cchoosedig::OnOK() 
{
	// TODO: Add extra validation here
	GetDlgItemText(IDC_time,mtime);
	if(strlen(mtime)==0)
		mtime="0";
	CDialog::OnOK();
}

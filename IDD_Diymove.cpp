// IDD_Diymove.cpp : implementation file
//

#include "stdafx.h"
#include "Group4.h"
#include "IDD_Diymove.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// IDD_Diymove dialog


IDD_Diymove::IDD_Diymove(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_Diymove::IDD, pParent)
{
	//{{AFX_DATA_INIT(IDD_Diymove)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void IDD_Diymove::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(IDD_Diymove)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(IDD_Diymove, CDialog)
	//{{AFX_MSG_MAP(IDD_Diymove)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// IDD_Diymove message handlers

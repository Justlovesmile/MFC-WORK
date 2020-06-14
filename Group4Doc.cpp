// Group4Doc.cpp : implementation of the CGroup4Doc class
//

#include "stdafx.h"
#include "Group4.h"

#include "Group4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGroup4Doc

IMPLEMENT_DYNCREATE(CGroup4Doc, CDocument)

BEGIN_MESSAGE_MAP(CGroup4Doc, CDocument)
	//{{AFX_MSG_MAP(CGroup4Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGroup4Doc construction/destruction

CGroup4Doc::CGroup4Doc()
{
	// TODO: add one-time construction code here

}

CGroup4Doc::~CGroup4Doc()
{
}

BOOL CGroup4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGroup4Doc serialization

void CGroup4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGroup4Doc diagnostics

#ifdef _DEBUG
void CGroup4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGroup4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGroup4Doc commands

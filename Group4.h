// Group4.h : main header file for the GROUP4 application
//

#if !defined(AFX_GROUP4_H__3CAE3DA2_8DE0_42BF_A76A_10A3A74A7056__INCLUDED_)
#define AFX_GROUP4_H__3CAE3DA2_8DE0_42BF_A76A_10A3A74A7056__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGroup4App:
// See Group4.cpp for the implementation of this class
//

class CGroup4App : public CWinApp
{
public:
	CGroup4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroup4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGroup4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUP4_H__3CAE3DA2_8DE0_42BF_A76A_10A3A74A7056__INCLUDED_)

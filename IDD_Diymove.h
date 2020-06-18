#if !defined(AFX_IDD_DIYMOVE_H__07D45B08_8CEF_4B7A_A1F2_4E34CB071675__INCLUDED_)
#define AFX_IDD_DIYMOVE_H__07D45B08_8CEF_4B7A_A1F2_4E34CB071675__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IDD_Diymove.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// IDD_Diymove dialog

class IDD_Diymove : public CDialog
{
// Construction
public:
	IDD_Diymove(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(IDD_Diymove)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(IDD_Diymove)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(IDD_Diymove)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IDD_DIYMOVE_H__07D45B08_8CEF_4B7A_A1F2_4E34CB071675__INCLUDED_)

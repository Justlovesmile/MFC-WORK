#if !defined(AFX_MYDIYMOVE_H__11037208_5BF6_4E91_A739_FF060FFC5619__INCLUDED_)
#define AFX_MYDIYMOVE_H__11037208_5BF6_4E91_A739_FF060FFC5619__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mydiymove.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Mydiymove dialog

class Mydiymove : public CDialog
{
// Construction
public:
	Mydiymove(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Mydiymove)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Mydiymove)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Mydiymove)
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSetfocusCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int style;
	int time;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDIYMOVE_H__11037208_5BF6_4E91_A739_FF060FFC5619__INCLUDED_)

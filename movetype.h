#if !defined(AFX_MOVETYPE_H__58DDEBDA_B822_4DEA_AB1F_7ECC0753AB80__INCLUDED_)
#define AFX_MOVETYPE_H__58DDEBDA_B822_4DEA_AB1F_7ECC0753AB80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// movetype.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// movetype dialog

class movetype : public CDialog
{
// Construction
public:
	movetype(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(movetype)
	enum { IDD = IDD_DIYMove };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(movetype)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(movetype)
	afx_msg void OnEditchangeCombo2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVETYPE_H__58DDEBDA_B822_4DEA_AB1F_7ECC0753AB80__INCLUDED_)

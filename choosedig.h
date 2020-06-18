#if !defined(AFX_CHOOSEDIG_H__50FAE957_A55E_44FF_945E_1A000E8AD883__INCLUDED_)
#define AFX_CHOOSEDIG_H__50FAE957_A55E_44FF_945E_1A000E8AD883__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// choosedig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cchoosedig dialog

class Cchoosedig : public CDialog
{
// Construction
public:
	Cchoosedig(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(Cchoosedig)
	enum { IDD = IDD_Choose };
	CComboBox	m_cb;
	//}}AFX_DATA
	int style;
	CString mtime;
	CString type;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cchoosedig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cchoosedig)
	afx_msg void OnChangetime();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSEDIG_H__50FAE957_A55E_44FF_945E_1A000E8AD883__INCLUDED_)

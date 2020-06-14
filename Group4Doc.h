// Group4Doc.h : interface of the CGroup4Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GROUP4DOC_H__A6EB7097_CD2E_4102_A652_61579ED392AE__INCLUDED_)
#define AFX_GROUP4DOC_H__A6EB7097_CD2E_4102_A652_61579ED392AE__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGroup4Doc : public CDocument
{
protected: // create from serialization only
	CGroup4Doc();
	DECLARE_DYNCREATE(CGroup4Doc)

// Attributes
public:
	CList <ListPoint,ListPoint> Mylist;
// Operations
public:
	int thickness;
	int color;
	int type;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroup4Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGroup4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGroup4Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUP4DOC_H__A6EB7097_CD2E_4102_A652_61579ED392AE__INCLUDED_)

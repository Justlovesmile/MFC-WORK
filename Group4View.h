// Group4View.h : interface of the CGroup4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GROUP4VIEW_H__1BBA5B16_2B0C_4C3D_A1BE_F8864EEB7201__INCLUDED_)
#define AFX_GROUP4VIEW_H__1BBA5B16_2B0C_4C3D_A1BE_F8864EEB7201__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Transform.h"
#include "P2.h"

class CGroup4View : public CView
{
protected: // create from serialization only
	CGroup4View();
	DECLARE_DYNCREATE(CGroup4View)

// Attributes
public:
	CGroup4Doc* GetDocument();

// Operations
public:
	void DoubleBuffer(CDC* pDC);
	void DrawPoint(CGroup4Doc* pdoc,CDC* pdc,CPoint pEnd);
	void DrawLine(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void DrawTriangle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void DrawRectangle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void DrawEllipse(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void DrawBlackjx(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void DrawCircle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void DrawRightTriangle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void DrawArrawLeft(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void DrawArrowUp(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void Drawblackcircle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void Drawfivestar(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd);
	void ReDrawObject();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroup4View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawRectangle(CDC* pDC,CTransform *transP);
	virtual ~CGroup4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint pStart,pEnd;
// Generated message map functions
protected:
	//{{AFX_MSG(CGroup4View)
	afx_msg void Onmakepoint();
	afx_msg void Onmakeline();
	afx_msg void OnClear();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void Onmaketriangle();
	afx_msg void Onmakerectangle();
	afx_msg void Onmakeellipse();
	afx_msg void Onmakeblackjx();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnmakeRightTriangle();
	afx_msg void Onmakecircle();
	afx_msg void Onmakepencil();
	afx_msg void OnmakeArrawLeft();
	afx_msg void OnmakeArrowUp();
	afx_msg void Onmakeblackcircle();
	afx_msg void OnChangeColor();
	afx_msg void OnBackPrev();
	afx_msg void OnmakeFiveStar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Group4View.cpp
inline CGroup4Doc* CGroup4View::GetDocument()
   { return (CGroup4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUP4VIEW_H__1BBA5B16_2B0C_4C3D_A1BE_F8864EEB7201__INCLUDED_)

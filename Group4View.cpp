// Group4View.cpp : implementation of the CGroup4View class
//

#include "stdafx.h"
#include "Group4.h"
#include "math.h"
#include "Group4Doc.h"
#include "Group4View.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

bool cclick;
int dstyle=0;

/////////////////////////////////////////////////////////////////////////////
// CGroup4View

IMPLEMENT_DYNCREATE(CGroup4View, CView)

BEGIN_MESSAGE_MAP(CGroup4View, CView)
	//{{AFX_MSG_MAP(CGroup4View)
	ON_COMMAND(IDD_makepoint, Onmakepoint)
	ON_COMMAND(IDD_makeline, Onmakeline)
	ON_COMMAND(IDD_CLEAR, OnClear)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDD_maketriangle, Onmaketriangle)
	ON_COMMAND(IDD_makerectangle, Onmakerectangle)
	ON_COMMAND(IDD_makeellipse, Onmakeellipse)
	ON_COMMAND(IDD_makeblackjx, Onmakeblackjx)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDD_makeRightTriangle, OnmakeRightTriangle)
	ON_COMMAND(IDD_makecircle, Onmakecircle)
	ON_COMMAND(IDD_makepencil, Onmakepencil)
	ON_COMMAND(IDD_makeArrawLeft, OnmakeArrawLeft)
	ON_COMMAND(IDD_makeArrowUp, OnmakeArrowUp)
	ON_COMMAND(IDD_makeblackcircle, Onmakeblackcircle)
	ON_COMMAND(IDD_ChangeColor, OnChangeColor)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGroup4View construction/destruction
CGroup4View::CGroup4View()
{
	// TODO: add construction code here

}

CGroup4View::~CGroup4View()
{
}

BOOL CGroup4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGroup4View drawing

void CGroup4View::OnDraw(CDC* pDC)
{
	CGroup4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->color=RGB(0,0,0);
	pDoc->thickness=1;
	pDoc->type=PS_SOLID;
	//�Զ�������ϵ
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//����ӳ��ģʽ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô���
	pDC->SetViewportExt(rect.Width(),-rect.Height());//��������:x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//�ͻ�������Ϊ����ϵԭ��
	ReleaseDC(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CGroup4View printing

BOOL CGroup4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGroup4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGroup4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGroup4View diagnostics

#ifdef _DEBUG
void CGroup4View::AssertValid() const
{
	CView::AssertValid();
}

void CGroup4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGroup4Doc* CGroup4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGroup4Doc)));
	return (CGroup4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGroup4View message handlers


//����
void CGroup4View::OnClear() 
{
	RedrawWindow();
	cclick=false;
	dstyle=0;
}
//����
void CGroup4View::Onmakepoint() 
{
	//MessageBox("����������ѡ��","��ʾ");
	cclick=false;
	dstyle=1;
}
//����
void CGroup4View::Onmakeline()
{
	//MessageBox("��������������","��ʾ");
	cclick=false;
	dstyle=2;
}
//������������
void CGroup4View::Onmaketriangle() 
{
	cclick=false;
	dstyle=3;
}
//������
void CGroup4View::Onmakerectangle() 
{
	cclick=false;
	dstyle=4;
}
//����Բ
void CGroup4View::Onmakeellipse() 
{
	cclick=false;
	dstyle=5;
}
//��������
void CGroup4View::Onmakeblackjx() 
{
	cclick=false;
	dstyle=6;
}
//��Բ��
void CGroup4View::Onmakecircle() 
{
	cclick=false;
	dstyle=7;
	
}
//��ֱ��������
void CGroup4View::OnmakeRightTriangle() 
{
	cclick=false;
	dstyle=8;
}
//���ɻ���
void CGroup4View::Onmakepencil() 
{
	cclick=false;
	dstyle=9;
}
//���ͷ
void CGroup4View::OnmakeArrawLeft() 
{
	cclick=false;
	dstyle=10;
}
//�ϼ�ͷ
void CGroup4View::OnmakeArrowUp() 
{
	cclick=false;
	dstyle=11;
}
//ʵ��Բ
void CGroup4View::Onmakeblackcircle() 
{
	cclick=false;
	dstyle=12;
}
/*
1 ����
2 ����
3.������������
4.������
5.����Բ��
6.��������
7.��Բ��
8.��ֱ��������
9.���ɻ���
10.���ͷ
11.�ϼ�ͷ
12.ʵ��Բ
*/
void CGroup4View::OnLButtonDown(UINT nFlags, CPoint point)
{//����������

	CDC* pdc=GetDC();
	// TODO: Add your message handler code here and/or call default
	pStart=pEnd=point;
	pdc=new CClientDC(this);
	cclick=true;
	CView::OnLButtonDown(nFlags, point);
}

void CGroup4View::OnMouseMove(UINT nFlags, CPoint point) 
{//����ƶ�
	// TODO: Add your message handler code here and/or call default
	CString str1; 
	str1.Format (_T("x=%d,y=%d  "),point.x,point.y); 
	((CMainFrame *)GetParent())->SetMessageText(str1); 
	//�ж��Ƿ���
	if(!cclick){
		return;
	}
	CDC* pdc=GetDC();
	CGroup4Doc* pdoc=GetDocument();
	pdc->SetROP2(R2_NOT);//���÷�ɫ
	CPen Pen(pdoc->type,pdoc->thickness,pdoc->color);
	pdc->SelectObject(Pen);
    if(dstyle==1)
    {//��
		pEnd=point;
    }
    else if(dstyle==2)
    {//��
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
        pEnd = point;
        pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
    }
    else if(dstyle==3)
    {//����������
		pdc->MoveTo((pStart.x+pEnd.x)/2,pStart.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo((pStart.x+pEnd.x)/2,pStart.y);
        pEnd = point;
        pdc->MoveTo((pStart.x+pEnd.x)/2,pStart.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo((pStart.x+pEnd.x)/2,pStart.y);
    }
    else if(dstyle==4)
    {//����
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
		pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
        pEnd = point;
        pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
    }
    else if(dstyle==5)
    {//��Բ
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
		pdc->Ellipse(pStart.x,pStart.y,pEnd.x,pEnd.y);
        pEnd = point;
        pdc->Ellipse(pStart.x,pStart.y,pEnd.x,pEnd.y);
    }
    else if(dstyle==6)
    {//������
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
        pEnd = point;
        pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
        bsh.DeleteObject();
    }
    else if(dstyle==7)
    {//Բ
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//�뾶
		CBrush *bsh=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pdc->SelectObject(bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		pEnd=point;
		r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		r = int(sqrt(r1));//�뾶
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
    }
	else if(dstyle==8)
    {//ֱ��������
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pStart.x,pStart.y);
        pEnd = point;
        pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pStart.x,pStart.y);
    }
	else if(dstyle==9)
	{//���ɻ���
		pdc->SetROP2(R2_COPYPEN);
		pdc->MoveTo(pEnd);
		pdc->LineTo(point);
		pEnd = point;
	}
	else if(dstyle==10)
	{//���ͷ
		int dy=int(pStart.y-pEnd.y);
		int dx=int(pEnd.x-pStart.x);
		pdc->MoveTo(pStart.x,int(pStart.y-dy/2));
		pdc->LineTo(int(pStart.x+dx/2),pStart.y);
		pdc->LineTo(int(pStart.x+dx/2),int(pStart.y-dy/4));
		pdc->LineTo(pEnd.x,int(pStart.y-dy/4));
		pdc->LineTo(pEnd.x,int(pStart.y-3*dy/4));
		pdc->LineTo(int(pStart.x+dx/2),int(pStart.y-3*dy/4));
		pdc->LineTo(int(pStart.x+dx/2),pEnd.y);
		pdc->LineTo(pStart.x,int(pStart.y-dy/2));
		pEnd=point;
		dy=int(pStart.y-pEnd.y);
		dx=int(pEnd.x-pStart.x);
		pdc->MoveTo(pStart.x,int(pStart.y-dy/2));
		pdc->LineTo(int(pStart.x+dx/2),pStart.y);
		pdc->LineTo(int(pStart.x+dx/2),int(pStart.y-dy/4));
		pdc->LineTo(pEnd.x,int(pStart.y-dy/4));
		pdc->LineTo(pEnd.x,int(pStart.y-3*dy/4));
		pdc->LineTo(int(pStart.x+dx/2),int(pStart.y-3*dy/4));
		pdc->LineTo(int(pStart.x+dx/2),pEnd.y);
		pdc->LineTo(pStart.x,int(pStart.y-dy/2));
	}
	else if(dstyle==11)
	{//�ϼ�ͷ
		int dy0=int(pStart.y-pEnd.y);
		int dx0=int(pEnd.x-pStart.x);
		pdc->MoveTo(pStart.x,int(pStart.y-dy0/2));
		pdc->LineTo(int(pStart.x+dx0/2),pStart.y);
		pdc->LineTo(pEnd.x,int(pStart.y-dy0/2));
		pdc->LineTo(int(pStart.x+3*dx0/4),int(pStart.y-dy0/2));
		pdc->LineTo(int(pStart.x+3*dx0/4),pEnd.y);
		pdc->LineTo(int(pStart.x+dx0/4),pEnd.y);
		pdc->LineTo(int(pStart.x+dx0/4),int(pStart.y-dy0/2));
		pdc->LineTo(pStart.x,int(pStart.y-dy0/2));
		pEnd=point;
		dy0=int(pStart.y-pEnd.y);
		dx0=int(pEnd.x-pStart.x);
		pdc->MoveTo(pStart.x,int(pStart.y-dy0/2));
		pdc->LineTo(int(pStart.x+dx0/2),pStart.y);
		pdc->LineTo(pEnd.x,int(pStart.y-dy0/2));
		pdc->LineTo(int(pStart.x+3*dx0/4),int(pStart.y-dy0/2));
		pdc->LineTo(int(pStart.x+3*dx0/4),pEnd.y);
		pdc->LineTo(int(pStart.x+dx0/4),pEnd.y);
		pdc->LineTo(int(pStart.x+dx0/4),int(pStart.y-dy0/2));
		pdc->LineTo(pStart.x,int(pStart.y-dy0/2));
	}
	else if(dstyle=12)
	{//ʵ��Բ
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//�뾶
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		pEnd=point;
		r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		r = int(sqrt(r1));//�뾶
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		bsh.DeleteObject();
	}
	ReleaseDC(pdc);
	CView::OnMouseMove(nFlags, point);
}
void CGroup4View::OnLButtonUp(UINT nFlags, CPoint point)
{//������̧��
	// TODO: Add your message handler code here and/or call default
	CGroup4Doc* pdoc = GetDocument();
	CDC* pdc=GetDC();
	CPen pen(pdoc->type, pdoc->thickness,pdoc->color);
	pdc->SelectObject(pen);
	pdc->SetROP2(R2_COPYPEN);//��ǰ��ɫ���Ǳ�����ɫ
    if(dstyle==1)
    {//��
		CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pEnd.x,pEnd.y,pEnd.x+5,pEnd.y+5);
		bsh.DeleteObject();
    }
    else if(dstyle==2)
    {//��
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
    }
    else if(dstyle==3)
    {//��������
		pdc->MoveTo((pStart.x+pEnd.x)/2,pStart.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo((pStart.x+pEnd.x)/2,pStart.y);
    }
	else if(dstyle==4)
    {//����
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
        pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
    }
    else if(dstyle==5)
    {//��Բ
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
        pdc->Ellipse(pStart.x,pStart.y,pEnd.x,pEnd.y);
    }
   else if(dstyle==6)
    {//������
        CBrush bsh;
        bsh.CreateSolidBrush(pdoc->color);
        pdc->SelectObject(&bsh);
        pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
		bsh.DeleteObject();
    }
   else if(dstyle==7)
    {//��Բ��
	   	CBrush *bsh=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pdc->SelectObject(bsh);
		CPen pen(pdoc->type,pdoc->thickness,pdoc->color);
	   	float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//�뾶
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
    }
   else if(dstyle==8)
    {//ֱ��������
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pStart.x,pStart.y);
    }
	else if(dstyle==9)
	{//���ɻ���
	   	pdc->MoveTo(pEnd);
		pdc->LineTo(point);
	}
	else if(dstyle==10)
	{//���ͷ
		int dy=int(pStart.y-pEnd.y);
		int dx=int(pEnd.x-pStart.x);
		pdc->MoveTo(pStart.x,int(pStart.y-dy/2));
		pdc->LineTo(int(pStart.x+dx/2),pStart.y);
		pdc->LineTo(int(pStart.x+dx/2),int(pStart.y-dy/4));
		pdc->LineTo(pEnd.x,int(pStart.y-dy/4));
		pdc->LineTo(pEnd.x,int(pStart.y-3*dy/4));
		pdc->LineTo(int(pStart.x+dx/2),int(pStart.y-3*dy/4));
		pdc->LineTo(int(pStart.x+dx/2),pEnd.y);
		pdc->LineTo(pStart.x,int(pStart.y-dy/2));
	}
	else if(dstyle==11)
	{//�ϼ�ͷ
		int dy0=int(pStart.y-pEnd.y);
		int dx0=int(pEnd.x-pStart.x);
		pdc->MoveTo(pStart.x,int(pStart.y-dy0/2));
		pdc->LineTo(int(pStart.x+dx0/2),pStart.y);
		pdc->LineTo(pEnd.x,int(pStart.y-dy0/2));
		pdc->LineTo(int(pStart.x+3*dx0/4),int(pStart.y-dy0/2));
		pdc->LineTo(int(pStart.x+3*dx0/4),pEnd.y);
		pdc->LineTo(int(pStart.x+dx0/4),pEnd.y);
		pdc->LineTo(int(pStart.x+dx0/4),int(pStart.y-dy0/2));
		pdc->LineTo(pStart.x,int(pStart.y-dy0/2));
	}
	else if(dstyle=12)
	{//ʵ��Բ
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//�뾶
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		bsh.DeleteObject();
	}
	cclick=false;
	CView::OnLButtonUp(nFlags, point);
	ReleaseDC(pdc);
}

//��ɫ
void CGroup4View::OnChangeColor() 
{
	CGroup4Doc* pdoc = GetDocument();
	// TODO: Add your command handler code here
	CColorDialog dlg(0,CC_FULLOPEN);
    if(dlg.DoModal())
    {
        pdoc->color=dlg.GetColor();//����ɫ�Ի����л�ȡ��ɫ��Ϣ
    }
    else if(dlg.DoModal()==IDCANCEL)
    {
	}
}

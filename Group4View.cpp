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
	//自定义坐标系
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//设置映射模式
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口
	pDC->SetViewportExt(rect.Width(),-rect.Height());//设置视区:x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//客户区中心为坐标系原点
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


//清屏
void CGroup4View::OnClear() 
{
	RedrawWindow();
	cclick=false;
	dstyle=0;
}
//画点
void CGroup4View::Onmakepoint() 
{
	//MessageBox("按下鼠标左键选点","提示");
	cclick=false;
	dstyle=1;
}
//画线
void CGroup4View::Onmakeline()
{
	//MessageBox("按下鼠标左键画线","提示");
	cclick=false;
	dstyle=2;
}
//画等腰三角形
void CGroup4View::Onmaketriangle() 
{
	cclick=false;
	dstyle=3;
}
//画矩形
void CGroup4View::Onmakerectangle() 
{
	cclick=false;
	dstyle=4;
}
//画椭圆
void CGroup4View::Onmakeellipse() 
{
	cclick=false;
	dstyle=5;
}
//画填充矩形
void CGroup4View::Onmakeblackjx() 
{
	cclick=false;
	dstyle=6;
}
//画圆形
void CGroup4View::Onmakecircle() 
{
	cclick=false;
	dstyle=7;
	
}
//画直角三角形
void CGroup4View::OnmakeRightTriangle() 
{
	cclick=false;
	dstyle=8;
}
//自由画笔
void CGroup4View::Onmakepencil() 
{
	cclick=false;
	dstyle=9;
}
//左箭头
void CGroup4View::OnmakeArrawLeft() 
{
	cclick=false;
	dstyle=10;
}
//上箭头
void CGroup4View::OnmakeArrowUp() 
{
	cclick=false;
	dstyle=11;
}
//实心圆
void CGroup4View::Onmakeblackcircle() 
{
	cclick=false;
	dstyle=12;
}
/*
1 画点
2 画线
3.画等腰三角形
4.画矩形
5.画椭圆形
6.画填充矩形
7.画圆形
8.画直角三角形
9.自由画笔
10.左箭头
11.上箭头
12.实心圆
*/
void CGroup4View::OnLButtonDown(UINT nFlags, CPoint point)
{//鼠标左键按下

	CDC* pdc=GetDC();
	// TODO: Add your message handler code here and/or call default
	pStart=pEnd=point;
	pdc=new CClientDC(this);
	cclick=true;
	CView::OnLButtonDown(nFlags, point);
}

void CGroup4View::OnMouseMove(UINT nFlags, CPoint point) 
{//鼠标移动
	// TODO: Add your message handler code here and/or call default
	CString str1; 
	str1.Format (_T("x=%d,y=%d  "),point.x,point.y); 
	((CMainFrame *)GetParent())->SetMessageText(str1); 
	//判断是否按下
	if(!cclick){
		return;
	}
	CDC* pdc=GetDC();
	CGroup4Doc* pdoc=GetDocument();
	pdc->SetROP2(R2_NOT);//设置反色
	CPen Pen(pdoc->type,pdoc->thickness,pdoc->color);
	pdc->SelectObject(Pen);
    if(dstyle==1)
    {//点
		pEnd=point;
    }
    else if(dstyle==2)
    {//线
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
        pEnd = point;
        pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
    }
    else if(dstyle==3)
    {//等腰三角形
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
    {//矩形
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
		pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
        pEnd = point;
        pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
    }
    else if(dstyle==5)
    {//椭圆
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
		pdc->Ellipse(pStart.x,pStart.y,pEnd.x,pEnd.y);
        pEnd = point;
        pdc->Ellipse(pStart.x,pStart.y,pEnd.x,pEnd.y);
    }
    else if(dstyle==6)
    {//填充矩形
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
        pEnd = point;
        pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
        bsh.DeleteObject();
    }
    else if(dstyle==7)
    {//圆
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//半径
		CBrush *bsh=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pdc->SelectObject(bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		pEnd=point;
		r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		r = int(sqrt(r1));//半径
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
    }
	else if(dstyle==8)
    {//直角三角形
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
	{//自由画笔
		pdc->SetROP2(R2_COPYPEN);
		pdc->MoveTo(pEnd);
		pdc->LineTo(point);
		pEnd = point;
	}
	else if(dstyle==10)
	{//左箭头
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
	{//上箭头
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
	{//实心圆
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//半径
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		pEnd=point;
		r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		r = int(sqrt(r1));//半径
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		bsh.DeleteObject();
	}
	ReleaseDC(pdc);
	CView::OnMouseMove(nFlags, point);
}
void CGroup4View::OnLButtonUp(UINT nFlags, CPoint point)
{//鼠标左键抬起
	// TODO: Add your message handler code here and/or call default
	CGroup4Doc* pdoc = GetDocument();
	CDC* pdc=GetDC();
	CPen pen(pdoc->type, pdoc->thickness,pdoc->color);
	pdc->SelectObject(pen);
	pdc->SetROP2(R2_COPYPEN);//当前颜色覆盖背景颜色
    if(dstyle==1)
    {//点
		CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pEnd.x,pEnd.y,pEnd.x+5,pEnd.y+5);
		bsh.DeleteObject();
    }
    else if(dstyle==2)
    {//线
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
    }
    else if(dstyle==3)
    {//等腰三角
		pdc->MoveTo((pStart.x+pEnd.x)/2,pStart.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo((pStart.x+pEnd.x)/2,pStart.y);
    }
	else if(dstyle==4)
    {//矩形
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
        pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
    }
    else if(dstyle==5)
    {//椭圆
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
        pdc->Ellipse(pStart.x,pStart.y,pEnd.x,pEnd.y);
    }
   else if(dstyle==6)
    {//填充矩形
        CBrush bsh;
        bsh.CreateSolidBrush(pdoc->color);
        pdc->SelectObject(&bsh);
        pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
		bsh.DeleteObject();
    }
   else if(dstyle==7)
    {//画圆形
	   	CBrush *bsh=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pdc->SelectObject(bsh);
		CPen pen(pdoc->type,pdoc->thickness,pdoc->color);
	   	float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//半径
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
    }
   else if(dstyle==8)
    {//直角三角形
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pStart.x,pStart.y);
    }
	else if(dstyle==9)
	{//自由画笔
	   	pdc->MoveTo(pEnd);
		pdc->LineTo(point);
	}
	else if(dstyle==10)
	{//左箭头
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
	{//上箭头
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
	{//实心圆
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//半径
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		bsh.DeleteObject();
	}
	cclick=false;
	CView::OnLButtonUp(nFlags, point);
	ReleaseDC(pdc);
}

//颜色
void CGroup4View::OnChangeColor() 
{
	CGroup4Doc* pdoc = GetDocument();
	// TODO: Add your command handler code here
	CColorDialog dlg(0,CC_FULLOPEN);
    if(dlg.DoModal())
    {
        pdoc->color=dlg.GetColor();//从颜色对话框中获取颜色信息
    }
    else if(dlg.DoModal()==IDCANCEL)
    {
	}
}

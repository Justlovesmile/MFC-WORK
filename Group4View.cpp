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
#define Round(d) int(floor(d+0.5))//四舍五入宏定义
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
	ON_COMMAND(IDD_BackPrev, OnBackPrev)
	ON_COMMAND(IDD_makeFiveStar, OnmakeFiveStar)
	ON_COMMAND(IDD_makePentagon, OnmakePentagon)
	ON_COMMAND(IDD_makeFourStar, OnmakeFourStar)
	ON_COMMAND(IDD_makehu, Onmakehu)
	ON_COMMAND(IDD_Tdown, OnTdown)
	ON_COMMAND(IDD_Tleft, OnTleft)
	ON_COMMAND(IDD_Tright, OnTright)
	ON_COMMAND(IDD_Tup, OnTup)
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
	//DoubleBuffer();
	//自定义坐标系
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//设置映射模式
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口
	pDC->SetViewportExt(rect.Width(),-rect.Height());//设置视区:x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//客户区中心为坐标系原点
	ReleaseDC(pDC);
	trans.SetMat(P,2);
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

//双缓冲
void CGroup4View::DoubleBuffer()
{
	CDC* pDC=GetDC();
	CRect rect;//定义客户区矩形
	GetClientRect(&rect);//获得客户区的大小
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC自定义坐标系
	pDC->SetWindowExt(rect.Width(), rect.Height());//设置窗口范围
	pDC->SetViewportExt(rect.Width(), -rect.Height());//设置视区范围,x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);//客户区中心为原点
	CDC memDC;//内存DC
	memDC.CreateCompatibleDC(pDC);//创建一个与显示pDC兼容的内存memDC
	CBitmap NewBitmap, *pOldBitmap;//内存中承载的临时位图 
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());//创建兼容位图 
	pOldBitmap = memDC.SelectObject(&NewBitmap);//将兼容位图选入memDC 
	memDC.FillSolidRect(rect,pDC->GetBkColor());//按原来背景填充客户区，否则是黑色
	memDC.SetMapMode(MM_ANISOTROPIC);//memDC自定义坐标系
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	ReDrawObject(&memDC);//向memDC绘制图形
	pDC->BitBlt(rect.left, rect.top, rect.Width(), -rect.Height(), &memDC, rect.Width() / 2, rect.Height() / 2, SRCCOPY);//将内存memDC中的位图拷贝到显示pDC中
	memDC.SelectObject(pOldBitmap);//恢复位图
	NewBitmap.DeleteObject();//删除位图
}
//重绘
void CGroup4View::ReDrawObject(CDC* pdc)
{
	CGroup4Doc* pdoc = GetDocument();
    if (!pdoc)
        return;
	cclick=false;
    ListPoint g;
	//暂存数据
	int ds=dstyle;
	int co=pdoc->color;
	int ty=pdoc->type;
	int th=pdoc->thickness;
	RedrawWindow();
    POSITION pos = pdoc->Mylist.GetHeadPosition();
    for(int i = 0; i<pdoc -> Mylist.GetCount(); i++)
    {
		//获取点信息
        g = pdoc -> Mylist.GetNext(pos);
        CPen pen(g.type,g.width,g.color);
		dstyle=g.dstyle;
		pStart=g.pStart;
		pEnd=g.pEnd;
		pdc->SelectObject(pen);
		pdoc->color=g.color;
		pdoc->thickness=g.width;
		pdoc->type=g.type;
		pdc->SetROP2(R2_COPYPEN);//当前颜色覆盖背景颜色
	    if(dstyle==1){//点
			DrawPoint(pdoc,pdc,pEnd);
	    }
	    else if(dstyle==2){//线
			DrawLine(pdoc,pdc,pStart,pEnd);
	    }
	    else if(dstyle==3){//等腰三角
			DrawTriangle(pdoc,pdc,pStart,pEnd);
	    }
		else if(dstyle==4){//矩形
			DrawRectangle(pdoc,pdc,pStart,pEnd);
	    }
	    else if(dstyle==5){//椭圆
			DrawEllipse(pdoc,pdc,pStart,pEnd);
	    }
	   else if(dstyle==6){//填充矩形
	        DrawBlackjx(pdoc,pdc,pStart,pEnd);
	    }
	   else if(dstyle==7){//画圆形
		   	DrawCircle(pdoc,pdc,pStart,pEnd);
	    }
	   else if(dstyle==8){//直角三角形
			DrawRightTriangle(pdoc,pdc,pStart,pEnd);
	    }
		else if(dstyle==10){//左箭头
			DrawArrawLeft(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==11){//上箭头
			DrawArrowUp(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==12){//实心圆
			Drawblackcircle(pdoc,pdc,pStart,pEnd);
		}
			else if(dstyle==13){//五角星
			Drawfivestar(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==14){//五边形
			DrawPentagon(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==15){//四角星
			DrawFourStar(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==16){//弧线
			DrawHu(pdoc,pdc,pStart,pEnd);
		}
	}
	//恢复数据
	pdoc->color=co;
	pdoc->type=ty;
	pdoc->thickness=th;
	dstyle=ds;
}

//回退
void CGroup4View::OnBackPrev() 
{
	// TODO: Add your command handler code here
	CGroup4Doc* pDoc = GetDocument();
	CDC* pdc=GetDC();
	POSITION pos = pDoc->Mylist.GetHeadPosition();
	if(pos!=NULL)
	{
		pDoc->Mylist.RemoveTail();
		ReDrawObject(pdc);
	}
	ReleaseDC(pdc);
}

//清屏
void CGroup4View::OnClear() 
{
	RedrawWindow();
	CGroup4Doc* pdoc = GetDocument();
	pdoc->Mylist.RemoveAll();
	cclick=false;
	dstyle=0;
}
//点
void CGroup4View::Onmakepoint() 
{
	//MessageBox("按下鼠标左键选点","提示");
	cclick=false;
	dstyle=1;
}
//直线
void CGroup4View::Onmakeline()
{
	//MessageBox("按下鼠标左键画线","提示");
	cclick=false;
	dstyle=2;
}
//等腰三角形
void CGroup4View::Onmaketriangle() 
{
	cclick=false;
	dstyle=3;
}
//矩形
void CGroup4View::Onmakerectangle() 
{
	cclick=false;
	dstyle=4;
}
//椭圆
void CGroup4View::Onmakeellipse() 
{
	cclick=false;
	dstyle=5;
}
//填充矩形
void CGroup4View::Onmakeblackjx() 
{
	cclick=false;
	dstyle=6;
}
//圆形
void CGroup4View::Onmakecircle() 
{
	cclick=false;
	dstyle=7;
	
}
//直角三角形
void CGroup4View::OnmakeRightTriangle() 
{
	cclick=false;
	dstyle=8;
}
//自由画笔
void CGroup4View::Onmakepencil() 
{
	MessageBox("注意！自由画笔暂不能保存\n功能有待完善","警告");
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
//五角星
void CGroup4View::OnmakeFiveStar() 
{
	cclick=false;
	dstyle=13;
}
//五边形
void CGroup4View::OnmakePentagon() 
{
	cclick=false;
	dstyle=14;
}
//四角星
void CGroup4View::OnmakeFourStar() 
{
	cclick=false;
	dstyle=15;	
}
//弧线
void CGroup4View::Onmakehu() 
{
	cclick=false;
	dstyle=16;	
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
13.五角星
14.五边形
15.四角星
16.弧线
17.移动
18.
*/
//画点
void CGroup4View::DrawPoint(CGroup4Doc* pdoc,CDC* pdc,CPoint pEnd) 
{
		CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pEnd.x,pEnd.y,pEnd.x+5,pEnd.y+5);
		bsh.DeleteObject();
}
//画线
void CGroup4View::DrawLine(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd)
{
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
}
//画等腰三角形
void CGroup4View::DrawTriangle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		pdc->MoveTo((pStart.x+pEnd.x)/2,pStart.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo((pStart.x+pEnd.x)/2,pStart.y);
}
//画矩形
void CGroup4View::DrawRectangle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
		pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
}
//画椭圆
void CGroup4View::DrawEllipse(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
		pdc->Ellipse(pStart.x,pStart.y,pEnd.x,pEnd.y);
}
//画填充矩形
void CGroup4View::DrawBlackjx(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
		bsh.DeleteObject();
}
//画圆形
void CGroup4View::DrawCircle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//半径
		CBrush *bsh=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pdc->SelectObject(bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
}
//画直角三角形
void CGroup4View::DrawRightTriangle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pStart.x,pStart.y);
}
//画左箭头
void CGroup4View::DrawArrawLeft(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
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
//画上箭头
void CGroup4View::DrawArrowUp(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
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
//画实心圆
void CGroup4View::Drawblackcircle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//半径
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		bsh.DeleteObject();
}
//画五角星
void CGroup4View::Drawfivestar(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		double pi = 3.1415926;
		int RX = -(pStart.x-pEnd.x);
		int RY = -(pStart.y-pEnd.y);
		pdc->MoveTo(int((pStart.x+pEnd.x)/2),pStart.y);
		pdc->LineTo(int(pStart.x+RX*(sin(72*pi/180)-cos(54*pi/180))/2/sin(72*pi/180)),pEnd.y);
		pdc->LineTo(pEnd.x,int(pStart.y+RY*(1-cos(72*pi/180))/(1+sin(54*pi/180))));
		pdc->LineTo(pStart.x,int(pStart.y+RY*(1-cos(72*pi/180))/(1+sin(54*pi/180))));
		pdc->LineTo(int(pStart.x+RX*(sin(72*pi/180)+cos(54*pi/180))/2/sin(72*pi/180)),pEnd.y);
		pdc->LineTo(int((pStart.x+pEnd.x)/2),pStart.y);
}
//画五边形
void CGroup4View::DrawPentagon(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		pdc->MoveTo(int((pStart.x+pEnd.x)/2),pStart.y);
		pdc->LineTo(pStart.x,int((pEnd.y-pStart.y)*0.41+pStart.y));
		pdc->LineTo(int(pStart.x+(pEnd.x - pStart.x)*0.19),pEnd.y);
		pdc->LineTo(int(pStart.x+(pEnd.x - pStart.x)*0.81),pEnd.y);
		pdc->LineTo(pEnd.x,int((pEnd.y-pStart.y)*0.41+pStart.y));
		pdc->LineTo(int((pStart.x+pEnd.x)/2),pStart.y);
}
//画四角星
void CGroup4View::DrawFourStar(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		pdc->MoveTo(int((pStart.x+pEnd.x)/2),pStart.y);
		pdc->LineTo(int(pStart.x+(pEnd.x - pStart.x)*0.375),int((pEnd.y-pStart.y)*0.375+pStart.y));
		pdc->LineTo(pStart.x,int((pStart.y+pEnd.y)/2));
		pdc->LineTo(int(pStart.x+(pEnd.x - pStart.x)*0.375),int((pEnd.y-pStart.y)*0.625+pStart.y));
		pdc->LineTo(int((pStart.x + pEnd.x)/2),pEnd.y);
		pdc->LineTo(int(pStart.x+(pEnd.x - pStart.x)*0.625),int((pEnd.y-pStart.y)*0.625+pStart.y));
		pdc->LineTo(pEnd.x,int((pStart.y+pEnd.y)/2));
		pdc->LineTo(int(pStart.x+(pEnd.x - pStart.x)*0.625),int((pEnd.y-pStart.y)*0.375+pStart.y));
		pdc->LineTo(int((pStart.x+pEnd.x)/2),pStart.y);
}
//画弧线
void CGroup4View::DrawHu(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd)
{
	pdc->SetArcDirection(AD_CLOCKWISE);
	pdc->Arc(pStart.x,pStart.y,pEnd.x,pEnd.y,int((pStart.x+pEnd.x)/2),pStart.y,pEnd.x,int((pStart.y+pEnd.y)/2));
}

void CGroup4View::OnLButtonDown(UINT nFlags, CPoint point)
{//鼠标左键按下

	CDC* pdc=GetDC();
	pStart=pEnd=point;
	pdc=new CClientDC(this);
	cclick=true;
	CView::OnLButtonDown(nFlags, point);
}

void CGroup4View::OnMouseMove(UINT nFlags, CPoint point) 
{//鼠标移动
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
		DrawLine(pdoc,pdc,pStart,pEnd);
        pEnd = point;
        DrawLine(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==3)
    {//等腰三角形
		DrawTriangle(pdoc,pdc,pStart,pEnd);
        pEnd = point;
		DrawTriangle(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==4)
    {//矩形
		DrawRectangle(pdoc,pdc,pStart,pEnd);
        pEnd = point;
		DrawRectangle(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==5)
    {//椭圆
		DrawEllipse(pdoc,pdc,pStart,pEnd);
        pEnd = point;
        DrawEllipse(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==6)
    {//填充矩形
		DrawBlackjx(pdoc,pdc,pStart,pEnd);
        pEnd = point;
        DrawBlackjx(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==7)
    {//圆
		DrawCircle(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawCircle(pdoc,pdc,pStart,pEnd);
    }
	else if(dstyle==8)
    {//直角三角形
		DrawRightTriangle(pdoc,pdc,pStart,pEnd);
        pEnd = point;
        DrawRightTriangle(pdoc,pdc,pStart,pEnd);
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
		DrawArrawLeft(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawArrawLeft(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==11)
	{//上箭头
		DrawArrowUp(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawArrowUp(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==12)
	{//实心圆
		Drawblackcircle(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		Drawblackcircle(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==13)
	{//五角星
		Drawfivestar(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		Drawfivestar(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==14)
	{//五边形
		DrawPentagon(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawPentagon(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==15)
	{//四角星
		DrawFourStar(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawFourStar(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==16)
	{//弧线
		DrawHu(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawHu(pdoc,pdc,pStart,pEnd);
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
	//点信息
    ListPoint lp;
	lp.pStart=pStart;
	lp.pEnd=pEnd;
	lp.color=pdoc->color;
	lp.dstyle=dstyle;
	lp.type=pdoc->type;
	lp.width=pdoc->thickness;
	if(dstyle==1)
    {//点
		DrawPoint(pdoc,pdc,pEnd);
    }
    else if(dstyle==2)
    {//线
		DrawLine(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==3)
    {//等腰三角
		DrawTriangle(pdoc,pdc,pStart,pEnd);
    }
	else if(dstyle==4)
    {//矩形
		DrawRectangle(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==5)
    {//椭圆
		DrawEllipse(pdoc,pdc,pStart,pEnd);
    }
   else if(dstyle==6)
    {//填充矩形
        DrawBlackjx(pdoc,pdc,pStart,pEnd);
    }
   else if(dstyle==7)
    {//画圆形
	   	DrawCircle(pdoc,pdc,pStart,pEnd);
    }
   else if(dstyle==8)
    {//直角三角形
		DrawRightTriangle(pdoc,pdc,pStart,pEnd);
    }
	else if(dstyle==9)
	{//自由画笔
	   	pdc->MoveTo(pEnd);
		pdc->LineTo(point);
	}
	else if(dstyle==10)
	{//左箭头
		DrawArrawLeft(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==11)
	{//上箭头
		DrawArrowUp(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==12)
	{//实心圆
		Drawblackcircle(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==13)
	{//五角星
		Drawfivestar(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==14)
	{//五边形
		DrawPentagon(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==15)
	{//四角星
		DrawFourStar(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==16)
	{//弧线
		DrawHu(pdoc,pdc,pStart,pEnd);
	}
	cclick=false;
	if(dstyle!=9)
	GetDocument()->Mylist.AddTail(lp);//保存信息
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

void CGroup4View::OnTdown() 
{
	// TODO: Add your command handler code here
	CDC* pdc=GetDC();
	CGroup4Doc* pdoc = GetDocument();
    if (!pdoc)
        return;
    ListPoint g;
	int Lcount;
    POSITION pos = pdoc->Mylist.GetHeadPosition();
    Lcount=pdoc -> Mylist.GetCount();
	for(int i = 0; i<Lcount; i++)
    {
        g = pdoc -> Mylist.GetNext(pos);
		P[0].x=g.pStart.x;P[0].y=g.pStart.y;
		P[1].x=g.pEnd.x;P[1].y=g.pEnd.y;
		trans.Translate(0,10);
		g.pStart.x=P[0].x;g.pStart.y=P[0].y;
		g.pEnd.x=P[1].x;g.pEnd.y=P[1].y;
		pdoc->Mylist.RemoveHead();
		pdoc->Mylist.AddTail(g);
	}
	ReDrawObject(pdc);
	ReleaseDC(pdc);
}

void CGroup4View::OnTleft() 
{
	// TODO: Add your command handler code here
	CDC* pdc=GetDC();
	CGroup4Doc* pdoc = GetDocument();
    if (!pdoc)
        return;
    ListPoint g;
	int Lcount;
    POSITION pos = pdoc->Mylist.GetHeadPosition();
    Lcount=pdoc -> Mylist.GetCount();
	for(int i = 0; i<Lcount; i++)
    {
        g = pdoc -> Mylist.GetNext(pos);
		P[0].x=g.pStart.x;P[0].y=g.pStart.y;
		P[1].x=g.pEnd.x;P[1].y=g.pEnd.y;
		trans.Translate(-10,0);
		g.pStart.x=P[0].x;g.pStart.y=P[0].y;
		g.pEnd.x=P[1].x;g.pEnd.y=P[1].y;
		pdoc->Mylist.RemoveHead();
		pdoc->Mylist.AddTail(g);
	}
	ReDrawObject(pdc);
	ReleaseDC(pdc);
}

void CGroup4View::OnTright() 
{
	// TODO: Add your command handler code here
	CDC* pdc=GetDC();
	CGroup4Doc* pdoc = GetDocument();
    if (!pdoc)
        return;
    ListPoint g;
	int Lcount;
    POSITION pos = pdoc->Mylist.GetHeadPosition();
    Lcount=pdoc -> Mylist.GetCount();
	for(int i = 0; i<Lcount; i++)
    {
        g = pdoc -> Mylist.GetNext(pos);
		P[0].x=g.pStart.x;P[0].y=g.pStart.y;
		P[1].x=g.pEnd.x;P[1].y=g.pEnd.y;
		trans.Translate(10,0);
		g.pStart.x=P[0].x;g.pStart.y=P[0].y;
		g.pEnd.x=P[1].x;g.pEnd.y=P[1].y;
		pdoc->Mylist.RemoveHead();
		pdoc->Mylist.AddTail(g);
	}
	ReDrawObject(pdc);
	ReleaseDC(pdc);
}

void CGroup4View::OnTup() 
{
	// TODO: Add your command handler code here
	CDC* pdc=GetDC();
	CGroup4Doc* pdoc = GetDocument();
    if (!pdoc)
        return;
    ListPoint g;
	int Lcount;
    POSITION pos = pdoc->Mylist.GetHeadPosition();
    Lcount=pdoc -> Mylist.GetCount();
	for(int i = 0; i<Lcount; i++)
    {
        g = pdoc -> Mylist.GetNext(pos);
		P[0].x=g.pStart.x;P[0].y=g.pStart.y;
		P[1].x=g.pEnd.x;P[1].y=g.pEnd.y;
		trans.Translate(0,-10);
		g.pStart.x=P[0].x;g.pStart.y=P[0].y;
		g.pEnd.x=P[1].x;g.pEnd.y=P[1].y;
		pdoc->Mylist.RemoveHead();
		pdoc->Mylist.AddTail(g);
	}
	ReDrawObject(pdc);
	ReleaseDC(pdc);
}

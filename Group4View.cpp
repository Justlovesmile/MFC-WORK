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
#define Round(d) int(floor(d+0.5))//��������궨��
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
	//�Զ�������ϵ
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//����ӳ��ģʽ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô���
	pDC->SetViewportExt(rect.Width(),-rect.Height());//��������:x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//�ͻ�������Ϊ����ϵԭ��
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

//˫����
void CGroup4View::DoubleBuffer()
{
	CDC* pDC=GetDC();
	CRect rect;//����ͻ�������
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC�Զ�������ϵ
	pDC->SetWindowExt(rect.Width(), rect.Height());//���ô��ڷ�Χ
	pDC->SetViewportExt(rect.Width(), -rect.Height());//����������Χ,x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);//�ͻ�������Ϊԭ��
	CDC memDC;//�ڴ�DC
	memDC.CreateCompatibleDC(pDC);//����һ������ʾpDC���ݵ��ڴ�memDC
	CBitmap NewBitmap, *pOldBitmap;//�ڴ��г��ص���ʱλͼ 
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());//��������λͼ 
	pOldBitmap = memDC.SelectObject(&NewBitmap);//������λͼѡ��memDC 
	memDC.FillSolidRect(rect,pDC->GetBkColor());//��ԭ���������ͻ����������Ǻ�ɫ
	memDC.SetMapMode(MM_ANISOTROPIC);//memDC�Զ�������ϵ
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	ReDrawObject(&memDC);//��memDC����ͼ��
	pDC->BitBlt(rect.left, rect.top, rect.Width(), -rect.Height(), &memDC, rect.Width() / 2, rect.Height() / 2, SRCCOPY);//���ڴ�memDC�е�λͼ��������ʾpDC��
	memDC.SelectObject(pOldBitmap);//�ָ�λͼ
	NewBitmap.DeleteObject();//ɾ��λͼ
}
//�ػ�
void CGroup4View::ReDrawObject(CDC* pdc)
{
	CGroup4Doc* pdoc = GetDocument();
    if (!pdoc)
        return;
	cclick=false;
    ListPoint g;
	//�ݴ�����
	int ds=dstyle;
	int co=pdoc->color;
	int ty=pdoc->type;
	int th=pdoc->thickness;
	RedrawWindow();
    POSITION pos = pdoc->Mylist.GetHeadPosition();
    for(int i = 0; i<pdoc -> Mylist.GetCount(); i++)
    {
		//��ȡ����Ϣ
        g = pdoc -> Mylist.GetNext(pos);
        CPen pen(g.type,g.width,g.color);
		dstyle=g.dstyle;
		pStart=g.pStart;
		pEnd=g.pEnd;
		pdc->SelectObject(pen);
		pdoc->color=g.color;
		pdoc->thickness=g.width;
		pdoc->type=g.type;
		pdc->SetROP2(R2_COPYPEN);//��ǰ��ɫ���Ǳ�����ɫ
	    if(dstyle==1){//��
			DrawPoint(pdoc,pdc,pEnd);
	    }
	    else if(dstyle==2){//��
			DrawLine(pdoc,pdc,pStart,pEnd);
	    }
	    else if(dstyle==3){//��������
			DrawTriangle(pdoc,pdc,pStart,pEnd);
	    }
		else if(dstyle==4){//����
			DrawRectangle(pdoc,pdc,pStart,pEnd);
	    }
	    else if(dstyle==5){//��Բ
			DrawEllipse(pdoc,pdc,pStart,pEnd);
	    }
	   else if(dstyle==6){//������
	        DrawBlackjx(pdoc,pdc,pStart,pEnd);
	    }
	   else if(dstyle==7){//��Բ��
		   	DrawCircle(pdoc,pdc,pStart,pEnd);
	    }
	   else if(dstyle==8){//ֱ��������
			DrawRightTriangle(pdoc,pdc,pStart,pEnd);
	    }
		else if(dstyle==10){//���ͷ
			DrawArrawLeft(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==11){//�ϼ�ͷ
			DrawArrowUp(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==12){//ʵ��Բ
			Drawblackcircle(pdoc,pdc,pStart,pEnd);
		}
			else if(dstyle==13){//�����
			Drawfivestar(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==14){//�����
			DrawPentagon(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==15){//�Ľ���
			DrawFourStar(pdoc,pdc,pStart,pEnd);
		}
		else if(dstyle==16){//����
			DrawHu(pdoc,pdc,pStart,pEnd);
		}
	}
	//�ָ�����
	pdoc->color=co;
	pdoc->type=ty;
	pdoc->thickness=th;
	dstyle=ds;
}

//����
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

//����
void CGroup4View::OnClear() 
{
	RedrawWindow();
	CGroup4Doc* pdoc = GetDocument();
	pdoc->Mylist.RemoveAll();
	cclick=false;
	dstyle=0;
}
//��
void CGroup4View::Onmakepoint() 
{
	//MessageBox("����������ѡ��","��ʾ");
	cclick=false;
	dstyle=1;
}
//ֱ��
void CGroup4View::Onmakeline()
{
	//MessageBox("��������������","��ʾ");
	cclick=false;
	dstyle=2;
}
//����������
void CGroup4View::Onmaketriangle() 
{
	cclick=false;
	dstyle=3;
}
//����
void CGroup4View::Onmakerectangle() 
{
	cclick=false;
	dstyle=4;
}
//��Բ
void CGroup4View::Onmakeellipse() 
{
	cclick=false;
	dstyle=5;
}
//������
void CGroup4View::Onmakeblackjx() 
{
	cclick=false;
	dstyle=6;
}
//Բ��
void CGroup4View::Onmakecircle() 
{
	cclick=false;
	dstyle=7;
	
}
//ֱ��������
void CGroup4View::OnmakeRightTriangle() 
{
	cclick=false;
	dstyle=8;
}
//���ɻ���
void CGroup4View::Onmakepencil() 
{
	MessageBox("ע�⣡���ɻ����ݲ��ܱ���\n�����д�����","����");
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
//�����
void CGroup4View::OnmakeFiveStar() 
{
	cclick=false;
	dstyle=13;
}
//�����
void CGroup4View::OnmakePentagon() 
{
	cclick=false;
	dstyle=14;
}
//�Ľ���
void CGroup4View::OnmakeFourStar() 
{
	cclick=false;
	dstyle=15;	
}
//����
void CGroup4View::Onmakehu() 
{
	cclick=false;
	dstyle=16;	
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
13.�����
14.�����
15.�Ľ���
16.����
17.�ƶ�
18.
*/
//����
void CGroup4View::DrawPoint(CGroup4Doc* pdoc,CDC* pdc,CPoint pEnd) 
{
		CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pEnd.x,pEnd.y,pEnd.x+5,pEnd.y+5);
		bsh.DeleteObject();
}
//����
void CGroup4View::DrawLine(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd)
{
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
}
//������������
void CGroup4View::DrawTriangle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		pdc->MoveTo((pStart.x+pEnd.x)/2,pStart.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo((pStart.x+pEnd.x)/2,pStart.y);
}
//������
void CGroup4View::DrawRectangle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
		pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
}
//����Բ
void CGroup4View::DrawEllipse(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush =pdc->SelectObject(pBrush);
		pdc->Ellipse(pStart.x,pStart.y,pEnd.x,pEnd.y);
}
//��������
void CGroup4View::DrawBlackjx(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Rectangle(pStart.x,pStart.y,pEnd.x,pEnd.y);
		bsh.DeleteObject();
}
//��Բ��
void CGroup4View::DrawCircle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//�뾶
		CBrush *bsh=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pdc->SelectObject(bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
}
//��ֱ��������
void CGroup4View::DrawRightTriangle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		pdc->MoveTo(pStart.x,pStart.y);
		pdc->LineTo(pEnd.x,pEnd.y);
		pdc->LineTo(pStart.x,pEnd.y);
		pdc->LineTo(pStart.x,pStart.y);
}
//�����ͷ
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
//���ϼ�ͷ
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
//��ʵ��Բ
void CGroup4View::Drawblackcircle(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		float r1 = (float)((pEnd.x-pStart.x)*(pEnd.x-pStart.x) + (pEnd.y-pStart.y)*(pEnd.y-pStart.y));
		int r = int(sqrt(r1));//�뾶
        CBrush bsh(pdoc->color);
        pdc->SelectObject(&bsh);
		pdc->Ellipse(pStart.x-r,pStart.y-r,pStart.x+r,pStart.y+r);
		bsh.DeleteObject();
}
//�������
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
//�������
void CGroup4View::DrawPentagon(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd) 
{
		pdc->MoveTo(int((pStart.x+pEnd.x)/2),pStart.y);
		pdc->LineTo(pStart.x,int((pEnd.y-pStart.y)*0.41+pStart.y));
		pdc->LineTo(int(pStart.x+(pEnd.x - pStart.x)*0.19),pEnd.y);
		pdc->LineTo(int(pStart.x+(pEnd.x - pStart.x)*0.81),pEnd.y);
		pdc->LineTo(pEnd.x,int((pEnd.y-pStart.y)*0.41+pStart.y));
		pdc->LineTo(int((pStart.x+pEnd.x)/2),pStart.y);
}
//���Ľ���
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
//������
void CGroup4View::DrawHu(CGroup4Doc* pdoc,CDC* pdc,CPoint pStart,CPoint pEnd)
{
	pdc->SetArcDirection(AD_CLOCKWISE);
	pdc->Arc(pStart.x,pStart.y,pEnd.x,pEnd.y,int((pStart.x+pEnd.x)/2),pStart.y,pEnd.x,int((pStart.y+pEnd.y)/2));
}

void CGroup4View::OnLButtonDown(UINT nFlags, CPoint point)
{//����������

	CDC* pdc=GetDC();
	pStart=pEnd=point;
	pdc=new CClientDC(this);
	cclick=true;
	CView::OnLButtonDown(nFlags, point);
}

void CGroup4View::OnMouseMove(UINT nFlags, CPoint point) 
{//����ƶ�
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
		DrawLine(pdoc,pdc,pStart,pEnd);
        pEnd = point;
        DrawLine(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==3)
    {//����������
		DrawTriangle(pdoc,pdc,pStart,pEnd);
        pEnd = point;
		DrawTriangle(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==4)
    {//����
		DrawRectangle(pdoc,pdc,pStart,pEnd);
        pEnd = point;
		DrawRectangle(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==5)
    {//��Բ
		DrawEllipse(pdoc,pdc,pStart,pEnd);
        pEnd = point;
        DrawEllipse(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==6)
    {//������
		DrawBlackjx(pdoc,pdc,pStart,pEnd);
        pEnd = point;
        DrawBlackjx(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==7)
    {//Բ
		DrawCircle(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawCircle(pdoc,pdc,pStart,pEnd);
    }
	else if(dstyle==8)
    {//ֱ��������
		DrawRightTriangle(pdoc,pdc,pStart,pEnd);
        pEnd = point;
        DrawRightTriangle(pdoc,pdc,pStart,pEnd);
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
		DrawArrawLeft(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawArrawLeft(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==11)
	{//�ϼ�ͷ
		DrawArrowUp(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawArrowUp(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==12)
	{//ʵ��Բ
		Drawblackcircle(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		Drawblackcircle(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==13)
	{//�����
		Drawfivestar(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		Drawfivestar(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==14)
	{//�����
		DrawPentagon(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawPentagon(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==15)
	{//�Ľ���
		DrawFourStar(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawFourStar(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==16)
	{//����
		DrawHu(pdoc,pdc,pStart,pEnd);
		pEnd=point;
		DrawHu(pdoc,pdc,pStart,pEnd);
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
	//����Ϣ
    ListPoint lp;
	lp.pStart=pStart;
	lp.pEnd=pEnd;
	lp.color=pdoc->color;
	lp.dstyle=dstyle;
	lp.type=pdoc->type;
	lp.width=pdoc->thickness;
	if(dstyle==1)
    {//��
		DrawPoint(pdoc,pdc,pEnd);
    }
    else if(dstyle==2)
    {//��
		DrawLine(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==3)
    {//��������
		DrawTriangle(pdoc,pdc,pStart,pEnd);
    }
	else if(dstyle==4)
    {//����
		DrawRectangle(pdoc,pdc,pStart,pEnd);
    }
    else if(dstyle==5)
    {//��Բ
		DrawEllipse(pdoc,pdc,pStart,pEnd);
    }
   else if(dstyle==6)
    {//������
        DrawBlackjx(pdoc,pdc,pStart,pEnd);
    }
   else if(dstyle==7)
    {//��Բ��
	   	DrawCircle(pdoc,pdc,pStart,pEnd);
    }
   else if(dstyle==8)
    {//ֱ��������
		DrawRightTriangle(pdoc,pdc,pStart,pEnd);
    }
	else if(dstyle==9)
	{//���ɻ���
	   	pdc->MoveTo(pEnd);
		pdc->LineTo(point);
	}
	else if(dstyle==10)
	{//���ͷ
		DrawArrawLeft(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==11)
	{//�ϼ�ͷ
		DrawArrowUp(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==12)
	{//ʵ��Բ
		Drawblackcircle(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==13)
	{//�����
		Drawfivestar(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==14)
	{//�����
		DrawPentagon(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==15)
	{//�Ľ���
		DrawFourStar(pdoc,pdc,pStart,pEnd);
	}
	else if(dstyle==16)
	{//����
		DrawHu(pdoc,pdc,pStart,pEnd);
	}
	cclick=false;
	if(dstyle!=9)
	GetDocument()->Mylist.AddTail(lp);//������Ϣ
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

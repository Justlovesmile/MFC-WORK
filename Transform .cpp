// TransForm.cpp: implementation of the CTransForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Group4.h"
#include "Transform.h"
#include "P2.h"
#include "math.h"
#define PI 3.14159
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTransform::CTransform()
{

}

CTransform::~CTransform()
{

}

void CTransform::SetMat(CP2 *p,int n)
{
	POld=p;
	num=n;
}

void CTransform::Identity()//单位矩阵
{
	T[0][0]=1.0;T[0][1]=0.0;T[0][2]=0.0;
	T[1][0]=0.0;T[1][1]=1.0;T[1][2]=0.0;
	T[2][0]=0.0;T[2][1]=0.0;T[2][2]=1.0;
}

void CTransform::Translate(double tx,double ty)//平移变换矩阵
{
	Identity();
	T[2][0]=tx; 
	T[2][1]=ty; 
	MultiMatrix();	
}

void CTransform::Scale(double sx,double sy)//比例变换矩阵
{
	Identity();
	T[0][0]=sx; 
	T[1][1]=sy; 
	MultiMatrix();	
}

void CTransform::Scale(double sx,double sy,CP2 p)//相对于任意点的整体比例变换矩阵
{
	Translate(-p.x,-p.y);
	Scale(sx,sy);
	Translate(p.x,p.y);	
}

void CTransform::Rotate(double beta)//旋转变换矩阵
{
	Identity();
	double rad=beta*PI/180;
	T[0][0]=cos(rad); T[0][1]=sin(rad);
	T[1][0]=-sin(rad);T[1][1]=cos(rad);
	MultiMatrix();	
}

void CTransform::Rotate(double beta,CP2 p)//相对于任意点的旋转变换矩阵
{
	Translate(-p.x,-p.y);
	Rotate(beta);
	Translate(p.x,p.y);	
}

void CTransform::ReflectOrg()//原点反射变换矩阵
{
	Identity();
	T[0][0]=-1;
	T[1][1]=-1;
	MultiMatrix();	
}

void CTransform::ReflectX()//X轴反射变换矩阵
{
	Identity();
	T[0][0]=1;
	T[1][1]=-1;
	MultiMatrix();	
}

void CTransform::ReflectY()//Y轴反射变换矩阵
{
	Identity();
	T[0][0]=-1;
	T[1][1]=1;
	MultiMatrix();	
}

void CTransform::Shear(double b,double c)//错切变换矩阵
{
	Identity();
	T[0][1]=b;
	T[1][0]=c;
	MultiMatrix();	
}

void CTransform::MultiMatrix()//矩阵相乘
{
	CP2 *PNew=new CP2[num];	
	for(int i=0;i<num;i++)
	{
		PNew[i]=POld[i];
	}
	for(int j=0;j<num;j++)
	{
		POld[j].x=PNew[j].x*T[0][0]+PNew[j].y*T[1][0]+PNew[j].w*T[2][0];
		POld[j].y=PNew[j].x*T[0][1]+PNew[j].y*T[1][1]+PNew[j].w*T[2][1];
		POld[j].w=PNew[j].x*T[0][2]+PNew[j].y*T[1][2]+PNew[j].w*T[2][2];
	}
	delete []PNew;
}

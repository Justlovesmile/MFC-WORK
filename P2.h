// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__F5B8C5D7_BC9B_4346_817B_F55E89EE7598__INCLUDED_)
#define AFX_P2_H__F5B8C5D7_BC9B_4346_817B_F55E89EE7598__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CP2  
{
public:
	CP2();
	virtual ~CP2();
	CP2(double,double);
	friend CP2 operator +(const CP2 &,const CP2 &);
	friend CP2 operator -(const CP2 &,const CP2 &);
	friend CP2 operator *(const CP2 &,double);
	friend CP2 operator *(double,const CP2 &);
	friend CP2 operator /(const CP2 &,double);
	friend CP2 operator+=(const CP2 &,const CP2 &);
	friend CP2 operator-=(const CP2 &,const CP2 &);
	friend CP2 operator*=(const CP2 &,double);
	friend CP2 operator/=(const CP2 &,double);
public:
	double x;
	double y;
	double w;
};

#endif // !defined(AFX_P2_H__F5B8C5D7_BC9B_4346_817B_F55E89EE7598__INCLUDED_)

// Transform.h: interface for the CTransform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORM_H__C4FA86B2_0AF5_409A_94EB_B02A1EE13E05__INCLUDED_)
#define AFX_TRANSFORM_H__C4FA86B2_0AF5_409A_94EB_B02A1EE13E05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"

class CTransform//��ά���α任  
{
public:
	CTransform();
	virtual ~CTransform();
	void SetMat(CP2 *,int);
	void Identity();
	void Translate(double,double);//ƽ�Ʊ任����
	void Scale(double,double);//�����任����
	void Scale(double,double,CP2);//����������ı����任����
	void Rotate(double);//��ת�任����
	void Rotate(double,CP2);//�������������ת�任����
	void ReflectOrg();//ԭ�㷴��任����
	void ReflectX();//X�ᷴ��任����
	void ReflectY();//Y�ᷴ��任����
	void Shear(double,double);//���б任����
	void MultiMatrix();//�������
public:
	double T[3][3];
	CP2 *POld;
	int num;
};

#endif // !defined(AFX_TRANSFORM_H__C4FA86B2_0AF5_409A_94EB_B02A1EE13E05__INCLUDED_)

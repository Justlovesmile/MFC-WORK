// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__5F758C99_A63C_44D7_8206_D7C1F64F1113__INCLUDED_)
#define AFX_STDAFX_H__5F758C99_A63C_44D7_8206_D7C1F64F1113__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#include   <afxtempl.h>
struct ListPoint
{
	CPoint pStart;
	CPoint pEnd;
	int dstyle;//图形类型
	int type;//画笔
	int width;//笔宽
	int color;//颜色
};
#endif // _AFX_NO_AFXCMN_SUPPORT


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__5F758C99_A63C_44D7_8206_D7C1F64F1113__INCLUDED_)

; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Cchoosedig
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Group4.h"
LastPage=0

ClassCount=9
Class1=CGroup4App
Class2=CGroup4Doc
Class3=CGroup4View
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=movetype
Class7=IDD_Diymove
Class8=Mydiymove
Resource2=IDR_MAINFRAME
Class9=Cchoosedig
Resource3=IDD_Choose

[CLS:CGroup4App]
Type=0
HeaderFile=Group4.h
ImplementationFile=Group4.cpp
Filter=N

[CLS:CGroup4Doc]
Type=0
HeaderFile=Group4Doc.h
ImplementationFile=Group4Doc.cpp
Filter=N

[CLS:CGroup4View]
Type=0
HeaderFile=Group4View.h
ImplementationFile=Group4View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDD_play


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Group4.cpp
ImplementationFile=Group4.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=IDD_Thick
Command18=IDD_Normal
Command19=IDD_Thin
Command20=IDD_SOLID
Command21=IDD_DASH
Command22=IDD_DOT
CommandCount=22

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=IDD_makepencil
Command2=IDD_makepoint
Command3=IDD_makeline
Command4=IDD_makehu
Command5=IDD_makerectangle
Command6=IDD_makeblackjx
Command7=IDD_maketriangle
Command8=IDD_makeRightTriangle
Command9=IDD_makeellipse
Command10=IDD_makecircle
Command11=IDD_makeblackcircle
Command12=IDD_makePentagon
Command13=IDD_makeFiveStar
Command14=IDD_makeFourStar
Command15=IDD_makeArrowUp
Command16=IDD_makeArrawLeft
Command17=IDD_ChangeColor
Command18=IDD_CLEAR
Command19=IDD_BackPrev
Command20=IDD_Tup
Command21=IDD_Tdown
Command22=IDD_Tleft
Command23=IDD_Tright
Command24=IDD_TCounterclockwise
Command25=IDD_Tclockwise
Command26=IDD_TBig
Command27=IDD_TSmall
Command28=IDD_Choose
CommandCount=28

[CLS:movetype]
Type=0
HeaderFile=movetype.h
ImplementationFile=movetype.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[CLS:IDD_Diymove]
Type=0
HeaderFile=IDD_Diymove.h
ImplementationFile=IDD_Diymove.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT

[CLS:Mydiymove]
Type=0
HeaderFile=Mydiymove.h
ImplementationFile=Mydiymove.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[DLG:IDD_Choose]
Type=1
Class=Cchoosedig
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_time,edit,1350639744

[CLS:Cchoosedig]
Type=0
HeaderFile=choosedig.h
ImplementationFile=choosedig.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO1
VirtualFilter=dWC


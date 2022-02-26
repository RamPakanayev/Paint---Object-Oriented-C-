
// OurProjectDlg.h : header file
//

#pragma once
#include "baseShape.h"
#include <stack>

// COurProjectDlg dialog
class COurProjectDlg : public CDialogEx
{
// Construction
	void drawAllShapes(CDC& other);
public:
	COurProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OURPROJECT_DIALOG };
#endif
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
private:
	CTypedPtrArray < CObArray, baseShape*> shapes,undoRedo;//shape template array - saving all the shapes.
	baseShape* currentShape;//current shape darwing
	bool isPressed;
	int selectedShape;//to switch case between shapes
	int penSize;
	//bool _clearPageChecker;
	bool _isRclickPressed;
	CPoint rClickPoint;//keeping the movement of the shape with the spesific Rcliked mouse point

protected:

	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	//-----------------mouse events:
	//left button
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);//start creating shape
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);//end of shape creation
	//right button
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);//selecting the shape in order to move
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);//release moving shape
	//double clicks
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);//update shape color pen brush size as requaierd
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);//copy shape
	//mouse move
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);//to create the shape and move the shape
	//------------------------------------------


	//-----------save load clear undo redo  buttons:
	afx_msg void OnBnClickedButton1();//save
	afx_msg void OnBnClickedButton2();//load
	afx_msg void OnBnClickedButton3();//clear page
	afx_msg void OnBnClickedButton4();//undo
	afx_msg void OnBnClickedButton5();//redo
	//------------------------------------------


	//--------------------------shapes:
	afx_msg void OnBnClickedCheck1();//Line
	BOOL _isLineChecked;
	afx_msg void OnBnClickedCheck2();//Circle
	BOOL _isCircleChecked;
	afx_msg void OnBnClickedCheck3();//Triangle
	BOOL _isTriangleChecked;
	afx_msg void OnBnClickedCheck4();//rectangle
	BOOL _isRectangleChecked;
	afx_msg void OnBnClickedCheck5();//DavidStar
	BOOL _isDavidStarChecked;
	afx_msg void OnBnClickedCheck6();//Diamond
	BOOL _isDiamondChecked;
	afx_msg void OnBnClickedCheck20();//90 degree trapez
	BOOL _isNintyDegreeTrapezChecked;
	afx_msg void OnBnClickedCheck21();//pentagon
	BOOL _isPentagonChecked;
	//------------------------------------------


	//-----------------pen sizes buttons:
	afx_msg void OnBnClickedCheck7();//small
	BOOL isPenSizeSmallChecked;
	afx_msg void OnBnClickedCheck8();//medium
	BOOL _isPenSizeMediumChecked;
	afx_msg void OnBnClickedCheck9();//big
	BOOL _isPenSizeLargeChecked;
	//--------------------------------------


	//-----------------pen color types buttons:
	COLORREF selectPenColor;
	afx_msg void OnBnClickedCheck10();//white
	BOOL _isWhitePenChecked;
	afx_msg void OnBnClickedCheck11();//black
	BOOL _isBlackPenChecked;
	afx_msg void OnBnClickedCheck12();//red
	BOOL _isRedPenChecked;
	afx_msg void OnBnClickedCheck13();//green
	BOOL _isGreenPenCHecked;
	afx_msg void OnBnClickedCheck14();//blue
	BOOL _isBluePenCHecked;
	//------------------------------------------


	//---------------brush color types buttons:
	COLORREF selectBrushColor;
	afx_msg void OnBnClickedCheck15();//white
	BOOL _isBrushWhiteChecked;
	afx_msg void OnBnClickedCheck16();//black
	BOOL _isBrushBlackChecked;
	afx_msg void OnBnClickedCheck17();//red
	BOOL _isBrushRedChecked;
	afx_msg void OnBnClickedCheck18();//green
	BOOL _isBrushGreenChecked;
	afx_msg void OnBnClickedCheck19();//blue
	BOOL _isBrushBlueChecked;
	//------------------------------------------


};

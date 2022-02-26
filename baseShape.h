#pragma once
#include <cmath>
#include "stdafx.h"
class baseShape :public CObject
{
public:
	DECLARE_SERIAL(baseShape)
	
	baseShape();//constractor
	virtual ~baseShape();//destractor
	
	void setBegin(CPoint point);//setter
	void setEnd(CPoint point);//setter
	
	CPoint getBegin()const;//getter
	CPoint getEnd()const;//getter

	virtual void draw(CDC& other);//each shape memamesh
	virtual BOOL InArea(int, int) const;//each shape memamesh
	
	
	void setPenSize(int penS);//setter
	int getPenSize();//getter

	void setPenColor(COLORREF& color);
	void setBackColor(COLORREF& color);
	
	void Serialize(CArchive& ar);//save&load
	
	//for the copy shape event
	void setTYPEID(int ID);
	int getTYPEID() const;
	

	COLORREF getPenColor();
	COLORREF getBackColor();
	
protected:
	int typeID;//for copy shape
	int penSize;
	CPoint begin, end;
	COLORREF penColor;
	COLORREF backColor;
	
};


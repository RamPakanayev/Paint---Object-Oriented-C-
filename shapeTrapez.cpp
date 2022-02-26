#include "pch.h"
#include "shapeTrapez.h"
#include "stdafx.h"


IMPLEMENT_SERIAL(shapeTrapez, shapeTriangle, 1)



void shapeTrapez::draw(CDC& dc)
{
	
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* oldBrush = dc.SelectObject(&brush);
	this->setMidPoint((begin.x - (end.x - begin.x)), end.y);
	this->topPoint.x = this->getMIDVAL().x;
	this->topPoint.y = begin.y;
	
	CPoint arr[4] = { begin,this->topPoint ,this->getMIDVAL(),end };

	dc.Polygon(arr, 4);

}
BOOL  shapeTrapez::InArea(int x, int y) const
{

	CRect temp;
	int tempX = x - begin.x;
	int tempY = y - begin.y;

	if (begin.x > getMIDVAL().x && end.y > begin.y)  temp.SetRect(getMIDVAL().x, begin.y, begin.x, end.y);
	else if (begin.x < getMIDVAL().x && end.y < begin.y)  temp.SetRect(begin.x, end.y, getMIDVAL().x, begin.y);
	else if (getMIDVAL().x <begin.x && begin.y> end.y) temp.SetRect(getMIDVAL().x, end.y, begin.x, begin.y);
	else if (getMIDVAL().x > begin.x && begin.y < end.y) temp.SetRect(begin.x, begin.y, getMIDVAL().x, end.y);
	CPoint point(x, y);

	if (temp.PtInRect(point) == true)
		return temp.PtInRect(point);

	bool CHECKER = (getMIDVAL().x - begin.x) * tempY - (getMIDVAL().y - begin.y) * tempX > 0;

	if ((end.x - begin.x) * tempY - (end.y - begin.y) * tempX > 0 == CHECKER) return FALSE;

	if ((end.x - getMIDVAL().x) * (y - getMIDVAL().y) - (end.y - getMIDVAL().y) * (x - getMIDVAL().x) > 0 != CHECKER) return FALSE;


	return TRUE;
}


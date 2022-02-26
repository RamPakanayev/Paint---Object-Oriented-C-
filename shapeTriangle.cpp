#include "pch.h"
#include "shapeTriangle.h"
#include "stdafx.h"


IMPLEMENT_SERIAL(shapeTriangle, baseShape, 1)



void shapeTriangle::draw(CDC& dc)
{
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* oldBrush = dc.SelectObject(&brush);
	midPoint.y = end.y;
	midPoint.x = begin.x - (end.x - begin.x);

	CPoint arr[3] = { begin,midPoint,end };
	dc.Polygon(arr, 3);

}

BOOL  shapeTriangle::InArea(int x, int y) const
{

	
	int tempX = x - begin.x;
	int tempY = y - begin.y;

	bool CHECKER = (midPoint.x - begin.x) * tempY - (midPoint.y - begin.y) * tempX > 0;

	if ((end.x - begin.x) * tempY - (end.y - begin.y) * tempX > 0 == CHECKER) return FALSE;

	if ((end.x - midPoint.x) * (y - midPoint.y) - (end.y - midPoint.y) * (x - midPoint.x) > 0 != CHECKER) return FALSE;

	return TRUE;
}

void shapeTriangle::setMidPoint(double tempX, double tempY)
{
	this->midPoint.x = tempX;
	this->midPoint.y = tempY;
}

CPoint shapeTriangle::getMIDVAL() const
{
	return this->midPoint;
}

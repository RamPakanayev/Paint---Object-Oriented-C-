#include "pch.h"
#include "shapePentagon.h"
#include "stdafx.h"


IMPLEMENT_SERIAL(shapePentagon, baseShape, 1)



void shapePentagon::draw(CDC& dc)
{
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* oldBrush = dc.SelectObject(&brush);
	CPoint arr[5];
	arr[0].SetPoint(begin.x, end.y);
	arr[1]=end;
	arr[2].SetPoint(end.x + (end.x - begin.x), (end.y + begin.y) * 0.5);
	arr[3].SetPoint(end.x, begin.y);
	arr[4]=begin;
	dc.Polygon(arr, 5);

}
BOOL shapePentagon::InArea(int x, int y) const
{
	
	CRect temp;
	if (end.x > begin.x && end.y > begin.y)  temp.SetRect(begin.x, begin.y, end.x, end.y);
	else if (end.x < begin.x && end.y < begin.y)  temp.SetRect(end.x, end.y, begin.x, begin.y);
	else if (begin.x <end.x && begin.y> end.y) temp.SetRect(begin.x, end.y, end.x, begin.y);
	else if (begin.x > end.x && begin.y < end.y) temp.SetRect(end.x, begin.y, begin.x, end.y);
	CPoint point(x, y);
	return temp.PtInRect(point);

}







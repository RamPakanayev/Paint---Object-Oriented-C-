#include "pch.h"
#include "stdafx.h"
#include "baseShape.h"
IMPLEMENT_SERIAL(baseShape, CObject, 1)

baseShape::baseShape()
{
	penColor = RGB(0, 0, 0);
	backColor = RGB(255, 255, 255);
	penSize = 12;
}

baseShape::~baseShape() {}


void baseShape::setBegin(CPoint point)
{
	begin = point;
}
void baseShape::setEnd(CPoint point)
{
	end = point;
}
CPoint baseShape::getBegin()const
{
	return begin;
}
CPoint baseShape::getEnd()const
{
	return end;
}

void baseShape::draw(CDC& other)
{
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = other.SelectObject(&pen);
	CBrush* oldBrush = other.SelectObject(&brush);
	other.SelectObject(oldPen);
	other.SelectObject(oldBrush);
}


void baseShape::setPenColor(COLORREF& color)
{
	penColor = color;
}

void baseShape::setBackColor(COLORREF& color)
{
	backColor = color;
}
void baseShape::setPenSize(int penS)
{
	penSize = penS;
}
void baseShape::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << penColor << backColor << begin.x << begin.y
			<< end.x << end.y << penSize;

	}
	else
	{

		ar >> penColor >> backColor >> begin.x >> begin.y
			>> end.x >> end.y >> penSize;

	}
}

BOOL baseShape::InArea(int x, int y) const
{
	return TRUE;
}


int baseShape::getPenSize()
{
	return penSize;
}

void  baseShape::setTYPEID(int ID)
{
	this->typeID = ID;
}

int baseShape::getTYPEID() const
{
	return this->typeID;
}

COLORREF baseShape::getPenColor()
{
	return this->penColor;
}

COLORREF baseShape::getBackColor()
{
	return this->backColor;
}
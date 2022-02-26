#pragma once
#include "shapeTriangle.h"
class shapeTrapez : public shapeTriangle
{
public:
	DECLARE_SERIAL(shapeTrapez)
	void draw(CDC& dc);
	BOOL InArea(int x, int y) const;
	
private:
	CPoint topPoint;
};
#pragma once
#include "baseShape.h"
class shapePentagon : public baseShape
{
public:
	DECLARE_SERIAL(shapePentagon)
	void draw(CDC& dc);
	BOOL InArea(int x, int y) const;

};


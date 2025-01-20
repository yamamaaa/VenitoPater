#include "Math2D.h"

namespace math2d
{
	POINTFLOAT operator+(const POINTFLOAT& lhs, const POINTFLOAT& rhs)
	{
		POINTFLOAT ret;

		ret.x = lhs.x + rhs.x;
		ret.y = lhs.y + rhs.y;

		return ret;
	}

	POINTFLOAT operator+=(POINTFLOAT& lhs, const POINTFLOAT& rhs)
	{
		lhs = lhs + rhs;
		return lhs;
	}
}
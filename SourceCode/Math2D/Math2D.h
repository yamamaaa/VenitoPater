#pragma once
#include <Dxlib.h>

namespace math2d
{
    /// <summary>
    /// POINTFLOAT���m�̉��Z
    /// </summary>
    /// <param name="lhs">�l1</param>
    /// <param name="rhs">�l2</param>
    /// <returns>���POINTFLOAT�̍��v�l</returns>
    POINTFLOAT operator+(const POINTFLOAT& lhs, const POINTFLOAT& rhs);

    /// <summary>
    /// POINTFLOAT�̉��Z�q
    /// </summary>
    /// <param name="lhs">�l1</param>
    /// <param name="rhs">�l2</param>
    /// <returns>���POINTFLOAT�̍��v�l</returns>
    POINTFLOAT operator+=(POINTFLOAT& lhs, const POINTFLOAT& rhs);
}
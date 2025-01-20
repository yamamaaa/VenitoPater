#pragma once
#include <Dxlib.h>

namespace math2d
{
    /// <summary>
    /// POINTFLOAT同士の加算
    /// </summary>
    /// <param name="lhs">値1</param>
    /// <param name="rhs">値2</param>
    /// <returns>二つのPOINTFLOATの合計値</returns>
    POINTFLOAT operator+(const POINTFLOAT& lhs, const POINTFLOAT& rhs);

    /// <summary>
    /// POINTFLOATの演算子
    /// </summary>
    /// <param name="lhs">値1</param>
    /// <param name="rhs">値2</param>
    /// <returns>二つのPOINTFLOATの合計値</returns>
    POINTFLOAT operator+=(POINTFLOAT& lhs, const POINTFLOAT& rhs);
}
#include "Collision.h"

namespace collision
{
    bool CheckHitSquare(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
    {
        bool hitc = false;//矩形に当たったか？

        float  L1 = x1;      // 左
        float  R1 = x1 + w1; // 右(左+横幅)
        float  L2 = x2;      // 左
        float  R2 = x2 + w2; // 右(左+横幅)

        if (R1 < L2) return hitc = false;
        if (R2 < L1) return hitc = false;

        float  U1 = y1;      // 上
        float  D1 = y1 + h1; // 下(上+縦幅)
        float  U2 = y2;      // 上
        float  D2 = y2 + h2; // 下(上+縦幅)

        if (D1 < U2) return hitc = false;
        if (D2 < U1) return hitc = false;

        // それ以外の場合は当たっている
        return hitc = true;
    }

    bool CheckHitPoint_Square(float x1, float y1, float x2, float y2, float w2, float h2)
    {
        bool hitc = false;//矩形に当たったか？

        float  L1 = x1;      // 左
        float  L2 = x2;      // 左
        float  R2 = x2 + w2; // 右(左+横幅)

        if (L1 < L2) return hitc = false;
        if (R2 < L1) return hitc = false;

        float  U1 = y1;      // 上
        float  U2 = y2;      // 上
        float  D2 = y2 + h2; // 下(上+縦幅)

        if (U1 < U2) return hitc = false;
        if (D2 < U1) return hitc = false;

        // それ以外の場合は当たっている
        return hitc = true;
    }
}
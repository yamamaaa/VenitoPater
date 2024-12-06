#include "Collision.h"

namespace collision
{
    bool CheckHitSquare(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
    {
        bool hitc = false;//��`�ɓ����������H

        float  L1 = x1;      // ��
        float  R1 = x1 + w1; // �E(��+����)
        float  L2 = x2;      // ��
        float  R2 = x2 + w2; // �E(��+����)

        if (R1 < L2) return hitc = false;
        if (R2 < L1) return hitc = false;

        float  U1 = y1;      // ��
        float  D1 = y1 + h1; // ��(��+�c��)
        float  U2 = y2;      // ��
        float  D2 = y2 + h2; // ��(��+�c��)

        if (D1 < U2) return hitc = false;
        if (D2 < U1) return hitc = false;

        // ����ȊO�̏ꍇ�͓������Ă���
        return hitc = true;
    }

    bool CheckHitPoint_Square(float x1, float y1, float x2, float y2, float w2, float h2)
    {
        bool hitc = false;//��`�ɓ����������H

        float  L1 = x1;      // ��
        float  L2 = x2;      // ��
        float  R2 = x2 + w2; // �E(��+����)

        if (L1 < L2) return hitc = false;
        if (R2 < L1) return hitc = false;

        float  U1 = y1;      // ��
        float  U2 = y2;      // ��
        float  D2 = y2 + h2; // ��(��+�c��)

        if (U1 < U2) return hitc = false;
        if (D2 < U1) return hitc = false;

        // ����ȊO�̏ꍇ�͓������Ă���
        return hitc = true;
    }
}
#pragma once

namespace collision
{
    /// <summary>
    /// �l�p�`���m�̓����蔻��
    /// </summary>
    /// <param name="x1">����A�̂����W</param>
    /// <param name="y1">����A��y���W</param>
    /// <param name="w1">����A�̂����蔻��@����</param>
    /// <param name="h1">����A�̂����蔻��@�c��</param>
    /// <param name="x2">����B�̂����W</param>
    /// <param name="y2">����B��y���W</param>
    /// <param name="w2">����B�̂����蔻��@����</param>
    /// <param name="h2">����B�̂����蔻��@�c��</param>
    bool CheckHitSquare(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

    /// <summary>
    /// �_�Ǝl�p�`�̓����蔻��
    /// </summary>
    /// <param name="x1">����A�̂����W</param>
    /// <param name="y1">����A��y���W</param>
    /// <param name="x2">����B�̂����W</param>
    /// <param name="y2">����B��y���W</param>
    /// <param name="w2">����B�̂����蔻��@����</param>
    /// <param name="h2">����B�̂����蔻��@�c��</param>
    bool CheckHitPoint_Square(float x1, float y1,float x2, float y2, float w2, float h2);
}


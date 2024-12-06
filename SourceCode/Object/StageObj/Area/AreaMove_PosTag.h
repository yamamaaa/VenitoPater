#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �G���A�ړ�����HitBox�̃^�O
    /// </summary>
    static struct AreaMove_PosTag
    {
        std::string UP = "up";
        std::string LEFT = "left";
        std::string RIGHT = "right";
        std::string DOWN = "down";
    } areaMove_PosTag;

    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>AreaMove_PosTagAll
    {
        areaMove_PosTag.UP,
        areaMove_PosTag.LEFT,
        areaMove_PosTag.RIGHT,
        areaMove_PosTag.DOWN,
    };
}
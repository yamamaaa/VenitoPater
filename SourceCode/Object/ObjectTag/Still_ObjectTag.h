#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �I�u�W�F�N�g�̎�ޕʃ^�O
    /// </summary>
    static struct Still_ObjectTag
    {
        std::string STILL = "still";
        std::string LINE = "line";
        std::string MENU = "menu";
    }still_ObjectTag;

    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>still_ObjectTagAll
    {
        still_ObjectTag.STILL,
        still_ObjectTag.LINE,
        still_ObjectTag.MENU,
    };
}
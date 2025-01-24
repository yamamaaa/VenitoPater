#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �I�u�W�F�N�g�̎�ޕʃ^�O
    /// </summary>
    static struct TimeOver_ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string GAMEOVERUI = "gameoverui";
        std::string TEXTDRAW = "textdraw";
    } timeOver_ObjectTag;


    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>TimeOver_ObjectTagAll
    {
        timeOver_ObjectTag.BACKGROUND,
        timeOver_ObjectTag.GAMEOVERUI,
        timeOver_ObjectTag.TEXTDRAW,
    };
}
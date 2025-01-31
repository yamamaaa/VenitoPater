#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �I�u�W�F�N�g�̎�ޕʃ^�O
    /// </summary>
    static struct GameClear_ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string GAMECLEARUI = "gameclearui";
        std::string SCORE = "score";
    } gameClear_Objecttag;

    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>GameClear_ObjectTagAll
    {
        gameClear_Objecttag.BACKGROUND,
        gameClear_Objecttag.GAMECLEARUI,
        gameClear_Objecttag.SCORE,
    };
}
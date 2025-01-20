#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// オブジェクトの種類別タグ
    /// </summary>
    static struct GameClear_ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string GAMECLEARUI = "gameclearui";
    } gameClear_Objecttag;

    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>GameClear_ObjectTagAll
    {
        gameClear_Objecttag.BACKGROUND,
        gameClear_Objecttag.GAMECLEARUI,
    };
}
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
        std::string SCORE = "score";
    } gameClear_ObjectTag;

    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>GameClear_ObjectTagAll
    {
        gameClear_ObjectTag.BACKGROUND,
        gameClear_ObjectTag.GAMECLEARUI,
        gameClear_ObjectTag.SCORE,
    };
}
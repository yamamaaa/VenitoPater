#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// オブジェクトの種類別タグ
    /// </summary>
    static struct GameOver_ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string GAMEOVERUI = "gameoverui";
    } gameOver_ObjectTag;


    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>GameOver_ObjectTagAll
    {
        gameOver_ObjectTag.BACKGROUND,
        gameOver_ObjectTag.GAMEOVERUI,
    };
}
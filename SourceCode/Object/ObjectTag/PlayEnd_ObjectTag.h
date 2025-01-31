#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// オブジェクトの種類別タグ
    /// </summary>
    static struct PlayEnd_ObjectTag
    {
        std::string SCORE = "score";
    } playEnd_ObjectTag;

    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>PlayEnd_ObjectTagAll
    {
        playEnd_ObjectTag.SCORE,
    };
}
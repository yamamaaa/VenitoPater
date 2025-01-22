#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// オブジェクトの種類別タグ
    /// </summary>
    static struct Story_ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string LINE = "line";
        std::string CHARACTER = "character";
    } story_ObjectTag;

    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>Story_ObjectTagAll
    {
        story_ObjectTag.BACKGROUND,
        story_ObjectTag.LINE,
        story_ObjectTag.CHARACTER,
    };
}
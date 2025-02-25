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
        std::string CHARACTER = "character";
        std::string STORYITEM = "storyitem";
        std::string LINE = "line";
        std::string MENU = "menu";
    } story_ObjectTag;

    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>Story_ObjectTagAll
    {
        story_ObjectTag.BACKGROUND,
        story_ObjectTag.CHARACTER,
        story_ObjectTag.STORYITEM,
        story_ObjectTag.LINE,
        story_ObjectTag.MENU,
    };
}
#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// オブジェクトの種類別タグ
    /// </summary>
    static struct Tutorial_ObjectTag
    {
        std::string TUTORIALUI = "tutorialui";
    } tutorial_ObjectTag;

    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>Tutorial_ObjectTagAll
    {
       tutorial_ObjectTag.TUTORIALUI,
    };
}
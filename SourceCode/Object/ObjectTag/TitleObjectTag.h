#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// オブジェクトの種類別タグ
    /// </summary>
    static struct TitleObjectTag
    {
        std::string TITLEUI = "titleui";
        std::string SELECTMODE = "selectmode";
    } titleObjectTag;

    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>TitleObjectTagAll
    {
        titleObjectTag.TITLEUI,
        titleObjectTag.SELECTMODE,
    };
}

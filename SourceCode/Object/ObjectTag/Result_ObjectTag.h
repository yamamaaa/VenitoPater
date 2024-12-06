#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// オブジェクトの種類別タグ
    /// </summary>
    static struct Result_ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string GAMEOVERUI = "gameoverui";
    } result_objecttag;


    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>Result_ObjectTagAll
    {
        result_objecttag.BACKGROUND,
        result_objecttag.GAMEOVERUI,
    };
}
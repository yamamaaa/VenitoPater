#pragma once
#pragma once
#include<string>
#include<vector>

namespace object
{
    /// <summary>
    /// キャラクター状態
    /// </summary>
    static struct CharaItem_Tag
    {
        std::string DUCK = "duck";
        std::string GUARD_SET = "guard_set";
        std::string MEDICINE = "medicine";
    } charaItem_Tag;

    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>CharaItem_TagAll
    {
        charaItem_Tag.DUCK,
        charaItem_Tag.GUARD_SET,
        charaItem_Tag.MEDICINE,
    };
}
#pragma once
#include<string>

namespace object
{
    /// <summary>
    /// キャラクター状態
    /// </summary>
    static struct CharaStatus
    {
        std::string SORROW = "sorrow";
        std::string NORMAL = "normal";
        std::string HAPPY = "happy";
    } charaStatus;
}
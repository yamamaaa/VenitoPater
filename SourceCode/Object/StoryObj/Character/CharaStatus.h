#pragma once
#include<string>

namespace object
{
    /// <summary>
    /// キャラクター状態
    /// </summary>
    static struct CharaStatus
    {
        std::string NORMAL = "normal";
        std::string WORRY = "worry";
        std::string DISMAYER = "dismayed";
        std::string HAPPY = "happy";
        std::string SURPRISE = "surprise";
    } charaStatus;
}
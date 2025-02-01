#pragma once
#include <vector>
#include <string>

namespace object
{
    /// <summary>
    /// �L�����N�^�[���
    /// </summary>
    static struct CharaStatus
    {
        std::string NORMAL = "normal";
        std::string WORRY = "worry";
        std::string DISMAYER = "dismayed";
        std::string HAPPY = "happy";
        std::string SURPRISE = "surprise";
    } charaStatus;

    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>charaStatus_All
    {
        charaStatus.NORMAL,
        charaStatus.WORRY,
        charaStatus.DISMAYER,
        charaStatus.HAPPY,
        charaStatus.SURPRISE,
    };
}
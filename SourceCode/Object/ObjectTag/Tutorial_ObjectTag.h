#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �I�u�W�F�N�g�̎�ޕʃ^�O
    /// </summary>
    static struct Tutorial_ObjectTag
    {
        std::string TUTORIALUI = "tutorialui";
    } tutorial_ObjectTag;

    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>Tutorial_ObjectTagAll
    {
       tutorial_ObjectTag.TUTORIALUI,
    };
}
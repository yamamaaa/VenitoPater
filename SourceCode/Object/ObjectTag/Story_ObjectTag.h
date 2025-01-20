#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �I�u�W�F�N�g�̎�ޕʃ^�O
    /// </summary>
    static struct Story_ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string CHARACTER = "character";
        std::string LINE = "line";
    } story_ObjectTag;

    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>Story_ObjectTagAll
    {
        story_ObjectTag.BACKGROUND,
        story_ObjectTag.CHARACTER,
        story_ObjectTag.LINE,
    };
}
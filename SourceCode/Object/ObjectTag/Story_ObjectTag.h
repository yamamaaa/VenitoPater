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
        std::string LINE = "line";
        std::string CHARACTER = "character";
    } story_ObjectTag;

    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>Story_ObjectTagAll
    {
        story_ObjectTag.BACKGROUND,
        story_ObjectTag.LINE,
        story_ObjectTag.CHARACTER,
    };
}
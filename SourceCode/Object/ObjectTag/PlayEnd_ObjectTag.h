#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �I�u�W�F�N�g�̎�ޕʃ^�O
    /// </summary>
    static struct PlayEnd_ObjectTag
    {
        std::string SCORE = "score";
    } playEnd_ObjectTag;

    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>PlayEnd_ObjectTagAll
    {
        playEnd_ObjectTag.SCORE,
    };
}
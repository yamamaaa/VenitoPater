#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �I�u�W�F�N�g�̎�ޕʃ^�O
    /// </summary>
    static struct TitleObjectTag
    {
        std::string TITLEUI = "titleui";
        std::string SELECTMODE = "selectmode";
    } titleObjectTag;

    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>TitleObjectTagAll
    {
        titleObjectTag.TITLEUI,
        titleObjectTag.SELECTMODE,
    };
}

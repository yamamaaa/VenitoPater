#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �I�u�W�F�N�g�̎�ޕʃ^�O
    /// </summary>
    static struct Result_ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string GAMEOVERUI = "gameoverui";
    } result_objecttag;


    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>Result_ObjectTagAll
    {
        result_objecttag.BACKGROUND,
        result_objecttag.GAMEOVERUI,
    };
}
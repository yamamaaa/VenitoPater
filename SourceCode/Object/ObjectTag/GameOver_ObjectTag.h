#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �I�u�W�F�N�g�̎�ޕʃ^�O
    /// </summary>
    static struct GameOver_ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string GAMEOVERUI = "gameoverui";
    } gameOver_ObjectTag;


    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>GameOver_ObjectTagAll
    {
        gameOver_ObjectTag.BACKGROUND,
        gameOver_ObjectTag.GAMEOVERUI,
    };
}
#pragma once
#include <string>
#include <memory>
#include <unordered_map>

namespace level_controller
{
    /// <summary>
    /// ��Փx�֌W
    /// </summary>
    class LevelController final
    {
    public:

        /// <summary>
        /// �C���X�^���X����
        /// </summary>
        static void Initialize();

        /// <summary>
        /// ��Փx�̃Z�b�g
        /// </summary>
        /// <param name="select_level">��Փx</param>
        static void SetLevel(const std::string select_level) { levelcontroller->m_NowLevel = select_level; }

        /// <summary>
        /// ��Փx�̎擾
        /// </summary>
        /// <returns>�ݒ肳�ꂽ��Փx</returns>
        static const std::string GetLevel(){ return levelcontroller->m_NowLevel; }

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~LevelController();

    private:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        LevelController();

        std::string m_NowLevel;    //���ۂɃZ�b�g���郌�x��

        static std::unique_ptr<LevelController> levelcontroller;    //���g�̎���
    };
}



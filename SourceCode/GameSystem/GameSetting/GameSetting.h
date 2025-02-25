#pragma once
#include <DxLib.h>
#include <memory>

namespace GameSystem
{
    /// <summary>
    /// �Q�[���Z�b�e�B���O
    /// </summary>
    class GameSetting final
    {
    public:

        /// <summary>
        /// ����������
        /// </summary>
        static void Init();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~GameSetting();

    private:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        GameSetting();

        /// <summary>
        /// ���C�u�����������O�̏���
        /// </summary>
        static void BeforeLibInit();

        /// <summary>
        /// ���C�u������������̏���
        /// </summary>
        static void AfterLibInit();

        static std::unique_ptr<GameSetting> gamesetting;           //���g�̎���

    };
}
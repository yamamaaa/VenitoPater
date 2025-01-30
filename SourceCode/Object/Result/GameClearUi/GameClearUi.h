#pragma once
#include "../../ObjectBase/ObjectBase.h"

/// <summary>
/// ��ʃT�C�Y�֘A
/// </summary>
namespace GameSystem
{
    class Window;
}

namespace object
{
	/// <summary>
	/// �Q�[���N���A�֘A
	/// </summary>
	class GameClearUi:public ObjectBase
	{
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        GameClearUi();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~GameClearUi();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �I�u�W�F�N�g�̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// ���̃Q�[���X�e�[�^�X���Z�b�g
        /// </summary>
        void SetNextGame_Status();

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        void DrawObj() override;

        GameSystem::Window* window;

        int m_FontHandle;                       //�t�H���g�n���h��
        const POINTS m_FONTSIZE = { 200,60 };   //�t�H���g�T�C�Y

        std::string m_TimeText = "5:00";        //�\���e�L�X�g

        bool m_IsSound;      //�T�E���h���Đ�������

        const float m_DRAWCOUNT_MAX = 12.0f;    //�\������
        const float m_COUNT_DECREMENT = 1.0f;	//�J�E���g�����l
        const int m_COLOR = 255;                //�J���[�R�[�h

        float m_DrawCount;  //�\�����ԃJ�E���g
	};
}
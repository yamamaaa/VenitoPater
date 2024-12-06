#pragma once
#include"../../../MouseBase/MouseBase.h"

namespace object
{
    /// <summary>
    /// �x��Ui
    /// </summary>
    class WarningUi;

	/// <summary>
	/// �V��G���A�̃[���}�C�֘A
	/// </summary>
	class ClockWork:public MouseBase
	{
	public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        ClockWork();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~ClockWork();

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
        /// �ړ�����
        /// </summary>
        void MoveObj(const float deltatime) override;

        /// <summary>
        /// �}�E�X�֘A�Ƃ̓����蔻��
        /// </summary>
        void CheckHitMouse();

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        void DrawObj() override;

        static const int m_AnimPattern = 4;         // �A�j���[�V�����̃p�^�[����
        const int m_AnimType = 1;            // �A�j���[�V�����̎��

        int m_Handle[m_AnimPattern];                //�摜�n���h��

        const float m_ANIMTIMER_MAX = 1.0f;            // �A�j���[�V�����^�C�}�[�ő�l
        float m_AnimTimer;                             // �A�j���[�V�����^�C�}�[
        int m_AnimNowPattern;                          // ���݂̃A�j���p�^�[��
        int m_AnimNowIndex;                            // �A�j���[�V�����摜�z��̓Y����

        const float m_CLICK_FPS = 8.0;              // �N���b�N��Ԏ�FPS
        const float m_DEFAULT_FPS = 6.0f;           // �f�t�H���gFPS
        float m_AnimationFPS = m_DEFAULT_FPS;       // �A�j���[�V����FPS

        static const int m_colwidth = 160;        //���T�C�Y
        static const int m_colheight = 180;       //�c�T�C�Y

        bool m_CanDraw = false;              //�摜��\���ł��邩
        bool m_CanDrawHP = false;            //HP��\���ł��邩
        bool m_IsClickNow = false;           //�N���b�N����
        const int m_DrawAreaNum = 3;         //�\���ł���G���A�i���o�[

        float DrawValue;       //�\���pHP

        const float m_WARNING_VALUE = 200.0f;    //�x�����o��HP�̎c�ʒl

        POINTS m_HPDrawPos;       //��]��Hp�o�[�\���ʒu

        POINTS m_FillBoxSize;     //��]��HP�c�ʕ\���T�C�Y
        POINTS m_LineBoxSize;     //HP�o�[�̈͂��T�C�Y

        VECTOR m_FillBox_Collar;    //�J���[�R�[�h
        VECTOR m_LineBox_Collar;

        WarningUi* warningui;     //�x��Ui�C���X�^���X
	};

}
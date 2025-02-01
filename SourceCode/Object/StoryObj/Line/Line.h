#pragma once
#include <fstream>

#include"../../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// �X�g�[���[���̃Z���t�֘A
	/// </summary>
	class Line:public ObjectBase
	{
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Line();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Line();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// �\����Ԃ̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateDrawStatus(const float deltatime);

        /// <summary>
        /// �N���b�N���
        /// </summary>
        void ClickStatus();

        /// <summary>
        /// �`��e�L�X�g�̃Z�b�g
        /// </summary>
        void DrawTextSet();

        /// <summary>
        /// �e�L�X�g�ǂݍ��ݏI��������_Story��
        /// </summary>
        void Text_Processing(std::string line);

        /// <summary>
        /// �`��e�L�X�g�̃A�j���[�V����
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void TextAnim(const float deltatime);

        /// <summary>
        /// �N���b�NUi�̃A�j���[�V�������s��
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void ClickUiMoveAnim(const float deltatime);

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override;

        std::string m_JsonTag[2];	//�T�E���h�pJson�^�O

        //�Q�[���X�e�[�^�X�ύX�R�[�h
        const std::string m_GAMEPLAY = "gameplay";
        const std::string m_STORY = "story";
        const std::string m_STILL = "still";
        const std::string m_PLAYEND = "playend";

        const std::string m_END = "null";   //�t�@�C�����[�R�[�h
        const std::string m_DAY = "day";    //�����ύX�R�[�h
        const std::string m_RED = "red";    //�����F�ύX�R�[�h
        const std::string m_SLOW = "slow";  //�����A�j���X�s�[�h�ύX�R�[�h

        std::ifstream m_TxtFile;//�ǂݍ��܂ꂽ�t�@�C��

        std::string m_Line;     //�t�@�C������擾��������
        std::string m_DrawText; //�\�����镶��

        int m_FontHandle;       //�t�H���g�n���h��

        int m_TxtNum;           //�\�����̕�����

        const float m_COUNT_DECREMENT = 2.4f;	//�J�E���g���炵��
        const float m_CLICKCOU_MAX = 1.2f;      //�ēx�N���b�N�ł���܂�
        const float m_CLICKCOU_WEIT = 4.0f;    //�ҋ@���[�h���̑҂�����

        bool m_IsClick;         //�N���b�N������
        bool m_IsLineSet;       //�\���������Z�b�g������
        bool m_IslineAnim;      //�\���������A�j�������H
        bool m_IsWeitMode;      //�\��������������Ԃ�(�ҋ@)
        bool m_IsClickUi;       //�N���b�NUi��\�����邩
        bool m_IsLineDone;      //�t�@�C�����[�R�[�h�܂œǂݍ��񂾂�
        bool m_IsMove_Up;       //�ړ���������ɐ؂�ւ��邩

        float m_ClickCount;     //�ēx�N���b�N�ł���܂�
        float m_AnimCount;      //�����̃A�j���J�E���g
        float m_AnimSpeed;      //�A�j���X�s�[�h

        const float m_ANIMFPS = 1.0f;          //�A�j��FPS
        const float m_SPEED_DEFAULT = 200.0f;    //�A�j���X�s�[�h(default)
        const float m_SPEED_SLOW = 0.2f;       //�A�j���X�s�[�h(slow)

        const float m_MOVESPEED = 30.0f;        //�ړ��X�s�[�h
        const float m_MOVEPOS_MAX = 3.0f;     //�N���b�NUi�ړ��ʍő�l

        bool m_IsSound_Start;       //�T�E���h���Đ��Đ����邩
        bool m_IsFirst;             //��ԏ��߂̕\����

        const POINTFLOAT m_UIPOS_RESET = {1780.0f,980.0f};     //�N���b�NUi�����ʒu

        POINTFLOAT m_UiPos;     //�N���b�NUi�ʒu

        VECTOR m_NowColor;                             //���݂̕����F
        VECTOR m_COLOR_DEFAULT = VGet(255, 255, 255);  //���F
        VECTOR m_COLOR_RED = VGet(255, 0, 0);          //�ԐF
	};
}



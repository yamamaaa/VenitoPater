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
        void UpdateDrawStatus();

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
        void TextAnim();

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override;

        //�Q�[���X�e�[�^�X�ύX�R�[�h
        const std::string m_GAMEPLAY = "gameplay";
        const std::string m_STORY = "story";
        const std::string m_STILL = "still";

        const std::string m_END = "null";   //�t�@�C�����[�R�[�h
        const std::string m_DAY = "day";    //�����ύX�R�[�h
        const std::string m_RED = "red";    //�����F�ύX�R�[�h
        const std::string m_SLOW = "slow";  //�����A�j���X�s�[�h�ύX�R�[�h

        std::ifstream m_TxtFile;//�ǂݍ��܂ꂽ�t�@�C��

        std::string m_Line;     //�t�@�C������擾��������
        std::string m_DrawText; //�\�����镶��

        std::string m_FontTag;  //�t�H���g��
        int m_FontHandol;       //�t�H���g�n���h��

        int m_TxtNum;           //�\�����̕�����

        const float m_WAITCOU_MAX = 3.0f;     //�X�^�[�g���Ă���\���܂ő҂�����
        float m_StartCount;                   //�X�^�[�g�J�E���g
        bool m_WaitDone;                      //�҂����ԏI��������

        const float m_COUNT_DECREMENT = 0.01f;	//�J�E���g���炵��
        const float m_CLICKCOU_MAX = 0.5f;      //�ēx�N���b�N�ł���܂�
        const float m_CLICKCOU_WEIT = 2.0f;    //�ҋ@���[�h���̑҂�����

        bool m_IsClick;         //�N���b�N������
        bool m_IsLineSet;       //�\���������Z�b�g������
        bool m_IslineAnim;      //�\���������A�j�������H

        bool m_IsLineDone;      //�t�@�C�����[�R�[�h�܂œǂݍ��񂾂�

        bool m_IsWeitMode;      //�\��������������Ԃ�(�ҋ@)

        float m_ClickCount;     //�ēx�N���b�N�ł���܂�
        float m_AnimCount;      //�����̃A�j���J�E���g
        float m_AnimSpeed;      //�A�j���X�s�[�h

        const float m_ANIMFPS = 0.1f;   //�A�j��FPS
        const float m_SPEED_DEFAULT = 0.1f;    //�A�j���X�s�[�h(default)
        const float m_SPEED_SLOW = 0.02f;       //�A�j���X�s�[�h(slow)

        VECTOR m_NowCollar;                             //���݂̕����F
        VECTOR m_COLLAR_DEFAULT = VGet(255, 255, 255);  //���F
        VECTOR m_COLLAR_RED = VGet(255, 0, 0);          //�ԐF
	};
}



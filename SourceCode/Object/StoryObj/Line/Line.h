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

        LPCSTR m_FontPath;      //�t�H���g�^�C�v
        std::string m_Line;     //�t�@�C������擾��������
        std::string m_DrawText; //�\�����镶��

        int m_TxtNum;           //�\�����̕�����

        bool m_IsClick;         //�N���b�N������
        bool m_IsLineSet;       //�\���������Z�b�g������
        bool m_IslineAnim;      //�\���������A�j�������H

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



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
        const std::string m_GAMEPLAY = "GamePlay";
        const std::string m_STORY = "Story";
        const std::string m_STILL = "Still";

        //�����ύX�R�[�h
        const std::string m_DEY = "Dey";

        std::string m_EndTxt;   //�t�@�C�����[�R�[�h

        std::ifstream m_TxtFile;//�ǂݍ��܂ꂽ�t�@�C��

        LPCSTR m_FontPath;      //�t�H���g�^�C�v
        std::string m_Line;     //�\�����镶��

        int m_TxtNum;           //�\�����̕�����

        bool m_IsClick;         //�N���b�N������
        bool m_IsLineSet;       //�\���������Z�b�g������
        bool m_IslineAnim;      //�\���������A�j�������H

        float m_ClickCount;     //�ēx�N���b�N�ł���܂�
        float m_AnimCount;      //�����̃A�j���J�E���g
	};
}



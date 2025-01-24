#pragma once
#include <fstream>

#include"../ObjectBase/ObjectBase.h"

namespace object
{
    class TextDraw:public ObjectBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        TextDraw();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~TextDraw();

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
        /// �`��e�L�X�g�̃Z�b�g
        /// </summary>
        void DrawTextSet();

        /// <summary>
        /// �`��e�L�X�g�̃A�j���[�V����
        /// </summary>
        void TextAnim();

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override;

        const std::string m_END = "null";   //�t�@�C�����[�R�[�h

        std::ifstream m_TxtFile;//�ǂݍ��܂ꂽ�t�@�C��

        LPCSTR m_FontPath;      //�t�H���g�^�C�v
        std::string m_Line;     //�t�@�C������擾��������
        std::string m_DrawText; //�\�����镶��

        const float m_WAITCOU_MAX = 3.0f;    //�X�^�[�g���Ă���\���܂ő҂�����
        float m_StartCount;                   //�X�^�[�g�J�E���g
        bool m_WaitDone;                      //�҂����ԏI��������

        const float m_RISESPEED = 0.01f;			//�������x

        int m_TxtNum;           //�\�����̕�����

        bool m_IsLineSet;       //�\���������Z�b�g������
        bool m_IslineAnim;      //�\���������A�j�������H

        bool m_IsLoadDone;       //�����̓ǂݍ��݂��I���邩
        bool m_IsDraw;           //�����̕\�������邩

        float m_DrawCount;                        //�����̕\�����I����܂�
        const float m_DRAW_COUNTMAX = 0.8f;       //�����̕\������

        float m_AnimCount;      //�����̃A�j���J�E���g
        float m_AnimSpeed;      //�A�j���X�s�[�h

        const float m_ANIMFPS = 0.1f;   //�A�j��FPS
        const float m_SPEED_DEFAULT = 0.02f;    //�A�j���X�s�[�h(default)

        VECTOR m_NowCollar;                             //���݂̕����F
        const VECTOR m_COLLAR_DEFAULT = VGet(255, 255, 255);  //���F
    };
}
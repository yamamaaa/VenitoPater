#pragma once
#include <fstream>

#include"../ObjectBase/ObjectBase.h"
#include "../ObjectManager/ObjectManager.h"

/// <summary>
/// ��ʃT�C�Y�֘A
/// </summary>
namespace GameSystem
{
    class Window;
}

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
        /// �����_���ŕ\������Z���t���Z�b�g
        /// </summary>
        void RandomLineSet();

        /// <summary>
        /// �X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// �\����Ԃ̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param
        void UpdateDrawStatus(const float deltatime);

        /// <summary>
        /// �`��e�L�X�g�̃Z�b�g
        /// </summary>
        void DrawTextSet();

        /// <summary>
        /// �`��e�L�X�g�̃A�j���[�V����
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void TextAnim(const float deltatime);

        /// <summary>
        /// �����̕\�����Ԃ��J�E���g
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void NumDayDrawCount(const float deltatime);

        /// <summary>
        /// �Z���t�̕\��
        /// </summary>
        void LineDraw();

        /// <summary>
        /// �����̕\��
        /// </summary>
        void NumDayDraw();

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override;

        GameSystem::Window* window;
        POINTS m_WindowSize;

        GameStatus m_Status;        //���݂̃X�e�[�^�X

        const std::string m_END = "null";   //�t�@�C�����[�R�[�h

        std::ifstream m_TxtFile;//�ǂݍ��܂ꂽ�t�@�C��

        LPCSTR m_FontPath;      //�t�H���g�^�C�v
        std::string m_Line;     //�t�@�C������擾��������
        std::string m_DrawText; //�\�����镶��

        const POINTS m_FONTSIZE_Line = { 30,5 };      //�t�H���g�T�C�Y_�Z���t
        const POINTS m_FONTSIZE_Day = { 90,20 };     //�t�H���g�T�C�Y_����

        bool m_IsReleaseObj;        //�������I��邩

        const float m_DROPSPEED = 70.0f;		      //�������x
        const float m_COUNTSPEED = 5.0f;              //�^�C���J�E���g�X�s�[�h
        const float m_COUNTMAX = 40.0f;               //�J�E���g�ő�l

        float m_DrawCount;              //�����̓��߂��J�nor�����̕\�����I����܂�

        int m_FontHandle;               //�t�H���g�n���h��

        const float m_WAITCOU_MAX = 3.0f;     //�X�^�[�g���Ă���\���܂ő҂�����
        float m_StartCount;                   //�X�^�[�g�J�E���g
        bool m_WaitDone;                      //�҂����ԏI��������

        const float m_RISESPEED = 0.6f;			//�������x

        int m_TxtNum;           //�\�����̕�����

        bool m_IsLineSet;       //�\���������Z�b�g������
        bool m_IslineAnim;      //�\���������A�j�������H

        const float m_DRAW_COUNTMAX = 2.4f;       //�����̕\������

        float m_AnimCount;      //�����̃A�j���J�E���g
        float m_AnimSpeed;      //�A�j���X�s�[�h

        const float m_ANIMFPS = 0.1f;           //�A�j��FPS
        const float m_SPEED_DEFAULT = 2.0f;    //�A�j���X�s�[�h(default)

        VECTOR m_NowColor;                             //���݂̕����F
        const VECTOR m_COLOR_DEFAULT = VGet(255, 255, 255);  //���F

    };
}
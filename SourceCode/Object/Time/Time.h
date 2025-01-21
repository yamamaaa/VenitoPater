#pragma once
#include "../ObjectBase/ObjectBase.h"

namespace object
{
    class Time :public ObjectBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Time();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Time();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �X�V
        /// </summary>
        /// <param name="deltatime"></param>
        void UpdateObj(float deltatime) override;

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override;

        const float m_TIMEMAX = 300.0f;
        const float m_RISETIME = 0.01f;    //������

        const float m_TIMER_MAX = 1.0f;    // �^�C�}�[�ő�l
        const float m_TIMERFPS = 0.1f;     // �^�C�}�[FPS

        const int m_MINUTES_RISETIME =10;    //�\���p��������
        const int m_MINUTES_MAX = 60;    //�\���p�������ő�l

        const int m_FONTSIZE_AM = 35;      //�t�H���g�T�C�Y_am
        const int m_FONTSIZE_TIME = 60;    //�t�H���g�T�C�Y_����

        POINTFLOAT m_TimePos;   //�����\���ʒu

        float m_NowTime;   //���ۂ̌o�ߎ���
        int m_DrawTime;       //�\���p_����
        int m_DrawMinutes;    //�\���p_��

        float m_DrawCount;   //�\�������̎Z�o
    };
}
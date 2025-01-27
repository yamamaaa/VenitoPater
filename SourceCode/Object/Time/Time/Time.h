#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
    /// <summary>
    /// �Q�[�������Ԋ֘A
    /// </summary>
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

        const POINTS m_FONTSIZE_AM = { 35,20 };      //�t�H���g�T�C�Y_am
        const POINTS m_FONTSIZE_TIME = { 60,20 };    //�t�H���g�T�C�Y_����

        int m_FontHandle_Am;    //�t�H���g�n���h��(am)
        int m_FontHandle_Time;  //�t�H���g�n���h��(time)

        const int m_PLAYTIME_MAX = 5;       //�v���C�^�C���̏I������

        POINTFLOAT m_TimePos;   //�����\���ʒu

        float m_NowTime;   //���ۂ̌o�ߎ���
        int m_DrawTime;       //�\���p_����
        int m_DrawMinutes;    //�\���p_��

        float m_DrawCount;   //�\�������̎Z�o

        std::string m_AmText = "AM";            //�\���e�L�X�g(am)
        std::string m_TimeText = "%d:%d";       //�\���e�L�X�g(time)
        std::string m_TimeText_Zero = "%d:00";  //�\���e�L�X�g(time_zeromin)

        VECTOR m_NowColor;                             //���݂̕����F
        VECTOR m_COLOR_DEFAULT = VGet(255, 255, 255);  //���F
        VECTOR m_COLOR_RED = VGet(255, 0, 0);          //�ԐF
    };
}
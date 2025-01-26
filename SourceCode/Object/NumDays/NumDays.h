#pragma once
#include<Dxlib.h>
#include <memory>

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
    /// �Q�[���������֘A
    /// </summary>
    class NumDays final
    {
    public:

        /// <summary>
        /// ������
        /// </summary>
        static void Initialize();

        /// <summary>
        /// ���݂̓������擾
        /// </summary>
        /// <returns>���݂̓���</returns>
        static int GetNumDays() { return numdays->m_NumDays; }

        /// <summary>
        /// �����𑝂₷
        /// </summary>
        static void UpdateNumDays();

        /// <summary>
        /// �����̕\��
        /// </summary>
        static void DrawNumDays();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~NumDays();

    private:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        NumDays();

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        static void LoadObject();

        GameSystem::Window* window;
        POINTS m_WindowSize;

        static const int m_DROPSPEED = 15;		    	    //�������x
        static const int m_COLLARCODE = 255;	            //�J���[�R�[�h
        const POINTS m_FONTSIZE = { 200,15 };               //�t�H���g�T�C�Y
        const float m_COUNTSPEED = 0.1f;              //�^�C���J�E���g�X�s�[�h
        const float m_COUNTMAX = 70.0f;             //�J�E���g�ő�l

        POINTFLOAT m_ObjPos;            //�����\���ʒu

        int m_NumDays;                  //�Q�[��������
        int m_Collar;                   //���������x
        float m_DrawCount;              //�����̓��߂��J�n����܂�

        bool m_IsFadeDone;				//�������I�������
        int m_FontHandle;       //�t�H���g�n���h��

        static std::unique_ptr<NumDays> numdays;	//���g�̎���
    };
}
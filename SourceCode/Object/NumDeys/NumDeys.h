#pragma once
#include <memory>

namespace object
{
    class NumDeys final
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
        static int GetNumDeys() { return numdeys->m_NumDeys; }

        /// <summary>
        /// �����𑝂₷
        /// </summary>
        static void UpdateNumDeys();

        /// <summary>
        /// �����̕\��
        /// </summary>
        static void DrawNumDeys();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~NumDeys();

    private:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        NumDeys();

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        static void LoadObject();

        static const int m_DROPSPEED = 15;		    	    //�������x
        static const int m_COLLARCODE = 255;	            //�J���[�R�[�h

        int m_NumDeys;                  //�Q�[��������
        int m_Collar = 255;
        float m_DrawCount = 0.0f;

        bool m_IsFadeDone;				//�������I�������

        static std::unique_ptr<NumDeys> numdeys;	//���g�̎���
    };
}
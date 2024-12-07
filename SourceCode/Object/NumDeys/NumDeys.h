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

        int m_NumDeys;  //�Q�[��������

        static std::unique_ptr<NumDeys> numdeys;	//���g�̎���

    };
}
#pragma once
#include<Dxlib.h>
#include <memory>

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

        int m_NumDays;                  //�Q�[��������

        static std::unique_ptr<NumDays> numdays;	//���g�̎���
    };
}
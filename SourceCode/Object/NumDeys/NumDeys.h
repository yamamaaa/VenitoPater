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

        static std::unique_ptr<NumDeys> numdeys;	//���g�̎���

    };
}
#pragma once
#include <memory>

namespace object
{
    /// <summary>
    /// ������Ԋ֘A
    /// </summary>
    class LineStatus final
    {
    public:

        /// <summary>
        /// ������
        /// </summary>
        static void Initialize();

        /// <summary>
        /// �����̃A�j���[�V�������I���������擾
        /// </summary>
        /// <returns>true:�I��|false:���I��</returns>
        static const bool GetIsDoneAnim(){ return linestatus->m_IsDoneAnim; }

        /// <summary>
        /// �����̃A�j���[�V�������I���������Z�b�g
        /// </summary>
        /// <param name="status">true:�I��|false:���I��</param>
        static void SetIsDoneAnim(const bool status) {linestatus->m_IsDoneAnim = status; }

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~LineStatus();

    private:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        LineStatus();

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        static void LoadObject();

        bool m_IsDoneAnim;   //�����̃A�j�����I��������

        static std::unique_ptr<LineStatus> linestatus;	//���g�̎���
    };
}
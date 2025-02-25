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
        /// �\���摜�̃Z�b�g���I���������擾
        /// </summary>
        /// <returns>true:�I��|false:���I��</returns>
        static const bool GetIsDoneImgDraw() { return linestatus->m_IsDoneImgDraw; }

        /// <summary>
        /// �\���摜���Z�b�g���I������
        /// </summary>
        /// <param name="status">true:�I��|false:���I��</param>
        static void SetIsDoneImgDraw(const bool status) { linestatus->m_IsDoneImgDraw = status; }

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

        bool m_IsDoneAnim;      //�����̃A�j�����I��������
        bool m_IsDoneImgDraw;   //�\���摜���Z�b�g���I������

        static std::unique_ptr<LineStatus> linestatus;	//���g�̎���
    };
}
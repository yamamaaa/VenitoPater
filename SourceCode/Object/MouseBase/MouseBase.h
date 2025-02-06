#pragma once
#include"../ObjectBase/ObjectBase.h"

namespace object
{
    /// <summary>
    /// �}�E�X������N���X
    /// </summary>
    class MouseBase:public ObjectBase
    {
    public:
      
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        /// <param name="tagname">�^�O��</param>
        MouseBase(std::string tagname);

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~MouseBase();

    protected:

        /// <summary>
        /// ���N���b�N���͏�Ԏ擾
        /// </summary>
        /// <returns>���͎�:true|�����͎�:false</returns>
        const bool GetStateClick() const { return  m_StateClick; }

        /// <summary>
        /// �J�[�\�����I�u�W�F�N�g�ɓ������Ă��邩
        /// </summary>
        /// <returns>�������Ă���:true|�������Ă��Ȃ�:false</returns>
        const bool GetCursorHit() const { return  m_CursorHit; }

        /// <summary>
        /// �N���b�N�ł��邩�H
        /// </summary>
        void CanClick();

        /// <summary>
        /// �N���b�N������
        /// </summary>
        void MouseClick();

        /// <summary>
        /// �}�E�X�ƃI�u�W�F�N�g�̓����蔻��
        /// </summary>
        void CursorHit();

#if DEBUG
        /// <summary>
        /// �f�o�b�N�p���W��ԕ\�� �폜�\��
        /// </summary>
        void Debug_DrawObj();
#endif
        bool m_StateClick;        //�}�E�X�N���b�N���
        bool m_CanClick;          //�N���b�N�\���
        bool m_CursorHit;         //�J�[�\�����I�u�W�F�N�g�ɓ������Ă��邩�H

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override ;

        /// <summary>
        /// �X�V
        /// </summary>
        /// <param name="deltatime"></param>
        void UpdateObj(float deltatime) override {};

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override {};

        int m_MousePosX;    //�J�[�\�����WX
        int m_MousePosY;    //�J�[�\�����WY
    };
}



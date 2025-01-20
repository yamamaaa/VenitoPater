#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
    /// <summary>
    /// �A�C�e��Ui�֘A
    /// </summary>
    class ItemUi:public ObjectBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        ItemUi();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~ItemUi();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override {};

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override ;

        int m_RItem_Handole; //���A�A�C�e���摜�n���h��

        POINTFLOAT m_RItem_ObjPos;           //���A�A�C�e���摜�ʒu

        POINTFLOAT m_NItemNum_Pos;           //�A�C�e���l�����\���ʒu
        POINTFLOAT m_RItemNum_Pos;           //���A�A�C�e���l�����\���ʒu

        const int m_COLLARCODE = 255;        //�J���[�R�[�h
        const int m_FONTSIZE = 35;           //�t�H���g�T�C�Y
    };
}
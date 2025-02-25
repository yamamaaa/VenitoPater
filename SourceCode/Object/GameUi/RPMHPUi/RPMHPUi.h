#pragma once
#include "../../MouseBase/MouseBase.h"

namespace object
{
    //��]��HPUi�֘A
	class RPMHPUi :public MouseBase
	{
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        RPMHPUi();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~RPMHPUi();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override;

        const int m_DrawArea = 3;  //Ui��\���ł���G���A

        POINTS m_HPDrawPos;       //��]��Hp�o�[�\���ʒu

        POINTS m_FillBoxSize;     //��]��HP�c�ʕ\���T�C�Y
        POINTS m_LineBoxSize;     //HP�o�[�̈͂��T�C�Y

        VECTOR m_FillBox_Color;    //�J���[�R�[�h
        VECTOR m_LineBox_Color;

        float m_DrawValue;       //HP�c�ʕ\���p
        bool m_CanDraw; //�\���ł��邩
	};
}
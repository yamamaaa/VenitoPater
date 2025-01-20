#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// ���Ui�֘A
	/// </summary>
	class AvoidUi :public ObjectBase
	{
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        AvoidUi();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~AvoidUi();

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

        const int m_Hide_DrawArea = 3;  //Ui��\���ł��Ȃ��G���A
        bool m_CanDraw;                 //�\���ł����Ԃ��H
	};
}
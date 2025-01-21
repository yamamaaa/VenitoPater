#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
	class TitleUi:public ObjectBase
	{
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        TitleUi();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~TitleUi();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �I�u�W�F�N�g�̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override ;

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        void DrawObj() override;

        int m_TVScreen_Handle;      //�e���r��ʉ摜�n���h��
        POINTFLOAT m_TVScreenPos;   //�e���r��ʉ摜�ʒu
	};
}
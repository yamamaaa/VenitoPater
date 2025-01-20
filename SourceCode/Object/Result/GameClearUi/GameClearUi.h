#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
	class GameClearUi:public ObjectBase
	{
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        GameClearUi();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~GameClearUi();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �I�u�W�F�N�g�̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        void DrawObj() override;

        const float m_DRAWCOUNT_MAX = 50.0f;   //�\������
        const float m_COUNT_DECREMENT = 0.1f;	//�J�E���g�����l

        float m_DrawCount;  //�\�����ԃJ�E���g
	};
}
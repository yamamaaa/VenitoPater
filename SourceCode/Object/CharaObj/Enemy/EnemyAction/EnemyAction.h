#pragma once
#include "../../../ObjectBase/ObjectBase.h"

namespace object
{
	class EnemyAction :public ObjectBase
	{
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        EnemyAction();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~EnemyAction();

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

        int m_EmyActionImg[4];
	};
}
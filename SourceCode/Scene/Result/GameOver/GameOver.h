#pragma once
#include"../../../Scene/SceneBase/SceneBase.h"

namespace scene
{
    class GameOver:public SceneBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        GameOver();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~GameOver();

        /// <summary>
        /// �V�[���X�V����
        /// </summary>
        /// <param name="deltaTime">�f���^�^�C��</param>
        /// <returns>���̃t���[���V�[��</returns>
        SceneBase* UpdateScene(const float deltaTime)override;

        /// <summary>
        /// �V�[���X�V����
        /// </summary>
        void DrawScene()override;

    };
}
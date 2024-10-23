#pragma once
#include<Dxlib.h>

namespace scene
{
    /// <summary>
    /// �V�[���̍X�V�����N���X
    /// </summary>
    class SceneBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        SceneBase();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        virtual ~SceneBase();

        /// <summary>
        /// �V�[���X�V����
        /// </summary>
        /// <param name="deltaTime">�f���^�^�C��</param>
        /// <returns>���̃t���[���V�[��</returns>
        virtual SceneBase* UpdateScene(const float deltaTime) = 0;

        /// <summary>
        /// �V�[���`�揈��
        /// </summary>
        virtual void DrawScene() = 0;
    };
}
#pragma once
#include<Dxlib.h>

#include"../../Transitor/FadeTransitor/FadeTransitor.h"

namespace transitor
{
    /// <summary>
    /// ��ʈړ]_�t�F�[�h�֘A
    /// </summary>
    class FadeTransitor;
}

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

    protected:

        transitor::FadeTransitor* fade_transitor;   //�t�F�[�h�֘A
    };
}
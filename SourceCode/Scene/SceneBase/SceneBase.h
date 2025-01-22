#pragma once
#include<Dxlib.h>
#include"../../Object/ObjectManager/ObjectManager.h"
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
        /// �I�u�W�F�N�g�ǂݍ��݊֘A
        /// </summary>
        virtual void LoadObject() = 0;

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

        /// <summary>
        /// �V�[����������
        /// </summary>
        void LoadScene();

        /// <summary>
        /// �V�[���؂�ւ�������
        /// </summary>
        void TransitorScene();

        transitor::FadeTransitor* fade_transitor;   //�t�F�[�h�֘A

        bool m_FadeInSet;
    };
}
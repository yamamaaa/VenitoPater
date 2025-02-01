#pragma once
#include"../../Scene/SceneBase/SceneBase.h"

namespace scene
{
    /// <summary>
     /// �Q�[���I����ʊ֘A
     /// </summary>
    class PlayEnd :public SceneBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        PlayEnd();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~PlayEnd();

    private:

        /// <summary>
        /// �I�u�W�F�N�g�ǂݍ��݊֘A
        /// </summary>
        void LoadObject()override;

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

        bool m_IsNextSame;      //���������V�[����

    };
}
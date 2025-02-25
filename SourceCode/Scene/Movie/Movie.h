#pragma once
#include"../../Scene/SceneBase/SceneBase.h"

namespace scene
{
    /// <summary>
     /// �Q�[���I����ʊ֘A
     /// </summary>
    class Movie :public SceneBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Movie();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Movie();

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

        std::string m_MovieFile;  //�Đ����铮��̃t�@�C���p�X
    };
}
#pragma once
#include"../../Scene/SceneBase/SceneBase.h"

namespace scene
{
    /// <summary>
    /// �^�C�g����ʂ̐i�s�Ǘ��N���X
    /// </summary>
    class Title :public SceneBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Title();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Title();

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
        float m_Change_Count;   //���[�r�[���[�h�ɕς��܂ł̃J�E���g

        const float m_COUNT_DECREMENT = 1.0f;     //�J�E���g���炵��
        const float m_COUNT_MAX = 200.0f;         //���[�r�[���[�h�ɕς��܂�
    };
}
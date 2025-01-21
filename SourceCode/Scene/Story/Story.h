#pragma once
#include"../SceneBase/SceneBase.h"

namespace scene
{
	class Story :public SceneBase
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Story();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Story();

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
	};
}
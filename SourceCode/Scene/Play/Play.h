#pragma once
#include<string>
#include"../SceneBase/SceneBase.h"

namespace scene
{
	/// <summary>
	/// �Q�[�����̐i�s�Ǘ��N���X
	/// </summary>
	class Play:public SceneBase
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Play();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Play();

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
#pragma once
#include"../SceneBase/SceneBase.h"

namespace scene
{
	/// <summary>
	/// 3Days���[�h�̐i�s�Ǘ��N���X
	/// </summary>
	class ThreeDays:public SceneBase
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		ThreeDays();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~ThreeDays();

	private:

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
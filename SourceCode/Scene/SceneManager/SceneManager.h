#pragma once
#include<memory>
#include<stack>

//using namespace Fps;

/// <summary>
/// �^�C���֘A
/// </summary>
namespace fps
{
	class Fps;
}

namespace scene
{
	/// <summary>
	/// �V�[���Ǘ�
	/// </summary>
	class SceneManager final
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		SceneManager();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~SceneManager();

		/// <summary>
		/// �Q�[�����[�v
		/// </summary>
		void GameLoop();

		/// <summary>
		/// �V�[���X�V����
		/// </summary>
		void UpdateScene();

		/// <summary>
		/// �V�[���`�揈��
		/// </summary>
		void DrawScene();

		/// <summary>
		/// �V�[���؂�ւ�����
		/// </summary>
		void ChangeScene();

	private:

		std::shared_ptr<class fps::Fps> fps;						//�^�C���}�l�[�W���[

		std::stack<std::shared_ptr<class SceneBase>> m_NowScene;	//���݂̃V�[��
		SceneBase* m_HoldScene;										//���̃V�[��
	};

}



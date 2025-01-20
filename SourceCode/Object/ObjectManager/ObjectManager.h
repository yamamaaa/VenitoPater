#pragma once
#include <Dxlib.h>
#include <memory>
#include <unordered_map>
#include <string>

#include"../ObjectBase/ObjectBase.h"
#include"../ObjectManager/GameStatus.h"

namespace object
{
	class ObjectManager final
	{
	public:

		/// <summary>
		/// �}�l�[�W���[�C���X�^���X����
		/// </summary>
		static void Initialize();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~ObjectManager();

		/// <summary>
		/// ���݂̃V�[���^�O���Z�b�g
		/// </summary>
		static void NowSceneSet(std::vector<std::string> scene_objtag) {
			objectmanager->m_SceneTag = scene_objtag;
		}

		/// <summary>
		/// �I�u�W�F�N�g�o�^
		/// </summary>
		/// <param name="newobj">�o�^����I�u�W�F�N�g</param>
		static void Entry(ObjectBase* newobj);

		/// <summary>
		/// �S�I�u�W�F�N�g�̍X�V����
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		static void UpdateAllObj(const float deltatime);

		/// <summary>
		/// ���ׂẴI�u�W�F�N�g�̕`��
		/// </summary>
		static void DrawAllObj();

		/// <summary>
		/// �S�I�u�W�F�N�g�̍폜
		/// </summary>
		static void ReleaseAllObj();

		/// <summary>
		/// �Q�[����Ԃ��擾
		/// </summary>
		/// <returns>���݂̃Q�[�����</returns>
		static GameStatus GetGameState() { return objectmanager->m_GameStatus; }

		/// <summary>
		/// �Q�[����Ԃ��Z�b�g
		/// </summary>
		/// <param name="stats">�Z�b�g����Q�[�����</param>
		static void SetGameState(GameStatus stats) { objectmanager->m_GameStatus = stats; }

		/// <summary>
		/// ���݂̃V�[�����擾
		/// </summary>
		/// <returns>���݂̃V�[����</returns>
		static std::string GetNowSceneName() { return objectmanager->m_NowScene_Name; }

		/// <summary>
		/// ���݂̃V�[�����Z�b�g
		/// </summary>
		/// <param name="stats">���݂̃V�[����</param>
		static void SetNowSceneName(std::string scenename) { objectmanager->m_NowScene_Name = scenename; }

		/// <summary>
		/// �^�O��ނ̏��߂̃I�u�W�F�N�g��Ԃ�
		/// </summary>
		/// <param name="tagname">�I�u�W�F�N�g�̎��</param>
		/// <returns>�ŏ��̃I�u�W�F�N�g</returns>
		static ObjectBase* GetFirstGameObj(std::string tagname);

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		ObjectManager();

		std::string m_NowScene_Name;	//���݂̃V�[����

		GameStatus m_GameStatus;	//�Q�[�����

		static std::unique_ptr<ObjectManager> objectmanager;									// ObjectManager�̎���
		std::vector<std::string> m_SceneTag;													// ���݂̃V�[���̃I�u�W�F�N�g�^�O
		std::unordered_map<std::string, std::vector<std::shared_ptr<ObjectBase>>> m_Objects;	// �I�u�W�F�N�g���X�g
	};
}

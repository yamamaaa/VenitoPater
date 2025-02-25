#pragma once
#include <Dxlib.h>
#include <memory>
#include <unordered_map>
#include <string>

#include"../ObjectBase/ObjectBase.h"
#include"GameStatus.h"
#include"PlayMenu.h"

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
		/// ���݂̃Q�[����Ԃ��擾
		/// </summary>
		/// <returns>���݂̃Q�[�����</returns>
		static GameStatus GetNowGameState() { return objectmanager->m_NowGameStatus; }

		/// <summary>
		/// ���݂̃Q�[����Ԃ��Z�b�g
		/// </summary>
		/// <param name="stats">�Z�b�g����Q�[�����</param>
		static void SetNowGameState(GameStatus stats) { objectmanager->m_NowGameStatus = stats; }

		/// <summary>
		/// ���̃Q�[����Ԃ��擾
		/// </summary>
		/// <returns>���݂̃Q�[�����</returns>
		static GameStatus GetNextGameState() { return objectmanager->m_NextGameStatus; }

		/// <summary>
		/// ���̃Q�[����Ԃ��Z�b�g
		/// </summary>
		/// <param name="stats">�Z�b�g����Q�[�����</param>
		static void SetNextGameState(GameStatus stats) { objectmanager->m_NextGameStatus = stats; }

		/// <summary>
		/// ���݂̃v���C���[�h���擾
		/// </summary>
		/// <returns>�v���C���[�h</returns>
		static PlayMenu GetPlayMode() { return objectmanager->m_PlayMode; }

		/// <summary>
		/// ���݂̃v���C���[�h���Z�b�g
		/// </summary>
		/// <param name="select">�I�񂾃v���C���[�h</param>
		static void SetPlayMode(PlayMenu select) { objectmanager->m_PlayMode = select; }

		/// <summary>
		/// �I�񂾃I�u�W�F�N�g�̍폜
		/// </summary>
		/// <param name="tagname">�I�u�W�F�N�g�̎��</param>
		static void  ReleaseObj(std::string tagname);

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

		GameStatus m_NowGameStatus;		//���݂̃Q�[�����
		GameStatus m_NextGameStatus;	//���̃Q�[�����

		PlayMenu m_PlayMode;			//���݂̃v���C���[�h
		const std::string MENU = "menu";	//���j���[�^�O

		static std::unique_ptr<ObjectManager> objectmanager;									// ObjectManager�̎���
		std::vector<std::string> m_SceneTag;													// ���݂̃V�[���̃I�u�W�F�N�g�^�O
		std::unordered_map<std::string, std::vector<std::shared_ptr<ObjectBase>>> m_Objects;	// �I�u�W�F�N�g���X�g
	};
}

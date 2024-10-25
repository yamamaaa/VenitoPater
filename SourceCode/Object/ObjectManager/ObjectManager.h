#pragma once
#include <Dxlib.h>
#include <memory>
#include <unordered_map>
#include <string>

namespace object
{
	class ObjectBase;

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
		static void NowSceneSet(std::vector<std::string> scene_objtag);

		/// <summary>
		/// �I�u�W�F�N�g�o�^
		/// </summary>
		/// <param name="newobj">�o�^����I�u�W�F�N�g</param>
		static void Entry(ObjectBase* newobj);

		/// <summary>
		/// �S�I�u�W�F�N�g�̍X�V����
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		static void UpdateAllObj(float deltatime);

		/// <summary>
		/// ���ׂẴI�u�W�F�N�g�̕`��
		/// </summary>
		static void DrawAllObj();

		/// <summary>
		/// �I�u�W�F�N�g�̈ړ�����
		/// </summary>
		static void MoveAllObj();

		/// <summary>
		/// �I�u�W�F�N�g�̎��S����
		/// </summary>
		/// <param name="unnecobj">�s�v�ȃI�u�W�F�N�g</param>
		static void OnDeadObj(std::shared_ptr<ObjectBase> unnecobj);

		/// <summary>
		/// �S�I�u�W�F�N�g�̍폜
		/// </summary>
		static void ReleaseAllObj();

		/// <summary>
		/// �^�O��ނ̏��߂̃I�u�W�F�N�g��Ԃ�
		/// </summary>
		/// <param name="tagname">�I�u�W�F�N�g�̎��</param>
		/// <returns>�ŏ��̃I�u�W�F�N�g</returns>
		ObjectBase* GetFirstGameObj(std::string tagname);

	private:

		ObjectBase* objectbase;

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		ObjectManager();

		static std::unique_ptr<ObjectManager> objectmanager;									// ObjectManager�̎���
		std::vector<std::string> m_SceneTag;													// ���݂̃V�[���̃I�u�W�F�N�g�^�O
		std::unordered_map<std::string, std::vector<std::shared_ptr<ObjectBase>>> m_Objects;	// �I�u�W�F�N�g���X�g
    };
}

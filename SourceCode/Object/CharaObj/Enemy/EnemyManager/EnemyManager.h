#pragma once
#include <memory>
#include <unordered_map>
#include "../EnemyManager/EnemyID.h"

using namespace objecttag;

namespace object
{
	/// <summary>
	/// �G�֘A�̊Ǘ��N���X
	/// </summary>
	class EnemyManager final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// �G�̏o���ݒ�
		/// </summary>
		static void EmyAppearSetting(const float deltatime);

		/// <summary>
		/// �o����Ԃ̃Z�b�g
		/// </summary>
		/// <param name="id">�G���ʔԍ�</param>
		/// <param name="status">true:�o��|false:�o�����Ă��Ȃ�</param>
		static void SetIsAppear(const EnemyID id, const bool status) { enemymanager->m_IsAppear[id] = status; }

		/// <summary>
		/// �o����Ԃ̎擾
		/// </summary>
		/// <param name="id">�G���ʔԍ�</param>
		/// <returns>�o�����</returns>
		static int GetIsAppear(const EnemyID id) { return enemymanager->m_IsAppear[id]; }

		/// <summary>
		/// ���݂̏o�������Z�b�g
		/// </summary>
		/// <param name="num">�o����</param>
		static void SetAppearNumNow(const int num) { enemymanager->m_AppearNumNow = num; }

		/// <summary>
		/// ���݂̏o�������̎擾
		/// </summary>
		/// <param name="num">�o����</param>
		static int GetAppearNumNow() { return enemymanager->m_AppearNumNow; }

		/// <summary>
		/// ���������X�^�[�̃A�N�V�������C����Ԃ��Z�b�g
		/// </summary>
		/// <param name="status">true:���C�����B|false:���B���Ă��Ȃ�</param>
		static void SetBeefUpEmyIsAction(const bool status) { enemymanager->m_BeefUpEmy_IsAction = status; }

		/// <summary>
		/// ���������X�^�[���A�N�V�������C���ɓ��B�������擾
		/// </summary>
		/// <returns>true:���C�����B|false:���B���Ă��Ȃ�</returns>
		static bool GetBeefUpEmyIsAction() { return enemymanager->m_BeefUpEmy_IsAction; }

		/// <summary>
		/// �G���A�N�V�������C���ɓ��B�������Z�b�g
		/// </summary>
		/// <param name="status">true:���B|false:�����B</param>
		static void SetEmyIsAction(const bool status) { enemymanager->m_EmyIsAction = status; }

		/// <summary>
		/// �G���A�N�V�������C���ɓ��B�������擾
		/// </summary>
		/// <returns>true:���B|false:�����B</returns>
		static bool GetEmyIsAction() { return enemymanager->m_EmyIsAction; }

		/// <summary>
		/// �A�N�V�������N�������G��ID���Z�b�g
		/// </summary>
		/// <param name="data">�GID</param>
		static void SetEmyIDAction(EnemyID id) { enemymanager->m_EmyId_Action = id; }

		/// <summary>
		/// �A�N�V�������N�������G��ID���擾
		/// </summary>
		/// <returns>�GID</returns>
		static EnemyID GetEmyIDAction() { return enemymanager->m_EmyId_Action; }

		/// <summary>
		/// �㏈��
		/// </summary>
		static void Processing();

		//�폜�\��
		static void D_DrawStatus();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~EnemyManager();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		EnemyManager();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObjec();

		/// <summary>
		/// �G�̔r�o�ݒ�
		/// </summary>
		static void EmyRandlSetting();

		/// <summary>
		/// �o���J�E���g����
		/// </summary>
		static void AppearCount(const float deltatime);

		/// <summary>
		/// �o������
		/// </summary>
		static void EnemyAppear();

		EnemyID m_EmyId_Data;	//EnemyID�ꎞ�ۊǗp
		EnemyID m_EmyId_Action;	//�A�N�V�������N������EnemyID

		static const int m_EMYSCREEN_MAX = 3;	//��ʓ��G�̏o������
		static const int m_APPEAR_RANGE = 4;	//�o�����̃����_���͈�

		const float m_STARTWAIT_MAX[3] = { 40.0f,24.0f,6.0f};			//�X�^�[�g���̔r�o�҂�����
		const float m_APPEARCOUNT_MAX[3] = {50.0f,12.0f,3.0f};		//�Ăяo���ł���܂ł̃J�E���g

		float m_AppearCount_Max;	//���݂̍ďo���܂ł̃J�E���g

		const float m_COUNT_DECREMENT = 0.6f;	//�J�E���g�����l

		float m_StartCount;						//�X�^�[�g���̔r�o�J�E���g
		float m_AppearCount;					//�G�̔r�o�J�E���g
		int m_AppearNumNow;					//���݂̉�ʓ��G�̑���

		bool m_CanAppear;				//�o���ł��邩
		bool m_BeefUpEmy_IsAction;		//����̓G�̃A�N�V�����t���O
		bool m_EmyIsAction;				//�������Ԃ�

		//�G�̏o���t���O
		std::unordered_map<EnemyID, bool> m_IsAppear{};

		static std::unique_ptr<EnemyManager> enemymanager;	//���g�̎���
	};

}
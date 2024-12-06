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
		static void EmyAppearSetting();

		/// <summary>
		/// �o����Ԃ̃Z�b�g
		/// </summary>
		/// <param name="id">�G���ʔԍ�</param>
		/// <param name="status">true:�o��|false:�o�����Ă��Ȃ�</param>
		static void SetIsAppear(const EnemyID id,const bool status) { enemymanager->m_IsAppear[id] = status; }

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
		/// �G���������Ԃ��Z�b�g
		/// </summary>
		/// <param name="status">true:�\|false:�s�\</param>
		static void SetCanMove(const bool status) { enemymanager->m_CanMove = status; }

		/// <summary>
		/// �G���������Ԃ��擾
		/// </summary>
		/// <returns>true:�\|false:�s�\</returns>
		static bool GetCanMove() { return enemymanager->m_CanMove; }

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
		static void AppearCount();

		/// <summary>
		/// �o������
		/// </summary>
		static void EnemyAppear();


		EnemyID m_EmyId_Data;	//EnemyID�ꎞ�ۊǗp

		static const int m_EMYSCREEN_MAX = 3;	//��ʓ��G�̏o������
		static const int m_APPEAR_RANGE = 4;	//�o�����̃����_���͈�

		const float m_APPEARCOUNT_MAX = 600.0f;	//�Ăяo���ł���܂ł̃J�E���g
		const float m_COUNT_DECREMENT = 5.0f;	//�J�E���g�����l

		float m_AppearCount;					//�G�̔r�o�J�E���g
		int m_AppearNumNow ;					//���݂̉�ʓ��G�̑���

		bool m_CanAppear = true;				//�o���ł��邩
		bool m_BeefUpEmy_IsAction = false;		//����̓G�̃A�N�V�����t���O
		bool m_CanMove = true;					//�������Ԃ�

		//�G�̏o���t���O
		std::unordered_map<EnemyID,bool> m_IsAppear{
			{memini,false},
			{nil,false},
			{spero,false},
			{ira,false},
		};

		static std::unique_ptr<EnemyManager> enemymanager;	//���g�̎���
	};

}
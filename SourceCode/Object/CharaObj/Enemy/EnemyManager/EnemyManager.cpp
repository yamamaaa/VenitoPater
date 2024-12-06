#include <Dxlib.h>
#include <ctime>
#include "EnemyManager.h"

namespace object
{
	//���̂����
	std::unique_ptr<EnemyManager>EnemyManager::enemymanager = nullptr;

	EnemyManager::EnemyManager()
		:m_AppearNumNow(0)
	{
		//�����Ȃ�
	}

	EnemyManager::~EnemyManager()
	{
	}

	void EnemyManager::Initialize()
	{
		//���Ԃ���Ȃ�C���X�^���X����
		if (!enemymanager)
		{
			enemymanager.reset(new EnemyManager);
		}

		LoadObjec();
	}

	void EnemyManager::LoadObjec()
	{
		//�����_�������̏�����
		srand(static_cast<unsigned int>(time(0)));

		//�J�E���g�l�̏�����
		enemymanager->m_AppearCount = enemymanager->m_APPEARCOUNT_MAX;

		enemymanager->m_IsAppear[memini] = false;
		enemymanager->m_IsAppear[nil] = false;
		enemymanager->m_IsAppear[spero] = false;
		enemymanager->m_IsAppear[ira] = false;

		enemymanager->m_AppearNumNow = 0;

		enemymanager->m_CanAppear = true;				//�o���ł��邩
		enemymanager->m_BeefUpEmy_IsAction = false;		//����̓G�̃A�N�V�����t���O
		enemymanager->m_CanMove = true;					//�������Ԃ�

	}

	void EnemyManager::EmyAppearSetting()
	{
		//�G���o���\�Ȏ�
		if (enemymanager->m_CanAppear)
		{
			//��ʓ��̓G������m_EMYSCREEN_MAX�𒴂��ĂȂ�������
			if (enemymanager->m_AppearNumNow < m_EMYSCREEN_MAX)
			{
				EmyRandlSetting();
			}
		}

		//�o�����X�g�b�v���ꂽ��
		if (!enemymanager->m_CanAppear)
		{
			AppearCount();
		}
	}

	void EnemyManager::EmyRandlSetting()
	{
		int range = m_APPEAR_RANGE;	//�r�o����G�������_���Ō���
		int emynum = rand() % range;

		bool isappear = false;		//�o���ς݂�

		switch (emynum)
		{
		case memini:
			enemymanager->m_EmyId_Data = memini;
			break;
		case nil:
			enemymanager->m_EmyId_Data = nil;
			break;
		case spero:
			enemymanager->m_EmyId_Data = spero;
			break;
		case ira:
			enemymanager->m_EmyId_Data = ira;
			break;
		}

		//�I�΂ꂽEmy�����łɏo���ς݂����ׂ�
		if (enemymanager->m_IsAppear[enemymanager->m_EmyId_Data])
		{
			isappear = true;
		}

		//�o���ςłȂ��Ȃ�o���Z�b�g
		if (!isappear)
		{
			enemymanager->m_CanAppear = false;	//�o�����X�g�b�v
		}
	}

	void EnemyManager::AppearCount()
	{
		enemymanager->m_AppearCount -= enemymanager->m_COUNT_DECREMENT;		//�o���܂ł̃J�E���g���J�n

		if (enemymanager->m_AppearCount <= 0.0f)		//�K��l�ɒB������G�̏o��
		{
			EnemyAppear();
		}
	}

	void EnemyManager::EnemyAppear()
	{
		enemymanager->m_IsAppear[enemymanager->m_EmyId_Data] = true;	//�I�΂ꂽ�G�̏o��
		enemymanager->m_CanAppear = true;								//�G�̏o�����ĂъJ�n
		enemymanager->m_AppearNumNow++;									//�o�����̓G�����v�Z
		enemymanager->m_AppearCount = enemymanager->m_APPEARCOUNT_MAX;	//�J�E���g��������
	}

	void EnemyManager::D_DrawStatus()
	{
		//�폜�\��
		DrawFormatString(0, 500, GetColor(255, 255, 255), "�o���J�E���g:%f", enemymanager->m_AppearCount);
		DrawFormatString(0, 520, GetColor(255, 255, 255), "�G�o����:%d", enemymanager->m_AppearNumNow);
	}
}
#include <Dxlib.h>
#include <ctime>
#include "EnemyManager.h"

namespace object
{
	//実体を空に
	std::unique_ptr<EnemyManager>EnemyManager::enemymanager = nullptr;

	EnemyManager::EnemyManager()
		:m_AppearNumNow(0)
	{
		//処理なし
	}

	EnemyManager::~EnemyManager()
	{
	}

	void EnemyManager::Initialize()
	{
		//実態が空ならインスタンス生成
		if (!enemymanager)
		{
			enemymanager.reset(new EnemyManager);
		}

		LoadObjec();
	}

	void EnemyManager::LoadObjec()
	{
		//ランダム生成の初期化
		srand(static_cast<unsigned int>(time(0)));

		//カウント値の初期化
		enemymanager->m_AppearCount = enemymanager->m_APPEARCOUNT_MAX;

		enemymanager->m_IsAppear[memini] = false;
		enemymanager->m_IsAppear[nil] = false;
		enemymanager->m_IsAppear[spero] = false;
		enemymanager->m_IsAppear[ira] = false;

		enemymanager->m_AppearNumNow = 0;

		enemymanager->m_CanAppear = true;				//出現できるか
		enemymanager->m_BeefUpEmy_IsAction = false;		//特定の敵のアクションフラグ
		enemymanager->m_CanMove = true;					//動ける状態か

	}

	void EnemyManager::EmyAppearSetting()
	{
		//敵が出現可能な時
		if (enemymanager->m_CanAppear)
		{
			//画面内の敵総数がm_EMYSCREEN_MAXを超えてなかったら
			if (enemymanager->m_AppearNumNow < m_EMYSCREEN_MAX)
			{
				EmyRandlSetting();
			}
		}

		//出現がストップされたら
		if (!enemymanager->m_CanAppear)
		{
			AppearCount();
		}
	}

	void EnemyManager::EmyRandlSetting()
	{
		int range = m_APPEAR_RANGE;	//排出する敵をランダムで決定
		int emynum = rand() % range;

		bool isappear = false;		//出現済みか

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

		//選ばれたEmyがすでに出現済みか調べる
		if (enemymanager->m_IsAppear[enemymanager->m_EmyId_Data])
		{
			isappear = true;
		}

		//出現済でないなら出現セット
		if (!isappear)
		{
			enemymanager->m_CanAppear = false;	//出現をストップ
		}
	}

	void EnemyManager::AppearCount()
	{
		enemymanager->m_AppearCount -= enemymanager->m_COUNT_DECREMENT;		//出現までのカウントを開始

		if (enemymanager->m_AppearCount <= 0.0f)		//規定値に達したら敵の出現
		{
			EnemyAppear();
		}
	}

	void EnemyManager::EnemyAppear()
	{
		enemymanager->m_IsAppear[enemymanager->m_EmyId_Data] = true;	//選ばれた敵の出現
		enemymanager->m_CanAppear = true;								//敵の出現を再び開始
		enemymanager->m_AppearNumNow++;									//出現中の敵総数計算
		enemymanager->m_AppearCount = enemymanager->m_APPEARCOUNT_MAX;	//カウントを初期化
	}

	void EnemyManager::D_DrawStatus()
	{
		//削除予定
		DrawFormatString(0, 500, GetColor(255, 255, 255), "出現カウント:%f", enemymanager->m_AppearCount);
		DrawFormatString(0, 520, GetColor(255, 255, 255), "敵出現数:%d", enemymanager->m_AppearNumNow);
	}
}

#include "EnemyAction.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../EnemyManager/EnemyManager.h"

namespace object
{
	EnemyAction::EnemyAction()
		:ObjectBase(global_objecttag.ENEMYACTION)
	{
		//読み込み関連
		LoadObject();
	}

	EnemyAction::~EnemyAction()
	{
		//処理無し
	}

	void EnemyAction::LoadObject()
	{
		m_ObjPos = { 0.0 };

		m_EmyActionImg[0] = LoadGraph("../Asset/image/enemy/memini/place_3.png");
		m_EmyActionImg[1] = LoadGraph("../Asset/image/enemy/nil/place_3.png");
		m_EmyActionImg[2] = LoadGraph("../Asset/image/enemy/spero/place_3.png");
		m_EmyActionImg[3] = LoadGraph("../Asset/image/enemy/familia/place_2.png");
	}

	void EnemyAction::UpdateObj(const float deltatime)
	{
		//敵がアクションラインに到達したか
		if (!EnemyManager::GetEmyIsAction())
			return;

		EnemyID id=EnemyManager::GetEmyIDAction();

		switch (id)
		{
		case memini:
			m_ObjHandle = m_EmyActionImg[0];
			break;
		case nil:
			m_ObjHandle = m_EmyActionImg[1];
			break;
		case spero:
			m_ObjHandle = m_EmyActionImg[2];
			break;
		case familia:
			m_ObjHandle = m_EmyActionImg[3];
			break;
		}
	}

	void EnemyAction::DrawObj()
	{
		//敵がアクションラインに到達したか
		if (!EnemyManager::GetEmyIsAction())
			return;

		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}

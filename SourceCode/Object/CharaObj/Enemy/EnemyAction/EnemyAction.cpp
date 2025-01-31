#include "EnemyAction.h"
#include "../EnemyManager/EnemyManager.h"
#include "../../../Time/TimeStatus/TimeStatus.h"
#include "../../../ObjectManager/ObjectManager.h"
#include "../../../../SoundController/SoundController.h"

namespace object
{
	EnemyAction::EnemyAction()
		:ObjectBase(play_ObjectTag.ENEMYACTION)
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
		m_ObjHandle = 0;
		m_ObjPos = { 0.0 };
		m_EmyActionImg[0] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetMeminiData(3).c_str());
		m_EmyActionImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetNilData(3).c_str());
		m_EmyActionImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetSperoData(3).c_str());
		m_EmyActionImg[3] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetFamiliaData(2).c_str());

		sound_controller::SoundController::AddSoundData("../Asset/sound/play/enemy.mp3", "enemy", 250, false);
		sound_controller::SoundController::AddSoundData("../Asset/sound/play/emyaction.mp3", "emyaction", 180, false);
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

		//タイムオーバーしていたら専用演出
		if (TimeStatus::GetIsTimeOver())
		{
			ObjectManager::SetNextGameState(TimeOver);
		}

		sound_controller::SoundController::StartSound("enemy");
		sound_controller::SoundController::StartSound("emyaction");
	}

	void EnemyAction::DrawObj()
	{
		//敵がアクションラインに到達したか
		if (!EnemyManager::GetEmyIsAction())
			return;

		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}

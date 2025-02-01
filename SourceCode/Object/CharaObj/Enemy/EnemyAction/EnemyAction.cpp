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
		DeleteGraph(m_ObjHandle);

		for (int i = 0; i < 4; i++)
		{
			DeleteGraph(m_EmyActionImg[i]);
		}
	}

	void EnemyAction::LoadObject()
	{
		m_ObjHandle = 0;
		m_ObjPos = { 0.0 };
		m_EmyActionImg[0] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetMeminiData(3).c_str());
		m_EmyActionImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetNilData(3).c_str());
		m_EmyActionImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetSperoData(3).c_str());
		m_EmyActionImg[3] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetFamiliaData(2).c_str());

		auto json = JsonManager::SoundData_Instance()->Get_Play_SoundData_Instance();
		m_JsonTag[0] = json->GeyEnemy_NameData();
		m_JsonTag[1] = json->GetEmyAction_NameData();
		sound_controller::SoundController::AddSoundData(json->GetEnemy_PathData(), m_JsonTag[0], json->GeyEnemy_VolumeData(), json->GeyEnemy_TypeData());
		sound_controller::SoundController::AddSoundData(json->GetEmyAction_PathData(), m_JsonTag[1], json->GetEmyAction_VolumeData(), json->GetEmyAction_TypeData());
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

		sound_controller::SoundController::StartSound(m_JsonTag[0]);
		sound_controller::SoundController::StartSound(m_JsonTag[1]);
	}

	void EnemyAction::DrawObj()
	{
		//敵がアクションラインに到達したか
		if (!EnemyManager::GetEmyIsAction())
			return;

		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}

#include "SelectMode.h"
#include "../../ObjectTag/TitleObjectTag.h"
#include "../../../SoundController/SoundController.h"

namespace object
{
	SelectMode::SelectMode()
		:MouseBase(titleObjectTag.TITLEUI)
	{
		//読み込み関連
		LoadObject();
	}

	SelectMode::~SelectMode()
	{
		DeleteGraph(m_ObjHandle);
		DeleteGraph(m_MenuHandol);

		m_HitPos.clear();
		m_SelectMenuPos.clear();
	}

	void SelectMode::LoadObject()
	{
		m_ObjPos = {0,0};
		m_ObjSize = { 600,80 };

		m_SelectPos = { 537.0f,437.0f };
		m_MenuPos = { 700.0f,250.0f };

		m_SelectIndex = 0;
		//クリック可能状態
		m_CanClick = true;


		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_TitleData_Instance()->GetSelectData().c_str());
		m_MenuHandol= LoadGraph(JsonManager::ImgData_Instance()->Get_TitleData_Instance()->GetMenuData().c_str());

		auto json = JsonManager::SoundData_Instance()->Get_Title_SoundData_Instance();
		m_JsonTag[0] = json->GetBgmNameData();
		m_JsonTag[1] = json->GetSelect_NameData();
		m_JsonTag[2] = json->GetButton_NameData();
		m_JsonTag[3] = json->GetTransition_NameData();
		sound_controller::SoundController::AddSoundData(json->GetBgmPathData(), m_JsonTag[0], json->GetBgmVolumeData(), json->GetBgmTypeData());
		sound_controller::SoundController::AddSoundData(json->GetSelect_PathData(), m_JsonTag[1], json->GetSelect_VolumeData(), json->GetSelect_TypeData());
		sound_controller::SoundController::AddSoundData(json->GetButton_PathData(), m_JsonTag[2], json->GetButton_VolumeData(), json->GetButton_TypeData());
		sound_controller::SoundController::AddSoundData(json->GetTransition_PathData(), m_JsonTag[3], json->GetTransition_VolumeData(), json->GetTransition_TypeData());
	}

	void SelectMode::UpdateObj(const float deltatime)
	{
		sound_controller::SoundController::StartSound(m_JsonTag[0]);

		m_SelectIndex = 0;
		for (int i = 0; i < 3; i++)
		{
			//マウスがエリア移動の位置にあるか
			m_ObjPos.x = m_HitPos[i].x;
			m_ObjPos.y = m_HitPos[i].y;

			//マウスとの当たり判定
			CursorHit();

			//カーソルに当たっていたら
			if (GetCursorHit())
			{
				CanClick();
				m_SelectPos.x = m_SelectMenuPos[i].x;
				m_SelectPos.y = m_SelectMenuPos[i].y;
				if (index != m_SelectIndex)
				{
					index = m_SelectIndex;
					sound_controller::SoundController::StartSound(m_JsonTag[1]);
				}
			}
			//アイテムをクリックしたら
			if (GetStateClick() && GetCursorHit())
			{
				GameStatus status;
				PlayMenu menu;

				switch (m_SelectIndex)
				{
				case PlayMenu::PlayTutorial:
					menu = PlayMenu::PlayTutorial;
					status = GameStatus::Tutorial;
					break;
				case PlayMenu::PlayNewGame:
					menu = PlayMenu::PlayNewGame;
					status = GameStatus::Still;
					break;
				case PlayMenu::PlayRankingMode:
					menu = PlayMenu::PlayRankingMode;
					status = GameStatus::GamePlay;
					break;
				}

				if (menu == PlayMenu::PlayNewGame)
				{
					sound_controller::SoundController::StartSound(m_JsonTag[3]);
				}
				else
				{
					sound_controller::SoundController::StartSound(m_JsonTag[2]);
				}

				WaitTimer(240);

				ObjectManager::SetPlayMode(menu);
				ObjectManager::SetNextGameState(status);
			}
			else
			{
				m_SelectIndex++;
			}
		}
	}

	void SelectMode::DrawObj()
	{
		//画像の表示
		DrawGraph(static_cast<int>(m_SelectPos.x), static_cast<int>(m_SelectPos.y), m_ObjHandle, TRUE);
		DrawGraph(static_cast<int>(m_MenuPos.x), static_cast<int>(m_MenuPos.y), m_MenuHandol, TRUE);

#if DEBUG
		for (int i = 0; i < 3; i++)
		{
			DrawBox(static_cast<int>(m_HitPos[i].x), static_cast<int>(m_HitPos[i].y), static_cast<int>(m_HitPos[i].x) + m_ObjSize.x, static_cast<int>(m_HitPos[i].y) + m_ObjSize.y, GetColor(255, 40, 0), FALSE);
		}
#endif
	}
}
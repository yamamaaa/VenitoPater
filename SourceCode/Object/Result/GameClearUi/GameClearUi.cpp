#include "GameClearUi.h"
#include "../../ObjectTag/GameClear_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"
#include "../../NumDays/NumDays.h"

namespace object
{
	GameClearUi::GameClearUi()
		:ObjectBase(gameClear_Objecttag.GAMECLEARUI)
	{
		//読み込み関連
		LoadObject();
	}

	GameClearUi::~GameClearUi()
	{
		//処理なし
	}

	void GameClearUi::LoadObject()
	{
		m_ObjPos = { 770 ,400 };
		m_DrawCount = m_DRAWCOUNT_MAX;
	}

	void GameClearUi::UpdateObj(const float deltatime)
	{
		//一定時間文字の表示
		if (m_DrawCount <= 0.0f)
		{
			//終わったらプレイモード別に次のゲームステータスを変更
			if (ObjectManager::GetPlayMode() == PlayMenu::PlayNewGame)
			{
				SetNextGame_Status();
			}
			else if (ObjectManager::GetPlayMode() == PlayMenu::PlayRankingMode)
			{
				//ObjectManager::SetNextGameState(GameStatus);
			}
		}
		else
		{
			m_DrawCount -= m_COUNT_DECREMENT;
		}
	}

	void GameClearUi::SetNextGame_Status()
	{
		//日数別によりクリア後のステータスをセット
		int day = NumDays::GetNumDays();
		GameStatus status;
		switch (day)
		{
		case 1:
			status = GameStatus::Story;
			break;
		case 2:
			status = GameStatus::Still;
			break;
		case 3:
			status = GameStatus::Still;
			break;
		}

		ObjectManager::SetNextGameState(status);
	}

	void GameClearUi::DrawObj()
	{
		SetFontSize(m_FONTSIZE);
		DrawFormatString(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), GetColor(m_CORRER_CODE, m_CORRER_CODE, m_CORRER_CODE), "5 : 0");

#ifdef DEBUG
		SetFontSize(m_DEBUG_FONTSIZE);
		DrawFormatString(0, 0, GetColor(255, 255, 255), "表示時間 : %f", m_DrawCount);
#endif // DEBUG
	}
}
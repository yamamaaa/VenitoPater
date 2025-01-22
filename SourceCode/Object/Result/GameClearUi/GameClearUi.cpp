#include "GameClearUi.h"
#include "../../ObjectTag/GameClear_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
	GameClearUi::GameClearUi()
		:ObjectBase(gameClear_Objecttag.GAMECLEARUI)
	{
		//ì«Ç›çûÇ›ä÷òA
		LoadObject();
	}

	GameClearUi::~GameClearUi()
	{
		//èàóùÇ»Çµ
	}

	void GameClearUi::LoadObject()
	{
		m_ObjPos = { 770 ,400 };
		m_DrawCount = m_DRAWCOUNT_MAX;
	}

	void GameClearUi::UpdateObj(const float deltatime)
	{
		if (m_DrawCount <= 0.0f)
		{
			ObjectManager::SetNextGameState(GamePlay);
		}
		else
		{
			m_DrawCount -= m_COUNT_DECREMENT;
		}
	}

	void GameClearUi::DrawObj()
	{
		SetFontSize(150);
		DrawFormatString(m_ObjPos.x, m_ObjPos.y, GetColor(255, 255, 255), "6 : 0");

#ifdef DEBUG
		SetFontSize(16);
		DrawFormatString(0, 0, GetColor(255, 255, 255), "ï\é¶éûä‘ : %f", m_DrawCount);
#endif // DEBUG
	}
}
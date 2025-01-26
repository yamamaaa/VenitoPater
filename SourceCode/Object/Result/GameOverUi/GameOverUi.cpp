#include "GameOverUi.h"
#include "../../ObjectTag/GameOver_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
	GameOverUi::GameOverUi()
		:MouseBase(gameOver_ObjectTag.GAMEOVERUI)
	{
		//読み込み関連
		LoadObject();
	}

	GameOverUi::~GameOverUi()
	{
		//処理なし
	}

	void GameOverUi::LoadObject()
	{
		m_ResultLogo_Pos = { 750 ,400 };

		m_SelectUi_Pos[0] = { 440, 800 };
		m_SelectUi_Pos[1] = { 1200, 800 };

		m_ObjSize = { 300,100 };

		m_UiOffset[0] = { 50,30 };
		m_UiOffset[1] = { 70,30 };

		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_ResultData_Instance()->GetOverData_Select().c_str());

		m_Uipos.x = m_SelectUi_Pos[0].x;
		m_Uipos.y = m_SelectUi_Pos[0].y;
	}

	void GameOverUi::UpdateObj(const float deltatime)
	{
		//マウスがエリア移動の位置にあるか

		for (int i = 0; i < 2; i++)
		{
			m_ObjPos.x = m_SelectUi_Pos[i].x;
			m_ObjPos.y = m_SelectUi_Pos[i].y;

			m_ObjSize.x = m_ObjSize.x;
			m_ObjSize.y = m_ObjSize.y;

			//マウスとの当たり判定
			CursorHit();
			CanClick();

			if (GetCursorHit())
			{
				if (i == 0)	//コンテニューなら
				{
#ifdef DEBUG
					m_selectstatus = "コンテニュー";
#endif // DEBUG
					m_Uipos.x = m_SelectUi_Pos[0].x;
					m_Uipos.y = m_SelectUi_Pos[0].y;
				}
				else if (i == 1)//タイトルに戻るなら
				{
#ifdef DEBUG
					m_selectstatus = "タイトル";
#endif // DEBUG
					m_Uipos.x = m_SelectUi_Pos[1].x;
					m_Uipos.y = m_SelectUi_Pos[1].y;
				}

				//アイテムをクリックしたら
				if (GetStateClick())
				{
					if (i == 0)	//コンテニューなら
					{
						ObjectManager::SetNextGameState(Continue);
					}
					else		//タイトルに戻るなら
					{
						ObjectManager::SetNextGameState(Title);
					}
				}
			}
		}
	}

	void GameOverUi::DrawObj()
	{
		//SetFontSize(100);
		DrawFormatString(m_ResultLogo_Pos.x, m_ResultLogo_Pos.y, GetColor(255, 255, 255), "GameOver");

		DrawGraph(static_cast<int>(m_Uipos.x), static_cast<int>(m_Uipos.y),m_ObjHandle, TRUE);

		//SetFontSize(30);
		DrawFormatString(m_SelectUi_Pos[0].x+ m_UiOffset[0].x, m_SelectUi_Pos[0].y + m_UiOffset[0].y, GetColor(255, 255, 255), "コンテニュー");
		DrawFormatString(m_SelectUi_Pos[1].x + m_UiOffset[1].x, m_SelectUi_Pos[1].y + m_UiOffset[1].y, GetColor(255, 255, 255), "タイトルへ");

		DrawBox(m_SelectUi_Pos[0].x, m_SelectUi_Pos[0].y, m_SelectUi_Pos[0].x + m_ObjSize.x, m_SelectUi_Pos[0].y + m_ObjSize.y, GetColor(255,0,0),FALSE);

		DrawBox(m_SelectUi_Pos[1].x, m_SelectUi_Pos[1].y, m_SelectUi_Pos[1].x + m_ObjSize.x, m_SelectUi_Pos[1].y + m_ObjSize.y, GetColor(0, 255, 0),FALSE);

#ifdef DEBUG
		DrawFormatString(0, 20, GetColor(255, 255, 255), "セレクト状態:%s", m_selectstatus.c_str());
#endif // DEBUG
	}
}
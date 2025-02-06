#include "Menu.h"
#include"../../Object/ObjectTag/Play_ObjectTag.h"
#include"../../MouseStatus/MouseStatus.h"
#include"../../SoundController/SoundController.h"

namespace object
{
	Menu::Menu()
		:MouseBase(play_ObjectTag.MENU)
	{
		//読み込み関連
		LoadObject();
	}

	Menu::~Menu()
	{
		DeleteGraph(m_IconImg);
		DeleteGraph(m_MenuBack_Img);
		DeleteGraph(m_SelectImg);
	}

	void Menu::LoadObject()
	{
		m_IsMenuMode = false;

		m_MenuBack_Pos = { 1290.0f,0.0f };

		m_SelectPos_Offset = { -20.0f,50.0f };

		m_IconHitPos = { 1875.0f, 5.0f, };
		m_IconHit_Size = { 50,50 };

		m_BackHit_Pos = { 1410.0f,30.0f };
		m_BackHit_Size = { 100,60 };

		m_MenuHit_Pos.push_back({ 1485.0f,350.0f });
		m_MenuHit_Pos.push_back({ 1485.0f,580.0f });
		m_MenuHit_Size = { 300,50 };

		m_IconImg= LoadGraph("../Asset/image/menu/icon.png");
		m_MenuBack_Img= LoadGraph("../Asset/image/menu/menuback.png");
		m_SelectImg= LoadGraph("../Asset/image/menu/select.png");

		m_JsonTag[0] = "selectmenu";
		m_JsonTag[1] = "buttonmenu";

		sound_controller::SoundController::AddSoundData("../Asset/sound/menu/selsect.mp3", m_JsonTag[0], 130, false);
		sound_controller::SoundController::AddSoundData("../Asset/sound/menu/button.mp3", m_JsonTag[1], 130, false);
	}

	void Menu::UpdateObj(const float deltatime)
	{
		if (!mousestatus::MouseStatus::GetIsFadeDone())
			return;

		if (!m_IsMenuMode)
		{
			if (ClickDetect(m_IconHitPos, m_IconHit_Size))
			{
				sound_controller::SoundController::StartSound(m_JsonTag[0]);
				m_IsMenuMode = true;
				mousestatus::MouseStatus::SetIsMenuMode(true);
			}
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				if (CursorDetect(m_MenuHit_Pos[i], m_MenuHit_Size))
				{
					if (i != m_HitIndex)
					{
						m_HitIndex = i;
						sound_controller::SoundController::StartSound(m_JsonTag[0]);
					}
				}
				if (ClickDetect(m_MenuHit_Pos[i], m_MenuHit_Size))
				{
					sound_controller::SoundController::StartSound(m_JsonTag[1]);
					GameStatusSet();
					mousestatus::MouseStatus::SetIsMenuMode(false);
				}
			}

			if (ClickDetect(m_BackHit_Pos, m_BackHit_Size))
			{
				sound_controller::SoundController::StartSound(m_JsonTag[1]);
				mousestatus::MouseStatus::SetIsMenuMode(false);
				m_IsMenuMode = false;
			}
		}
	}

	bool Menu::ClickDetect(POINTFLOAT& objpos,POINTS& objsize)
	{
		m_ObjPos = objpos;
		m_ObjSize = objsize;

		//マウスとの当たり判定
		CursorHit();
		CanClick();

		//当たっていたら
		if (GetStateClick() && GetCursorHit())
		{
			return true;
		}

		return false;
	}

	bool Menu::CursorDetect(POINTFLOAT& objpos, POINTS& objsize)
	{
		m_ObjPos = objpos;
		m_ObjSize = objsize;

		CursorHit();

		if (GetCursorHit())
		{
			return true;
		}
		return false;
	}

	void Menu::GameStatusSet()
	{
		switch (m_HitIndex)
		{
		case 0:
			ObjectManager::SetNextGameState(GameStatus::Title);
			break;
		case 1:
			ObjectManager::SetNextGameState(GameStatus::GameEnd);
			break;
		}
	}

	void Menu::DrawObj()
	{
		DrawGraphF(m_IconHitPos.x, m_IconHitPos.y, m_IconImg, TRUE);

		if (m_IsMenuMode)
		{
			DrawGraphF(m_MenuBack_Pos.x, m_MenuBack_Pos.y, m_MenuBack_Img, TRUE);

			POINTFLOAT selectpos = m_MenuHit_Pos[m_HitIndex] + m_SelectPos_Offset;
			DrawGraphF(selectpos.x , selectpos.y, m_SelectImg, TRUE);
#if DEBUG

			for (POINTFLOAT pos : m_MenuHit_Pos)
			{
				DrawBox(static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(pos.x) + m_MenuHit_Size.x, static_cast<int>(pos.y) + m_MenuHit_Size.y, GetColor(255, 40, 0), FALSE);
			}
			DrawBox(static_cast<int>(m_BackHit_Pos.x), static_cast<int>(m_BackHit_Pos.y), static_cast<int>(m_BackHit_Pos.x) + m_BackHit_Size.x, static_cast<int>(m_BackHit_Pos.y) + m_BackHit_Size.y, GetColor(255, 40, 0), FALSE);
#endif
		}
#if DEBUG
		DrawBox(static_cast<int>(m_IconHitPos.x), static_cast<int>(m_IconHitPos.y), static_cast<int>(m_IconHitPos.x) + m_IconHit_Size.x, static_cast<int>(m_IconHitPos.y) + m_IconHit_Size.y, GetColor(255, 40, 0), FALSE);
#endif
	}
}
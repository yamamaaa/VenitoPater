#include "TutorialUi.h"
#include"../ObjectTag/Tutorial_ObjectTag.h"
#include"../ObjectManager/ObjectManager.h"
#include"../../MouseStatus/MouseStatus.h"
#include"../../SoundController/SoundController.h"

namespace object
{
	TutorialUi::TutorialUi()
		:MouseBase(tutorial_ObjectTag.TUTORIALUI)
	{
		//読み込み関連
		LoadObject();
	}

	TutorialUi::~TutorialUi()
	{
	}

	void TutorialUi::LoadObject()
	{
		m_HitIndex = 0;

		for (int i = 0; i < 6; i++)
		{
			m_MenuHit_Pos.push_back({320.0f* static_cast<float>(i),902.0f});
		}

		m_BackHit_Pos = { 0.0f,20.0f };

		m_MenuHit_Size= { 320,500 };
		m_BackHit_Size = {170,120 };

		m_SelectPos = {0.0f,817.0f};

		m_BackImg = LoadGraph("../Asset/image/tutorial/back.png");

		m_Tutorial_Img.push_back(LoadGraph("../Asset/image/tutorial/select_0.png"));
		m_Tutorial_Img.push_back(LoadGraph("../Asset/image/tutorial/select_1.png"));
		m_Tutorial_Img.push_back(LoadGraph("../Asset/image/tutorial/select_2.png"));
		m_Tutorial_Img.push_back(LoadGraph("../Asset/image/tutorial/select_3.png"));
		m_Tutorial_Img.push_back(LoadGraph("../Asset/image/tutorial/select_4.png"));
		m_Tutorial_Img.push_back(LoadGraph("../Asset/image/tutorial/select_5.png"));

		m_MenuImg = LoadGraph("../Asset/image/tutorial/menu.png");
		m_SelectImg = LoadGraph("../Asset/image/tutorial/selectmenu.png");

		auto json = JsonManager::SoundData_Instance()->Get_Tutorial_SoundData_Instance();
		m_JsonTag[0] = json->GetBgmNameData();
		m_JsonTag[1] = json->GetBack_NameData();
		m_JsonTag[2] = json->GetButton_NameData();

		sound_controller::SoundController::AddSoundData(json->GetBgmPathData(), m_JsonTag[0], json->GetBgmVolumeData(), json->GetBgmTypeData());
		sound_controller::SoundController::AddSoundData(json->GetBack_PathData(), m_JsonTag[1], json->GetBack_VolumeData(), json->GetBack_TypeData());
		sound_controller::SoundController::AddSoundData(json->GetButton_PathData(), m_JsonTag[2], json->GetButton_VolumeData(), json->GetButton_TypeData());

		//クリック可能状態
		m_CanClick = true;
	}

	void TutorialUi::UpdateObj(const float deltatime)
	{
		sound_controller::SoundController::StartSound(m_JsonTag[0]);

		if (!mousestatus::MouseStatus::GetIsFadeDone())
			return;

		static int index;
		for (int i = 0; i < 6; i++)
		{
			//マウスがメニューボタンの位置にあるか
			m_ObjPos = m_MenuHit_Pos[i];
			m_ObjSize = m_MenuHit_Size;

			//マウスとの当たり判定
			CursorHit();

			//カーソルに当たっていたら
			if (GetCursorHit())
			{
				m_HitIndex = i;
				if (index != m_HitIndex)
				{
					index = m_HitIndex;
					sound_controller::SoundController::StartSound(m_JsonTag[2]);
				}
			}
		}

		m_ObjPos = m_BackHit_Pos;
		m_ObjSize = m_BackHit_Size;

		//マウスとの当たり判定
		CursorHit();
		CanClick();

		//カーソルに当たっていたら
		if(GetStateClick() && GetCursorHit())
		{
			ObjectManager::SetNextGameState(GameStatus::Title);
			sound_controller::SoundController::StartSound(m_JsonTag[1]);
		}
	}

	void TutorialUi::DrawObj()
	{
		DrawGraph(0, 0, m_Tutorial_Img[m_HitIndex], TRUE);
		DrawGraphF(m_SelectPos.x, m_SelectPos.y, m_MenuImg, TRUE);
		DrawGraphF(m_BackHit_Pos.x, m_BackHit_Pos.y, m_BackImg, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_SelectImg_Color);
		DrawGraphF(m_MenuHit_Pos[m_HitIndex].x, m_MenuHit_Pos[m_HitIndex].y, m_SelectImg, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

#ifdef DEBUG
		for (int i = 0; i < 6; i++)
		{
			DrawBox(static_cast<int>(m_MenuHit_Pos[i].x), static_cast<int>(m_MenuHit_Pos[i].y), static_cast<int>(m_MenuHit_Pos[i].x) + m_MenuHit_Size.x, static_cast<int>(m_MenuHit_Pos[i].y) + m_MenuHit_Size.y, GetColor(255, 40, 0), FALSE);
		}

		DrawBox(static_cast<int>(m_BackHit_Pos.x), static_cast<int>(m_BackHit_Pos.y), static_cast<int>(m_BackHit_Pos.x) + m_BackHit_Size.x, static_cast<int>(m_BackHit_Pos.y) + m_BackHit_Size.y, GetColor(255, 40, 0), FALSE);
#endif
	}
}
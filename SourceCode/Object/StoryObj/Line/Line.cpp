﻿#include "Line.h"
#include"../../ObjectTag/Story_ObjectTag.h"
#include"../LineStatus/LineStatus.h"
#include"../../ObjectManager/ObjectManager.h"
#include"../../../MouseStatus/MouseStatus.h"
#include"../../../NumDays/NumDays.h"
#include"../../../SoundController/SoundController.h"

namespace object
{
	Line::Line()
		:ObjectBase(story_ObjectTag.LINE)
	{
		//読み込み関連
		LoadObject();
	}

	Line::~Line()
	{
		m_TxtFile.close();
		//フォントのアンロード
		DeleteFontToHandle(m_FontHandle);
	}

	void Line::LoadObject()
	{
		m_IsClick = true;
		m_IsLineSet =false;
		m_IslineAnim =false;
		m_IsWeitMode = false;
		m_IsClickUi = false;
		m_IsLineDone = false;
		m_IsMove_Up = false;
		m_IsSound_Start = false;
		m_IsFirst = true;

		LineStatus::SetIsDoneAnim(false);

		m_TxtNum = 0;
		m_AnimCount = 0.0f;
		m_ClickCount = 0.0f;
		m_ObjPos = { 0.0f,875.0f };
		m_UiPos = m_UIPOS_RESET;
		m_NowColor = m_COLOR_DEFAULT;
		m_AnimSpeed = m_SPEED_DEFAULT;

		//現在のゲームステータスを取得
		GameStatus status=ObjectManager::GetNowGameState();

		auto json = JsonManager::SoundData_Instance()->Get_Story_SoundData_Instance();

		//日数別に読み込むファイルを変更
		int dey = NumDays::GetNumDays();
		std::string text;
		if (status == Story)
		{
			switch (dey)
			{
			case 0:
				text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetLineData_Day_0();
				break;
			case 1:
				text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetLineData_Day_1();
				break;
			case 4:
				text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetLineData_Day_4();
				break;
			}

			m_JsonTag[0] = json->GetStory_NameData();
			sound_controller::SoundController::AddSoundData(json->GetStory_PathData(), m_JsonTag[0], json->GetStory_VolumeData(), json->GetStory_TypeData());
		}
		if (status == Still)
		{
			switch (dey)
			{
			case 0:
				m_JsonTag[0] = json->GetStill_Day_0_NameData();
				sound_controller::SoundController::AddSoundData(json->GetStill_Day_0_PathData(), m_JsonTag[0], json->GetStill_Day_0_VolumeData(), json->GetStill_Day_0_TypeData());
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_0();
				break;
			case 1:
				m_JsonTag[0] = json->GetStill_Day_1_NameData();
				sound_controller::SoundController::AddSoundData(json->GetStill_Day_1_PathData(), m_JsonTag[0], json->GetStill_Day_1_VolumeData(), json->GetStill_Day_1_TypeData());
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_1();
				break;
			case 2:
				m_JsonTag[0] = json->GetStill_Day_2_NameData();
				sound_controller::SoundController::AddSoundData(json->GetStill_Day_2_PathData(), m_JsonTag[0], json->GetStill_Day_2_VolumeData(), json->GetStill_Day_2_TypeData());
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_2();
				break;
			case 3:
				m_JsonTag[0] = json->GetStill_Day_3_NameData();
				sound_controller::SoundController::AddSoundData(json->GetStill_Day_3_PathData(), m_JsonTag[0], json->GetStill_Day_3_VolumeData(), json->GetStill_Day_3_TypeData());
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_3();
				break;
			case 4:
				m_JsonTag[0] = json->GetStill_Day_4_NameData();
				sound_controller::SoundController::AddSoundData(json->GetStill_Day_4_PathData(), m_JsonTag[0], json->GetStill_Day_4_VolumeData(), json->GetStill_Day_4_TypeData());
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_4();
				break;
			}
		}

		//ファイルの読み込み
		m_TxtFile.open(text.c_str());

		m_JsonTag[1] = json->GetButtonNameData();
		sound_controller::SoundController::AddSoundData(json->GetButtonPathData(), m_JsonTag[1], json->GetButtonVolumeData(), json->GetButtonTypeData());

		m_FontHandle = CreateFontToHandle("メイリオ", 30, 5, DX_FONTTYPE_ANTIALIASING);

		if (m_FontHandle == -1)
		{
			//フォント読込エラー処理
			MessageBox(NULL, "FontErrer", "", MB_OK);
		}
	}

	void Line::UpdateObj(const float deltatime)
	{
		LineStatus::SetIsDoneAnim(false);

		if (m_IsSound_Start)
		{
			sound_controller::SoundController::StartSound(m_JsonTag[0]);
		}
		else
		{
			sound_controller::SoundController::StopSound(m_JsonTag[0]);
		}

		//入力状態が不可の時は処理なし
		if (!mousestatus::MouseStatus::GetIsFadeDone())
			return;

		//画像のセットが終わっていなかったら処理なし
		if (!LineStatus::GetIsDoneImgDraw())
			return;

		//クリックUiの更新
		if (m_IsLineDone)
		{
			if (m_IsClickUi)
			{
				ClickUiMoveAnim(deltatime);
			}
			return;
		}

		UpdateDrawStatus(deltatime);

		if (m_IslineAnim)
		{
			TextAnim(deltatime);
		}
		else
		{
			m_IsClickUi = true;
			ClickUiMoveAnim(deltatime);
		}
	}

	void Line::UpdateDrawStatus(const float deltatime)
	{
#if DEBUG
		//スペースキーでスキップ
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			if (m_Line == m_END)
			{
				Text_Processing(m_Line);
			}
			std::getline(m_TxtFile, m_Line);
		}
#endif // DEBUG

		ClickStatus();

		//クリックしたら
		if (!m_IsClick)
		{
			m_ClickCount -= m_COUNT_DECREMENT * deltatime;
			if (m_ClickCount <= 0.0f)
			{
				m_ClickCount = 0.0f;
				m_IsClick = true;
			}
		}

		//未セット状態なら
		if (!m_IsLineSet)
		{
			DrawTextSet();
		}
	}

	void Line::ClickStatus()
	{
		//文字のセットができていてクリック可能状態
		if (m_IsLineSet && m_IsClick)
		{
			//カウントモードなら自動切り替え
			if (m_IsWeitMode)
			{
				m_IsWeitMode = false;
				m_IsLineSet = false;
				m_IsClick = false;
			}
			else if (GetMouseInput() & MOUSE_INPUT_LEFT)
			{
				if (mousestatus::MouseStatus::GetIsMenuMode())
					return;

				//文字がアニメ中なら
				if (m_IslineAnim)
				{
					//文字をすべて表示する
					m_TxtNum = static_cast<int>(m_Line.size());
					m_IslineAnim = false;
				}
				else
				{
					//文字のセットを行う
					m_IsLineSet = false;
					sound_controller::SoundController::StartSound(m_JsonTag[1]);
				}
				m_IsClick = false;
				m_ClickCount = m_CLICKCOU_MAX;
			}
		}
	}

	void Line::DrawTextSet()
	{
		std::string line = "";

		//次の行を読み込み
		std::getline(m_TxtFile, line);

		if (line == m_END)	//ファイルの終わりならステータス変更
		{
			Text_Processing(line);
			m_IsLineDone = true;
		}

		if (m_IsLineDone)
			return;

		m_AnimSpeed = m_SPEED_DEFAULT;
		m_NowColor = m_COLOR_DEFAULT;

		bool status_set = false;
		if (line == "status")
		{
			status_set = true;
		}

		while (status_set)
		{
			//次の行を読み込み
			std::getline(m_TxtFile, line);
			if (line == "status")
			{
				status_set = false;
				std::getline(m_TxtFile, line);
			}
			else if (line == m_RED)
			{
				m_NowColor = m_COLOR_RED;
			}
			else if (line == m_SLOW)
			{
				m_AnimSpeed = m_SPEED_SLOW;
			}
			else if (line == "soundstop")
			{
				m_IsSound_Start = false;
			}
			else if (line == "soundstart")
			{
				m_IsSound_Start = true;
			}
		}

		//前の文字をクリア
		m_Line.clear();
		m_TxtNum = 0;

		if (line == "count")
		{
			//再度クリックできるまで持つ
			m_IsClick = false;
			m_IsWeitMode = true;
			m_ClickCount = m_CLICKCOU_WEIT;
		}
		else
		{
			m_Line = line;
		}

		m_IsLineSet = true;
		m_IslineAnim = true;
		m_IsClickUi = false;
		m_UiPos.y = m_UIPOS_RESET.y;

		if (m_IsFirst)
		{
			m_IsFirst = false;
		}
		else
		{
			LineStatus::SetIsDoneAnim(true);
		}
	}

	void Line::Text_Processing(std::string line)
	{
		//次の行を読み込み
		std::getline(m_TxtFile, line);
		if (line == m_DAY)
		{
			NumDays::UpdateNumDays();
		}

		//次の行を読み込み
		std::getline(m_TxtFile, line);
		if (line == m_GAMEPLAY)
		{
			ObjectManager::SetNextGameState(GamePlay);
		}
		if (line == m_STORY)
		{
      		ObjectManager::SetNextGameState(Story);
		}
		if (line == m_STILL)
		{
			ObjectManager::SetNextGameState(Still);
		}
		if (line == m_PLAYEND)
		{
			ObjectManager::SetNextGameState(PlayEnd);
		}
	}

	void Line::TextAnim(const float deltatime)
	{
		m_AnimCount += m_AnimSpeed;

		if (m_AnimCount >= m_ANIMFPS)
		{
			if (m_TxtNum == m_Line.size())
			{
				m_IslineAnim = false;
				m_AnimCount = 0.0f;
			}
			else
			{
				m_TxtNum++;
				m_AnimCount = 0.0f;
			}
		}
	}

	void Line::ClickUiMoveAnim(const float deltatime)
	{
		//現在のUi位置を取得
		float pos= m_UiPos.y;

		//上移動中なら少しずつ上がる処理
		if (m_IsMove_Up)
		{
			//位置が移動最大値を超えたら切り替え処理
			if (pos < m_UIPOS_RESET.y - m_MOVEPOS_MAX)
			{
				m_IsMove_Up = false;
			}
			else
			{
				pos -= m_MOVESPEED * deltatime;
			}
		}
		else
		{
			//少しずつ下がる処理
			if (pos > m_UIPOS_RESET.y + m_MOVEPOS_MAX)
			{
				m_IsMove_Up = true;
			}
			else
			{
				pos += m_MOVESPEED * deltatime;
			}
		}

		m_UiPos.y = pos;
	}

	void Line::DrawObj()
	{
		if (m_IsClickUi&&!m_IsWeitMode)
		{
			DrawStringToHandle(static_cast<int>(m_UiPos.x), static_cast<int>(m_UiPos.y), "▽", GetColor(static_cast<int>(m_COLOR_DEFAULT.x), static_cast<int>(m_COLOR_DEFAULT.y), static_cast<int>(m_COLOR_DEFAULT.z)), m_FontHandle);
		}

		//文字の長さを取得して画面中央に表示
		int x = GetDrawFormatStringWidthToHandle(m_FontHandle,m_Line.c_str(), -1);
		DrawStringToHandle((1920 - x) / 2, static_cast<int>(m_ObjPos.y), (m_Line.substr(0, m_TxtNum) + " ").c_str(), GetColor(static_cast<int>(m_NowColor.x), static_cast<int>(m_NowColor.y), static_cast<int>(m_NowColor.z)), m_FontHandle);

#if DEBUG
		DrawFormatString(0, 20, GetColor(255, 255, 255), "m_ClickCount:%f", m_ClickCount);
		DrawString(0, 100, "スペースでスキップ",GetColor(255, 255, 255));
#endif // DEBUG
	}
}

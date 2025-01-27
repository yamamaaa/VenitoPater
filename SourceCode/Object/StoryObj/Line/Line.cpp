#include "Line.h"
#include"../../ObjectTag/Story_ObjectTag.h"
#include"../LineStatus/LineStatus.h"
#include"../../ObjectManager/ObjectManager.h"
#include"../../NumDays/NumDays.h"

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
		m_IsFirst = true;

		LineStatus::SetIsDoneAnim(false);

		m_TxtNum = 0;
		m_AnimCount = 0.0f;
		m_ClickCount = 0.0f;
		m_ObjPos = { 0.0f,875.0f };
		m_UiPos = m_UIPOS_RESET;
		m_NowColor = m_COLOR_DEFAULT;
		m_AnimSpeed = m_SPEED_DEFAULT;

		m_StartCount = m_WAITCOU_MAX;

		//現在のゲームステータスを取得
		GameStatus status=ObjectManager::GetNextGameState();

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
		}
		if (status == Still)
		{
			switch (dey)
			{
			case 0:
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_0();
				break;
			case 1:
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_1();
				break;
			case 2:
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_2();
				break;
			case 3:
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_3();
				break;
			case 4:
				text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetLineData_Day_4();
				break;
			}
		}

		m_FontHandle = CreateFontToHandle("メイリオ", 30, 5, DX_FONTTYPE_ANTIALIASING);

		//ファイルの読み込み
		m_TxtFile.open(text.c_str());

		if (m_FontHandle == -1)
		{
			//フォント読込エラー処理
			MessageBox(NULL, "FontErrer", "", MB_OK);
		}
	}

	void Line::UpdateObj(const float deltatime)
	{
		LineStatus::SetIsDoneAnim(false);

		//スタートから表示までずらす
		if (!m_WaitDone)
		{
			m_StartCount -= m_COUNT_DECREMENT* deltatime;
			if (m_StartCount <= 0.0f)
			{
				m_WaitDone = true;
			}
			return;
		}

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
#ifdef DEBUG
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
				//文字がアニメ中なら
				if (m_IslineAnim)
				{
					//文字をすべて表示する
					m_TxtNum = m_Line.size();
					m_IslineAnim = false;
				}
				else
				{
					//文字のセットを行う
					m_IsLineSet = false;
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
		m_AnimCount += m_AnimSpeed* deltatime;
		if (m_AnimCount >= m_ANIMFPS)
		{
			if (m_TxtNum == m_Line.size())
			{
				m_IslineAnim = false;
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
		if (m_IsClickUi)
		{
			DrawStringToHandle(static_cast<int>(m_UiPos.x), static_cast<int>(m_UiPos.y), "▽", GetColor(static_cast<int>(m_COLOR_DEFAULT.x), static_cast<int>(m_COLOR_DEFAULT.y), static_cast<int>(m_COLOR_DEFAULT.z)), m_FontHandle);
		}

		//文字の長さを取得して画面中央に表示
		int x = GetDrawFormatStringWidthToHandle(m_FontHandle,m_Line.c_str(), -1);
		DrawStringToHandle((1920 - x) / 2, static_cast<int>(m_ObjPos.y), (m_Line.substr(0, m_TxtNum) + " ").c_str(), GetColor(static_cast<int>(m_NowColor.x), static_cast<int>(m_NowColor.y), static_cast<int>(m_NowColor.z)), m_FontHandle);

#ifdef DEBUG
		DrawFormatString(0, 20, GetColor(255, 255, 255), "m_ClickCount:%f", m_ClickCount);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "m_StartCount:%f", m_StartCount);
		DrawString(0, 100, "スペースでスキップ",GetColor(255, 255, 255));
#endif // DEBUG
	}
}

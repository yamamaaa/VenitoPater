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
		RemoveFontResource(m_FontTag.c_str());
	}

	void Line::LoadObject()
	{
		m_IsClick = true;
		m_IsLineSet = true;
		m_IslineAnim = true;
		m_IsWeitMode = false;
		m_IsLineDone = false;

		LineStatus::SetIsDoneAnim(false);

		m_TxtNum = 0;
		m_AnimCount = 0.0f;
		m_ClickCount = 0.0f;
		m_ObjPos = { 0,850 };
		m_NowCollar = m_COLLAR_DEFAULT;
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

		//ファイルの読み込み
		m_TxtFile.open(text.c_str());
		std::getline(m_TxtFile, m_Line);	//一行目読み込み

		auto t = JsonManager::FontData_Instance()->Get_StoryDat_Instance();

		//フォント名を取得
		std::ifstream fontname_data;
		fontname_data.open(t->Get_FontTagToChar());
		std::getline(fontname_data, m_FontTag);
		AddFontResourceEx(t->GetFontPath().c_str(), FR_PRIVATE, NULL);
		m_FontHandol = CreateFontToHandle(t->Get_FontTagToChar(), 30, 1, DX_FONTTYPE_ANTIALIASING_EDGE);

		if (m_FontHandol == -1)
		{
			//フォント読込エラー処理
			RemoveFontResource(m_FontTag.c_str());
			MessageBox(NULL, "FontErrer", "", MB_OK);
		}

		//fontname_data.close();

		SetFontSize(30);
	}

	void Line::UpdateObj(const float deltatime)
	{
		if (m_IsLineDone)
			return;

		//スタートから表示までずらす
		if (!m_WaitDone)
		{
			m_StartCount -= m_COUNT_DECREMENT;
			if (m_StartCount <= 0.0f)
			{
				m_WaitDone = true;
			}
			return;
		}

		UpdateDrawStatus();

		if (m_IslineAnim)
		{
			TextAnim();
		}
	}

	void Line::UpdateDrawStatus()
	{
		LineStatus::SetIsDoneAnim(false);

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
			m_ClickCount -= m_COUNT_DECREMENT;
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

		bool status_set = false;
		if (line == "status")
		{
			status_set = true;
		}
		else if(!m_IsLineDone)
		{
			m_NowCollar = m_COLLAR_DEFAULT;
			m_AnimSpeed = m_SPEED_DEFAULT;
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
				m_NowCollar = m_COLLAR_RED;
			}
			else if (line == m_SLOW)
			{
				m_AnimSpeed = m_SPEED_SLOW;
			}
		}

		if (line == m_END)	//ファイルの終わりならステータス変更
		{
			Text_Processing(line);
			m_IsLineDone = true;
		}
		else
		{
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
		}

		LineStatus::SetIsDoneAnim(true);
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
	}

	void Line::TextAnim()
	{
		m_AnimCount += m_AnimSpeed;
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

	void Line::DrawObj()
	{
		int x = GetDrawStringWidth(m_Line.c_str(), -1);
		DrawStringToHandle((1920 - x) / 2, static_cast<int>(m_ObjPos.y), (m_Line.substr(0, m_TxtNum) + " ").c_str(), GetColor(static_cast<int>(m_NowCollar.x), static_cast<int>(m_NowCollar.y), static_cast<int>(m_NowCollar.z)), m_FontHandol);

#ifdef DEBUG
		DrawFormatString(0, 20, GetColor(255, 255, 255), "m_ClickCount:%f", m_ClickCount);
		DrawString(0, 100, "スペースでスキップ",GetColor(255, 255, 255));
#endif // DEBUG
	}
}

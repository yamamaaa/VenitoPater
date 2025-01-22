#include "Line.h"
#include"../../ObjectTag/Story_ObjectTag.h"
#include"../LineStatus/LineStatus.h"
#include"../../ObjectManager/ObjectManager.h"
#include"../../NumDeys/NumDeys.h"

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
		if (RemoveFontResourceEx(m_FontPath, FR_PRIVATE, NULL)) {
		}
		else {
			MessageBox(NULL, "remove failure", "", MB_OK);
		}
	}

	void Line::LoadObject()
	{
		SetFontSize(30);		//フォントサイズ設定

		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetFlameData().c_str());

		m_IsClick = true;
		m_IsLineSet = true;
		m_IslineAnim = true;

		LineStatus::SetIsDoneAnim(false);

		m_TxtNum = 0;
		m_AnimCount = 0.0f;
		m_ClickCount = 0.0f;
		m_ObjPos = { 0,850 };
		m_NowCollar = m_COLLAR_DEFAULT;
		m_AnimSpeed = m_SPEED_DEFAULT;

		//現在のゲームステータスを取得
		GameStatus status=ObjectManager::GetNextGameState();

		//日数別に読み込むファイルを変更
		int dey = NumDeys::GetNumDeys();
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

		//フォントの読み込み
		/*std::string font = JsonManager::FontData_Instance()->Get_StoryDat_Instance()->GetFontData();
		m_FontPath = font.c_str();*/
		m_FontPath = "../Asset/font/story/ShinRetroMaruGothic-Medium.ttf";

		//フォントの読み込みができなかったら
		if (AddFontResourceEx(m_FontPath, FR_PRIVATE, NULL) > 0)
		{
		}
		else 
		{
			// フォント読込エラー処理
			MessageBox(NULL, "FontErrer", "", MB_OK);
		}

		//フォント名を取得
		std::ifstream fontname_data;
		std::string name;
		fontname_data.open(JsonManager::FontData_Instance()->Get_StoryDat_Instance()->Get_FontTagData().c_str());
		std::getline(fontname_data, name);
		//フォントをセット
		ChangeFont(name.c_str(), DX_CHARSET_DEFAULT);
		fontname_data.close();
	}

	void Line::UpdateObj(const float deltatime)
	{
		//文字のセットができていてクリック可能状態
		if (m_IsLineSet && m_IsClick)
		{
			if (GetMouseInput() & MOUSE_INPUT_LEFT)
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
			}
		}

		//クリックしたら
		if (!m_IsClick)
		{
			m_ClickCount += 0.1;
			if (m_ClickCount >= 5.0f)
			{
				m_ClickCount = 0.0f;
				m_IsClick = true;
			}
		}

		//未セット状態なら
		if (!m_IsLineSet)
		{
			//前の文字をクリア
			m_Line.clear();
			m_TxtNum = 0;
			m_NowCollar = m_COLLAR_DEFAULT;
			m_AnimSpeed = m_SPEED_DEFAULT;

			std::string line="";

			//次の行を読み込み
			std::getline(m_TxtFile, line);

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
					m_NowCollar = m_COLLAR_RED;
				}
				else if (line == m_SLOW)
				{
					m_AnimSpeed = m_SPEED_SLOW;
				}
			}

			if (line == m_END)	//ファイルの終わりならステータス変更
			{
				//次の行を読み込み
				std::getline(m_TxtFile, line);
				if (line == m_DAY)
				{
					NumDeys::UpdateNumDeys();
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
			else
			{
				m_Line = line;
			}

			m_IsLineSet = true;
			m_IslineAnim = true;

			LineStatus::SetIsDoneAnim(true);
		}

		if (m_IslineAnim)
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
	}

	void Line::DrawObj()
	{
		DrawGraph(0, 0, m_ObjHandle, TRUE);
		int x = GetDrawStringWidth(m_Line.c_str(), -1);
		DrawString((1920 - x) / 2, static_cast<int>(m_ObjPos.y), (m_Line.substr(0, m_TxtNum) + " ").c_str(), GetColor(static_cast<int>(m_NowCollar.x), static_cast<int>(m_NowCollar.y), static_cast<int>(m_NowCollar.z)));

#ifdef DEBUG
		DrawFormatString(0, 20, GetColor(255, 255, 255), "m_ClickCount:%f", m_ClickCount);
#endif // DEBUG
	}
}

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

		m_IsClick = true;
		m_IsLineSet = true;
		m_IslineAnim = true;

		LineStatus::SetIsDoneAnim(false);

		m_TxtNum = 0;
		m_AnimCount = 0.0f;
		m_ClickCount = 0.0f;
		m_ObjPos = { 0,800 };

		//現在のゲームステータスを取得
		GameStatus status=ObjectManager::GetGameState();

		//日数別に読み込むファイルを変更
		int dey = NumDeys::GetNumDeys();

		if (status == Story)
		{
			switch (dey)
			{
			case 0:
				m_TxtFile.open("../Asset/text/character/dey0.txt");
				break;
			case 1:
				m_TxtFile.open("../Asset/text/character/dey1.txt");
				break;
			case 3:
				m_TxtFile.open("../Asset/text/character/dey3.txt");
				break;
			}
		}
		if (status == Still)
		{
			switch (dey)
			{
			case 0:
				m_TxtFile.open("../Asset/text/still/steel_dey0.txt");
				break;
			case 1:
				m_TxtFile.open("../Asset/text/still/steel_dey1.txt");
				break;
			case 2:
				m_TxtFile.open("../Asset/text/still/steel_dey2.txt");
				break;
			case 3:
				m_TxtFile.open("../Asset/text/still/steel_dey3.txt");
				break;
			}
		}

		//ファイルの読み込み
		std::fstream file;
		file.open("../Asset/text/EndTxt.txt");
		std::getline(file, m_EndTxt);
		file.close();
		
		std::getline(m_TxtFile, m_Line);	//一行目読み込み

		//フォントの読み込み
		m_FontPath = "../Asset/font/story/ShinRetroMaruGothic-Medium.ttf";

		//フォントの読み込みができなかったら
		if (AddFontResourceEx(m_FontPath, FR_PRIVATE, NULL) > 0)
		{
		}
		else 
		{
			// フォント読込エラー処理
			MessageBox(NULL, "フォント読込失敗", "", MB_OK);
		}

		ChangeFont("新レトロ丸ゴシック", DX_CHARSET_DEFAULT);
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

			std::string line="";

			//次の行を読み込み
			std::getline(m_TxtFile, line);

			//ファイルの終わりならステータス変更
			if (line == m_EndTxt)
			{
				//次の行を読み込み
				std::getline(m_TxtFile, line);

				if (line == m_DEY)
				{
					NumDeys::UpdateNumDeys();
				}

				//次の行を読み込み
				std::getline(m_TxtFile, line);
				if (line == m_GAMEPLAY)
				{
					ObjectManager::SetGameState(GamePlay);
				}
				if (line == m_STORY)
				{
					ObjectManager::SetGameState(Story);
				}
				if (line == m_STILL)
				{
					ObjectManager::SetGameState(Still);
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
			m_AnimCount += 0.5f;
			if (m_AnimCount >= 1.0f)
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
		int x = GetDrawStringWidth(m_Line.c_str(), -1);
		DrawString((1920 - x) / 2, m_ObjPos.y, (m_Line.substr(0, m_TxtNum) + " ").c_str(), GetColor(255, 255, 255));

#ifdef DEBUG
		DrawFormatString(0, 20, GetColor(255, 255, 255), "m_ClickCount:%f", m_ClickCount);
#endif // DEBUG
	}
}

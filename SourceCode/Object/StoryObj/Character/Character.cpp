#include "Character.h"
#include"../../ObjectTag/Story_ObjectTag.h"
#include"../LineStatus/LineStatus.h"
#include"../../ObjectManager/ObjectManager.h"
#include"../../NumDays/NumDays.h"

namespace object
{
	Character::Character()
		:ObjectBase(story_ObjectTag.CHARACTER)
	{
		//読み込み関連
		LoadObject();
	}

	Character::~Character()
	{
		m_TxtFile.close();
	}

	void Character::LoadObject()
	{
		//画像データ取得
		for (int i = 0; i < 10; i++)
		{
			m_Objimg[JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetFamiliaData_Name(i)] = LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetFamiliaData_Image(i).c_str());
		}

		//日数別に読み込むファイルを変更
		int dey = NumDays::GetNumDays();
		std::string text;

		//表情テキストファイルの取得
		switch (dey)
		{
		case 0:
			text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetExpressionData_Day_0();
			break;
		case 1:
			text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetExpressionData_Day_1();
			break;
		case 4:
			text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetExpressionData_Day_4();
			break;
		}

		//テキストファイルの展開
		m_TxtFile.open((text.c_str()));
		//表示画像データ更新
		UpdateDrawStatus();
	}

	void Character::UpdateObj(const float deltatime)
	{
		//文字セット前は以下処理なし
		if (!LineStatus::GetIsDoneAnim())
			return;
		//表示画像データ更新
		UpdateDrawStatus();
	}

	void Character::UpdateDrawStatus()
	{
		//表情データを読み込んで画像をセット
		std::getline(m_TxtFile, m_Status);
		m_ObjHandle = m_Objimg[m_Status.c_str()];

		//データ別に座標をセット
		if (m_Status.substr(0, charaStatus.NORMAL.size()) == charaStatus.NORMAL)
		{
			m_ObjPos = m_ImgPos[charaStatus.NORMAL];
		}
		if (m_Status.substr(0, charaStatus.WORRY.size()) == charaStatus.WORRY)
		{
			m_ObjPos = m_ImgPos[charaStatus.WORRY];
		}
		if (m_Status.substr(0, charaStatus.DISMAYER.size()) == charaStatus.DISMAYER)
		{
			m_ObjPos = m_ImgPos[charaStatus.DISMAYER];
		}
		if (m_Status.substr(0, charaStatus.HAPPY.size()) == charaStatus.HAPPY)
		{
			m_ObjPos = m_ImgPos[charaStatus.HAPPY];
		}
		if (m_Status.substr(0, charaStatus.SURPRISE.size()) == charaStatus.SURPRISE)
		{
			m_ObjPos = m_ImgPos[charaStatus.SURPRISE];
		}
	}

	void Character::DrawObj()
	{
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);

#ifdef DEBUG
		DrawFormatString(0, 40, GetColor(255, 255, 255), "表情:%s", m_Status.c_str());
#endif // DEBUG
	}
}
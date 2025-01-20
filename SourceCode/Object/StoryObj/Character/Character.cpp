#include "Character.h"
#include"CharaStatus.h"
#include"../../ObjectTag/Story_ObjectTag.h"
#include"../LineStatus/LineStatus.h"
#include"../../ObjectManager/ObjectManager.h"
#include"../../NumDeys/NumDeys.h"

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
		//処理なし
	}

	void Character::LoadObject()
	{
		m_Objimg[charaStatus.HAPPY] = LoadGraph("../Asset/image/story/character/happy.png");
		m_Objimg[charaStatus.NORMAL] = LoadGraph("../Asset/image/story/character/normal.png");
		m_Objimg[charaStatus.SORROW] = LoadGraph("../Asset/image/story/character/sorrow.png");

		m_ObjPos = { 800,100 };

		//日数別に読み込むファイルを変更
		int dey = NumDeys::GetNumDeys();

		switch (dey)
		{
		case 0:
			m_TxtFile.open(("../Asset/text/character/file2.txt"));
			break;
		case 1:
			m_TxtFile.open(("../Asset/text/character/file2.txt"));
			break;
		case 3:
			m_TxtFile.open(("../Asset/text/character/file2.txt"));
			break;
		}

		//ファイルの読み込み
		std::getline(m_TxtFile, m_Status);	//一行目読み込み

		m_ObjHandle = m_Objimg[m_Status.c_str()];
	}

	void Character::UpdateObj(const float deltatime)
	{
		//文字セット前は以下処理なし
		if (!LineStatus::GetIsDoneAnim())
			return;

		std::getline(m_TxtFile, m_Status);	//一行目読み込み
		m_ObjHandle = m_Objimg[m_Status.c_str()];

		LineStatus::SetIsDoneAnim(false);
	}

	void Character::DrawObj()
	{
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
#ifdef DEBUG
		DrawFormatString(0, 40, GetColor(255, 255, 255), "表情:%s", m_Status.c_str());
#endif // DEBUG
	}
}
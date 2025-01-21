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
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Character::~Character()
	{
		//�����Ȃ�
	}

	void Character::LoadObject()
	{
		m_Objimg[charaStatus.HAPPY] = LoadGraph("../Asset/image/story/character/happy.png");
		m_Objimg[charaStatus.NORMAL] = LoadGraph("../Asset/image/story/character/normal.png");
		m_Objimg[charaStatus.SORROW] = LoadGraph("../Asset/image/story/character/sorrow.png");

		m_ObjPos = { 800,100 };

		//�����ʂɓǂݍ��ރt�@�C����ύX
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

		//�t�@�C���̓ǂݍ���
		std::getline(m_TxtFile, m_Status);	//��s�ړǂݍ���

		m_ObjHandle = m_Objimg[m_Status.c_str()];
	}

	void Character::UpdateObj(const float deltatime)
	{
		//�����Z�b�g�O�͈ȉ������Ȃ�
		if (!LineStatus::GetIsDoneAnim())
			return;

		std::getline(m_TxtFile, m_Status);	//��s�ړǂݍ���
		m_ObjHandle = m_Objimg[m_Status.c_str()];

		LineStatus::SetIsDoneAnim(false);
	}

	void Character::DrawObj()
	{
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
#ifdef DEBUG
		DrawFormatString(0, 40, GetColor(255, 255, 255), "�\��:%s", m_Status.c_str());
#endif // DEBUG
	}
}
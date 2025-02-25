#include "Character.h"
#include"../../ObjectTag/Story_ObjectTag.h"
#include"../LineStatus/LineStatus.h"
#include"../../ObjectManager/ObjectManager.h"
#include"../../../NumDays/NumDays.h"

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
		m_TxtFile.close();
		m_ImgPos.clear();

		for (int i = 0; i < 10; i++)
		{
			DeleteGraph(m_Objimg[JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetFamiliaData_Name(i)]);
		}
  		m_Objimg.clear();

		DeleteGraph(m_ObjHandle);
	}

	void Character::LoadObject()
	{
		//�摜�f�[�^�擾
		for (int i = 0; i < 10; i++)
		{
			m_Objimg[JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetFamiliaData_Name(i)] = LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetFamiliaData_Image(i).c_str());
		}

		//�����ʂɓǂݍ��ރt�@�C����ύX
		int dey = NumDays::GetNumDays();
		std::string text;

		//�\��e�L�X�g�t�@�C���̎擾
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

		//�e�L�X�g�t�@�C���̓W�J
		m_TxtFile.open((text.c_str()));
		LineStatus::SetIsDoneImgDraw(true);
		//�\���摜�f�[�^�X�V
		UpdateDrawStatus();
	}

	void Character::UpdateObj(const float deltatime)
	{
		//�����Z�b�g�O�͈ȉ������Ȃ�
		if (!LineStatus::GetIsDoneAnim())
			return;
		//�\���摜�f�[�^�X�V
		UpdateDrawStatus();
	}

	void Character::UpdateDrawStatus()
	{
		//�\��f�[�^��ǂݍ���ŉ摜���Z�b�g
		std::getline(m_TxtFile, m_Status);
		m_ObjHandle = m_Objimg[m_Status.c_str()];

		//�f�[�^�ʂɍ��W���Z�b�g
		for (std::string& status : charaStatus_All)
		{
			if (m_Status.substr(0, status.size()) == status)
			{
				m_ObjPos = m_ImgPos[status];
				return;
			}
		}
	}

	void Character::DrawObj()
	{
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);

#if DEBUG
		DrawFormatString(0, 40, GetColor(255, 255, 255), "�\��:%s", m_Status.c_str());
#endif // DEBUG
	}
}
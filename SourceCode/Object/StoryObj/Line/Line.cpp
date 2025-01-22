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
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Line::~Line()
	{
		m_TxtFile.close();

		//�t�H���g�̃A�����[�h
		if (RemoveFontResourceEx(m_FontPath, FR_PRIVATE, NULL)) {
		}
		else {
			MessageBox(NULL, "remove failure", "", MB_OK);
		}
	}

	void Line::LoadObject()
	{
		SetFontSize(30);		//�t�H���g�T�C�Y�ݒ�

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

		//���݂̃Q�[���X�e�[�^�X���擾
		GameStatus status=ObjectManager::GetNextGameState();

		//�����ʂɓǂݍ��ރt�@�C����ύX
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

		//�t�@�C���̓ǂݍ���
		m_TxtFile.open(text.c_str());
		std::getline(m_TxtFile, m_Line);	//��s�ړǂݍ���

		//�t�H���g�̓ǂݍ���
		/*std::string font = JsonManager::FontData_Instance()->Get_StoryDat_Instance()->GetFontData();
		m_FontPath = font.c_str();*/
		m_FontPath = "../Asset/font/story/ShinRetroMaruGothic-Medium.ttf";

		//�t�H���g�̓ǂݍ��݂��ł��Ȃ�������
		if (AddFontResourceEx(m_FontPath, FR_PRIVATE, NULL) > 0)
		{
		}
		else 
		{
			// �t�H���g�Ǎ��G���[����
			MessageBox(NULL, "FontErrer", "", MB_OK);
		}

		//�t�H���g�����擾
		std::ifstream fontname_data;
		std::string name;
		fontname_data.open(JsonManager::FontData_Instance()->Get_StoryDat_Instance()->Get_FontTagData().c_str());
		std::getline(fontname_data, name);
		//�t�H���g���Z�b�g
		ChangeFont(name.c_str(), DX_CHARSET_DEFAULT);
		fontname_data.close();
	}

	void Line::UpdateObj(const float deltatime)
	{
		//�����̃Z�b�g���ł��Ă��ăN���b�N�\���
		if (m_IsLineSet && m_IsClick)
		{
			if (GetMouseInput() & MOUSE_INPUT_LEFT)
			{
				//�������A�j�����Ȃ�
				if (m_IslineAnim)
				{
					//���������ׂĕ\������
					m_TxtNum = m_Line.size();
					m_IslineAnim = false;
				}
				else
				{
					//�����̃Z�b�g���s��
					m_IsLineSet = false;
				}
				m_IsClick = false;
			}
		}

		//�N���b�N������
		if (!m_IsClick)
		{
			m_ClickCount += 0.1;
			if (m_ClickCount >= 5.0f)
			{
				m_ClickCount = 0.0f;
				m_IsClick = true;
			}
		}

		//���Z�b�g��ԂȂ�
		if (!m_IsLineSet)
		{
			//�O�̕������N���A
			m_Line.clear();
			m_TxtNum = 0;
			m_NowCollar = m_COLLAR_DEFAULT;
			m_AnimSpeed = m_SPEED_DEFAULT;

			std::string line="";

			//���̍s��ǂݍ���
			std::getline(m_TxtFile, line);

			bool status_set = false;
			if (line == "status")
			{
				status_set = true;
			}

			while (status_set)
			{
				//���̍s��ǂݍ���
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

			if (line == m_END)	//�t�@�C���̏I���Ȃ�X�e�[�^�X�ύX
			{
				//���̍s��ǂݍ���
				std::getline(m_TxtFile, line);
				if (line == m_DAY)
				{
					NumDeys::UpdateNumDeys();
				}

				//���̍s��ǂݍ���
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

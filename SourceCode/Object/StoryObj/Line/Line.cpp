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

		m_IsClick = true;
		m_IsLineSet = true;
		m_IslineAnim = true;

		LineStatus::SetIsDoneAnim(false);

		m_TxtNum = 0;
		m_AnimCount = 0.0f;
		m_ClickCount = 0.0f;
		m_ObjPos = { 0,800 };

		//���݂̃Q�[���X�e�[�^�X���擾
		GameStatus status=ObjectManager::GetGameState();

		//�����ʂɓǂݍ��ރt�@�C����ύX
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

		//�t�@�C���̓ǂݍ���
		std::fstream file;
		file.open("../Asset/text/EndTxt.txt");
		std::getline(file, m_EndTxt);
		file.close();
		
		std::getline(m_TxtFile, m_Line);	//��s�ړǂݍ���

		//�t�H���g�̓ǂݍ���
		m_FontPath = "../Asset/font/story/ShinRetroMaruGothic-Medium.ttf";

		//�t�H���g�̓ǂݍ��݂��ł��Ȃ�������
		if (AddFontResourceEx(m_FontPath, FR_PRIVATE, NULL) > 0)
		{
		}
		else 
		{
			// �t�H���g�Ǎ��G���[����
			MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
		}

		ChangeFont("�V���g���ۃS�V�b�N", DX_CHARSET_DEFAULT);
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

			std::string line="";

			//���̍s��ǂݍ���
			std::getline(m_TxtFile, line);

			//�t�@�C���̏I���Ȃ�X�e�[�^�X�ύX
			if (line == m_EndTxt)
			{
				//���̍s��ǂݍ���
				std::getline(m_TxtFile, line);

				if (line == m_DEY)
				{
					NumDeys::UpdateNumDeys();
				}

				//���̍s��ǂݍ���
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

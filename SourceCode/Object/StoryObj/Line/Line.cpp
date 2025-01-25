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
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Line::~Line()
	{
		m_TxtFile.close();

		//�t�H���g�̃A�����[�h
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

		//���݂̃Q�[���X�e�[�^�X���擾
		GameStatus status=ObjectManager::GetNextGameState();

		//�����ʂɓǂݍ��ރt�@�C����ύX
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

		//�t�@�C���̓ǂݍ���
		m_TxtFile.open(text.c_str());
		std::getline(m_TxtFile, m_Line);	//��s�ړǂݍ���

		auto t = JsonManager::FontData_Instance()->Get_StoryDat_Instance();

		//�t�H���g�����擾
		std::ifstream fontname_data;
		fontname_data.open(t->Get_FontTagToChar());
		std::getline(fontname_data, m_FontTag);
		AddFontResourceEx(t->GetFontPath().c_str(), FR_PRIVATE, NULL);
		m_FontHandol = CreateFontToHandle(t->Get_FontTagToChar(), 30, 1, DX_FONTTYPE_ANTIALIASING_EDGE);

		if (m_FontHandol == -1)
		{
			//�t�H���g�Ǎ��G���[����
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

		//�X�^�[�g����\���܂ł��炷
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
		//�X�y�[�X�L�[�ŃX�L�b�v
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

		//�N���b�N������
		if (!m_IsClick)
		{
			m_ClickCount -= m_COUNT_DECREMENT;
			if (m_ClickCount <= 0.0f)
			{
				m_ClickCount = 0.0f;
				m_IsClick = true;
			}
		}

		//���Z�b�g��ԂȂ�
		if (!m_IsLineSet)
		{
			DrawTextSet();
		}
	}

	void Line::ClickStatus()
	{
		//�����̃Z�b�g���ł��Ă��ăN���b�N�\���
		if (m_IsLineSet && m_IsClick)
		{
			//�J�E���g���[�h�Ȃ玩���؂�ւ�
			if (m_IsWeitMode)
			{
				m_IsWeitMode = false;
				m_IsLineSet = false;
				m_IsClick = false;
			}
			else if (GetMouseInput() & MOUSE_INPUT_LEFT)
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
				m_ClickCount = m_CLICKCOU_MAX;
			}
		}
	}

	void Line::DrawTextSet()
	{
		std::string line = "";

		//���̍s��ǂݍ���
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
			Text_Processing(line);
			m_IsLineDone = true;
		}
		else
		{
			//�O�̕������N���A
			m_Line.clear();
			m_TxtNum = 0;

			if (line == "count")
			{
				//�ēx�N���b�N�ł���܂Ŏ���
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
		//���̍s��ǂݍ���
		std::getline(m_TxtFile, line);
		if (line == m_DAY)
		{
			NumDays::UpdateNumDays();
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
		DrawString(0, 100, "�X�y�[�X�ŃX�L�b�v",GetColor(255, 255, 255));
#endif // DEBUG
	}
}

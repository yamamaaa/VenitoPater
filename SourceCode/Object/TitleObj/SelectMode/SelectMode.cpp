#include "SelectMode.h"
#include "../../ObjectTag/TitleObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
	SelectMode::SelectMode()
		:MouseBase(titleObjectTag.TITLEUI)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	SelectMode::~SelectMode()
	{
		//�����Ȃ�
	}

	void SelectMode::LoadObject()
	{
		m_ObjPos = {0,0};
		m_ObjSize = { 600,80 };

		m_SelectPos = { 537.0f,437.0f };
		m_MenuPos = { 700.0f,250.0f };

		m_SelectIndex = 0;
		//�N���b�N�\���
		m_CanClick = true;

		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_TitleData_Instance()->GetSelectData().c_str());
		m_MenuHandol= LoadGraph(JsonManager::ImgData_Instance()->Get_TitleData_Instance()->GetMenuData().c_str());
	}

	void SelectMode::UpdateObj(const float deltatime)
	{
		m_SelectIndex = 0;

		for (int i = 0; i < 3; i++)
		{
			//�}�E�X���G���A�ړ��̈ʒu�ɂ��邩
			m_ObjPos.x = m_HitPos[i].x;
			m_ObjPos.y = m_HitPos[i].y;

			//�}�E�X�Ƃ̓����蔻��
			CursorHit();

			//�J�[�\���ɓ������Ă�����
			if (GetCursorHit())
			{
				CanClick();
				m_SelectPos.x = m_SelectMenuPos[i].x;
				m_SelectPos.y = m_SelectMenuPos[i].y;
			}
			//�A�C�e�����N���b�N������
			if (GetStateClick() && GetCursorHit())
			{
				GameStatus status;

				switch (m_SelectIndex)
				{
				case PlayMenu::PlayTutorial:
					status = GameStatus::Tutorial;
					break;
				case PlayMenu::PlayNewGame:
					status = GameStatus::GamePlay;
					break;
				case PlayMenu::PlayRankingMode:
					status = GameStatus::RankingMode;
					break;
				}

				ObjectManager::SetNextGameState(status);

				return;
			}
			else
			{
				m_SelectIndex++;
			}
		}
	}

	void SelectMode::DrawObj()
	{
		//�摜�̕\��
		DrawGraph(static_cast<int>(m_SelectPos.x), static_cast<int>(m_SelectPos.y), m_ObjHandle, TRUE);
		DrawGraph(static_cast<int>(m_MenuPos.x), static_cast<int>(m_MenuPos.y), m_MenuHandol, TRUE);

#ifdef DEBUG
		for (int i = 0; i < 3; i++)
		{
			DrawBox(static_cast<int>(m_HitPos[i].x), static_cast<int>(m_HitPos[i].y), static_cast<int>(m_HitPos[i].x) + m_ObjSize.x, static_cast<int>(m_HitPos[i].y) + m_ObjSize.y, GetColor(255, 40, 0), FALSE);
		}
#endif
	}
}
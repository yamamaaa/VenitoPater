#include "GameOverUi.h"
#include "../../ObjectTag/GameOver_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
	GameOverUi::GameOverUi()
		:MouseBase(gameOver_ObjectTag.GAMEOVERUI)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	GameOverUi::~GameOverUi()
	{
		//�����Ȃ�
	}

	void GameOverUi::LoadObject()
	{
		m_ResultLogo_Pos = { 750 ,400 };

		m_SelectUi_Pos[0] = { 440, 800 };
		m_SelectUi_Pos[1] = { 1200, 800 };

		m_ObjSize = { 300,100 };

		m_UiOffset[0] = { 50,30 };
		m_UiOffset[1] = { 70,30 };

		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_ResultData_Instance()->GetOverData_Select().c_str());

		m_Uipos.x = m_SelectUi_Pos[0].x;
		m_Uipos.y = m_SelectUi_Pos[0].y;
	}

	void GameOverUi::UpdateObj(const float deltatime)
	{
		//�}�E�X���G���A�ړ��̈ʒu�ɂ��邩

		for (int i = 0; i < 2; i++)
		{
			m_ObjPos.x = m_SelectUi_Pos[i].x;
			m_ObjPos.y = m_SelectUi_Pos[i].y;

			m_ObjSize.x = m_ObjSize.x;
			m_ObjSize.y = m_ObjSize.y;

			//�}�E�X�Ƃ̓����蔻��
			CursorHit();
			CanClick();

			if (GetCursorHit())
			{
				if (i == 0)	//�R���e�j���[�Ȃ�
				{
#ifdef DEBUG
					m_selectstatus = "�R���e�j���[";
#endif // DEBUG
					m_Uipos.x = m_SelectUi_Pos[0].x;
					m_Uipos.y = m_SelectUi_Pos[0].y;
				}
				else if (i == 1)//�^�C�g���ɖ߂�Ȃ�
				{
#ifdef DEBUG
					m_selectstatus = "�^�C�g��";
#endif // DEBUG
					m_Uipos.x = m_SelectUi_Pos[1].x;
					m_Uipos.y = m_SelectUi_Pos[1].y;
				}

				//�A�C�e�����N���b�N������
				if (GetStateClick())
				{
					if (i == 0)	//�R���e�j���[�Ȃ�
					{
						ObjectManager::SetNextGameState(Continue);
					}
					else		//�^�C�g���ɖ߂�Ȃ�
					{
						ObjectManager::SetNextGameState(Title);
					}
				}
			}
		}
	}

	void GameOverUi::DrawObj()
	{
		//SetFontSize(100);
		DrawFormatString(m_ResultLogo_Pos.x, m_ResultLogo_Pos.y, GetColor(255, 255, 255), "GameOver");

		DrawGraph(static_cast<int>(m_Uipos.x), static_cast<int>(m_Uipos.y),m_ObjHandle, TRUE);

		//SetFontSize(30);
		DrawFormatString(m_SelectUi_Pos[0].x+ m_UiOffset[0].x, m_SelectUi_Pos[0].y + m_UiOffset[0].y, GetColor(255, 255, 255), "�R���e�j���[");
		DrawFormatString(m_SelectUi_Pos[1].x + m_UiOffset[1].x, m_SelectUi_Pos[1].y + m_UiOffset[1].y, GetColor(255, 255, 255), "�^�C�g����");

		DrawBox(m_SelectUi_Pos[0].x, m_SelectUi_Pos[0].y, m_SelectUi_Pos[0].x + m_ObjSize.x, m_SelectUi_Pos[0].y + m_ObjSize.y, GetColor(255,0,0),FALSE);

		DrawBox(m_SelectUi_Pos[1].x, m_SelectUi_Pos[1].y, m_SelectUi_Pos[1].x + m_ObjSize.x, m_SelectUi_Pos[1].y + m_ObjSize.y, GetColor(0, 255, 0),FALSE);

#ifdef DEBUG
		DrawFormatString(0, 20, GetColor(255, 255, 255), "�Z���N�g���:%s", m_selectstatus.c_str());
#endif // DEBUG
	}
}
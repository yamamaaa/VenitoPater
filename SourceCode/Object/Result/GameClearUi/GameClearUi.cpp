#include "GameClearUi.h"
#include "../../ObjectTag/GameClear_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"
#include "../../NumDays/NumDays.h"

namespace object
{
	GameClearUi::GameClearUi()
		:ObjectBase(gameClear_Objecttag.GAMECLEARUI)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	GameClearUi::~GameClearUi()
	{
		//�����Ȃ�
	}

	void GameClearUi::LoadObject()
	{
		m_ObjPos = { 770 ,400 };
		m_DrawCount = m_DRAWCOUNT_MAX;
	}

	void GameClearUi::UpdateObj(const float deltatime)
	{
		//��莞�ԕ����̕\��
		if (m_DrawCount <= 0.0f)
		{
			//�I�������v���C���[�h�ʂɎ��̃Q�[���X�e�[�^�X��ύX
			if (ObjectManager::GetPlayMode() == PlayMenu::PlayNewGame)
			{
				SetNextGame_Status();
			}
			else if (ObjectManager::GetPlayMode() == PlayMenu::PlayRankingMode)
			{
				//ObjectManager::SetNextGameState(GameStatus);
			}
		}
		else
		{
			m_DrawCount -= m_COUNT_DECREMENT;
		}
	}

	void GameClearUi::SetNextGame_Status()
	{
		//�����ʂɂ��N���A��̃X�e�[�^�X���Z�b�g
		int day = NumDays::GetNumDays();
		GameStatus status;
		switch (day)
		{
		case 1:
			status = GameStatus::Story;
			break;
		case 2:
			status = GameStatus::Still;
			break;
		case 3:
			status = GameStatus::Still;
			break;
		}

		ObjectManager::SetNextGameState(status);
	}

	void GameClearUi::DrawObj()
	{
		SetFontSize(m_FONTSIZE);
		DrawFormatString(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), GetColor(m_CORRER_CODE, m_CORRER_CODE, m_CORRER_CODE), "5 : 0");

#ifdef DEBUG
		SetFontSize(m_DEBUG_FONTSIZE);
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�\������ : %f", m_DrawCount);
#endif // DEBUG
	}
}
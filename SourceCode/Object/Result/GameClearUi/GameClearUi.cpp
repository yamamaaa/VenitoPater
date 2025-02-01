#include "GameClearUi.h"
#include "../../ObjectTag/GameClear_ObjectTag.h"
#include "../../../GameSystem/Window/Window.h"
#include "../../ObjectManager/ObjectManager.h"
#include "../../../NumDays/NumDays.h"
#include "../../../SoundController/SoundController.h"

namespace object
{
	GameClearUi::GameClearUi()
		:ObjectBase(gameClear_ObjectTag.GAMECLEARUI)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	GameClearUi::~GameClearUi()
	{
		//�t�H���g�n���h���̉��
		DeleteFontToHandle(m_FontHandle);
	}

	void GameClearUi::LoadObject()
	{
		m_DrawCount = m_DRAWCOUNT_MAX;

		m_IsSound = false;

		window = nullptr;	//window�̃C���X�^���X����
		POINTS windowsize = window->GetWindowSize();

		auto json = JsonManager::SoundData_Instance()->Get_Clear_SoundData_Instance();
		m_JsonTag[0] = json->GetBgmNameData();
		m_JsonTag[1] = json->GetApplauseNameData();
		sound_controller::SoundController::AddSoundData(json->GetBgmPathData(), m_JsonTag[0],json->GetBgmVolumeData(), json->GetBgmTypeData());
		sound_controller::SoundController::AddSoundData(json->GetApplausePathData(), m_JsonTag[1], json->GetApplauseVolumeData(), json->GetApplauseTypeData());

		m_FontHandle = CreateFontToHandle("���C���I", m_FONTSIZE.x, m_FONTSIZE.y, DX_FONTTYPE_ANTIALIASING);

		//�����̒������擾���ĉ�ʒ����ɍ��W��ݒ�
		int x = GetDrawFormatStringWidthToHandle(m_FontHandle, m_TimeText.c_str(), 0);
		float ans_x = static_cast<float>((windowsize.x - x) / 2);
		float ans_y = static_cast<float>((windowsize.y - m_FONTSIZE.x) / 2);
		m_ObjPos = { ans_x, ans_y };
	}

	void GameClearUi::UpdateObj(const float deltatime)
	{
		if (!m_IsSound)
		{
			sound_controller::SoundController::StartSound(m_JsonTag[0]);
			sound_controller::SoundController::StartSound(m_JsonTag[1]);
			m_IsSound = true;
		}

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
				ObjectManager::SetNextGameState(GameStatus::Score);
			}
		}
		else
		{
			m_DrawCount -= m_COUNT_DECREMENT* deltatime;
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
		DrawStringFToHandle(m_ObjPos.x, m_ObjPos.y, m_TimeText.c_str(), GetColor(m_COLOR, m_COLOR, m_COLOR), m_FontHandle);
#ifdef DEBUG
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�\������ : %f", m_DrawCount);
#endif // DEBUG
	}
}
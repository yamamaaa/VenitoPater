#include "GameOverUi.h"
#include "../../ObjectTag/GameOver_ObjectTag.h"
#include "../../../GameSystem/Window/Window.h"
#include "../../ObjectManager/ObjectManager.h"
#include "../../../SoundController/SoundController.h"

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
		delete window;
		DeleteGraph(m_ObjHandle);
		//�t�H���g�n���h���̉��
		DeleteFontToHandle(m_FontHandle);
		DeleteFontToHandle(m_FontHandle_Ui);
	}

	void GameOverUi::LoadObject()
	{
		m_SelectUi_Pos[0] = { 440, 800 };
		m_SelectUi_Pos[1] = { 1200, 800 };

		m_ObjSize = { 300,100 };

		m_UiOffset[0] = { 50,30 };
		m_UiOffset[1] = { 60,30 };

		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_ResultData_Instance()->GetOverData_Select().c_str());

		auto json = JsonManager::SoundData_Instance()->Get_Result_SoundData_Instance();
		m_JsonTag[0] = json->GetBgmNameData();
		m_JsonTag[1] = json->GetBackNameData();
		m_JsonTag[2] = json->GetButtonNameData();
		sound_controller::SoundController::AddSoundData(json->GetBgmPathData(), m_JsonTag[0],json->GetBgmVolumeData(), json->GetBgmTypeData());
		sound_controller::SoundController::AddSoundData(json->GetBackPathData(), m_JsonTag[1], json->GetBackVolumeData(), json->GetBackTypeData());
		sound_controller::SoundController::AddSoundData(json->GetButtonPathData(), m_JsonTag[2], json->GetButtonVolumeData(), json->GetButtonTypeData());

		m_Uipos.x = m_SelectUi_Pos[0].x;
		m_Uipos.y = m_SelectUi_Pos[0].y;

		window = nullptr;	//window�̃C���X�^���X����
		POINTS windowsize = window->GetWindowSize();

		//�t�H���g�n���h���̐���
		m_FontHandle_Ui = CreateFontToHandle("���C���I", m_FONTSIZE_Ui.x, m_FONTSIZE_Ui.y, DX_FONTTYPE_ANTIALIASING);
		m_FontHandle = CreateFontToHandle("���C���I", m_FONTSIZE.x, m_FONTSIZE.y, DX_FONTTYPE_ANTIALIASING);

		//�����̒������擾���ĉ�ʒ����ɍ��W��ݒ�
		int x = GetDrawFormatStringWidthToHandle(m_FontHandle, m_Title.c_str(),0);
		float ans_x = static_cast<float>((windowsize.x - x) / 2);
		m_ResultLogo_Pos = { ans_x, 350.0f};
	}

	void GameOverUi::UpdateObj(const float deltatime)
	{
		//�}�E�X���G���A�ړ��̈ʒu�ɂ��邩

		sound_controller::SoundController::StartSound(m_JsonTag[0]);

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
						sound_controller::SoundController::StartSound(m_JsonTag[2]);
						ObjectManager::SetNextGameState(GamePlay);
					}
					else		//�^�C�g���ɖ߂�Ȃ�
					{
						sound_controller::SoundController::StartSound(m_JsonTag[1]);
						ObjectManager::SetNextGameState(Title);
					}
				}
			}
		}
	}

	void GameOverUi::DrawObj()
	{
		DrawGraph(static_cast<int>(m_Uipos.x), static_cast<int>(m_Uipos.y),m_ObjHandle, TRUE);

		DrawStringFToHandle(m_ResultLogo_Pos.x, m_ResultLogo_Pos.y, m_Title.c_str(), GetColor(m_COLOR, m_COLOR, m_COLOR),m_FontHandle);

		float ui_x0 = m_SelectUi_Pos[0].x + m_UiOffset[0].x;
		float ui_y0 = m_SelectUi_Pos[0].y + m_UiOffset[0].y;

		DrawStringFToHandle(ui_x0, ui_y0, m_SelectText[0].c_str(), GetColor(m_COLOR, m_COLOR, m_COLOR), m_FontHandle_Ui);

		float ui_x1 = m_SelectUi_Pos[1].x + m_UiOffset[1].x;
		float ui_y1= m_SelectUi_Pos[1].y + m_UiOffset[1].y;

		DrawStringFToHandle(ui_x1, ui_y1, m_SelectText[1].c_str(),GetColor(m_COLOR, m_COLOR, m_COLOR), m_FontHandle_Ui);

#ifdef DEBUG
		DrawBox(static_cast<int>(m_SelectUi_Pos[0].x), static_cast<int>(m_SelectUi_Pos[0].y), static_cast<int>(m_SelectUi_Pos[0].x + m_ObjSize.x), static_cast<int>(m_SelectUi_Pos[0].y + m_ObjSize.y), GetColor(255,0,0),FALSE);
		DrawBox(static_cast<int>(m_SelectUi_Pos[1].x), static_cast<int>(m_SelectUi_Pos[1].y), static_cast<int>(m_SelectUi_Pos[1].x + m_ObjSize.x), static_cast<int>(m_SelectUi_Pos[1].y + m_ObjSize.y), GetColor(0, 255, 0),FALSE);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "�Z���N�g���:%s", m_selectstatus.c_str());
#endif // DEBUG
	}
}
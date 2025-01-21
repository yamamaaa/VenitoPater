#include<Dxlib.h>
#include "HatUi.h"
#include"../AvoidStatus/AvoidStatus.h"
#include"../../../JsonMaster/JsonManager/JsonManager.h"

namespace object
{
	//���Ԃ����
	std::unique_ptr<HatUi>HatUi::hatui = nullptr;

	HatUi::HatUi()
	{
		//�����Ȃ�
	}

	HatUi::~HatUi()
	{
		//�����Ȃ�
	}

	void HatUi::Initialize()
	{
		//�������̂��Ȃ�������C���X�^���X����
		if (!hatui)
		{
			hatui.reset(new HatUi);
		}

		LoadUi();
	}

	void HatUi::LoadUi()
	{
		hatui->m_UiPos = { 0, 0 };
		hatui->m_UiHandle = -1;
		hatui->m_IsMoveDone = true;
		hatui->m_IsMoveDown = false;

		//�摜�̓ǂݍ���
		hatui->m_UiHandle = LoadGraph(jsonmaster::JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Hat().c_str());
	}

	void HatUi::SetMove()
	{
		//���������ԂłȂ����
		if (!AvoidStatus::GetIsAvoid())
		{
			hatui->m_IsMoveDone = false;	//���������Z�b�g
			hatui->m_IsMoveDown = true;		//���������Z�b�g
			hatui->m_UiPos.y = m_UIMOVE_POS;	//���W�Z�b�g
		}
		else
		{
			hatui->m_IsMoveDone = false;
		}
	}

	void HatUi::MoveUi()
	{
		//���ɓ������ꍇ
		if (hatui->m_IsMoveDown)
		{
			//�摜�����̈ʒu�܂ňړ�
			hatui->m_UiPos.y += hatui->m_UIMOVE_SPEED;
			if (hatui->m_UiPos.y == 0.0f)
			{
				hatui->m_IsMoveDone = true;
				hatui->m_IsMoveDown = false;
			}
		}
		else
		{
			//�摜�����̈ʒu�܂ňړ�
			hatui->m_UiPos.y -= hatui->m_UIMOVE_SPEED;
			if (hatui->m_UiPos.y == m_UIMOVE_POS)
			{
				hatui->m_IsMoveDone = true;
				AvoidStatus::SetIsAvoid(false);		//����s���̉���
			}
		}
	}

	void HatUi::DrawUi()
	{
		//�摜�̕\��
		DrawGraph(static_cast<int>(hatui->m_UiPos.x), static_cast<int>(hatui->m_UiPos.y), hatui->m_UiHandle, TRUE);
	}
}
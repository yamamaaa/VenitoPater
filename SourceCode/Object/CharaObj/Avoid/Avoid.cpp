#include<Dxlib.h>
#include "Avoid.h"
#include"../../ObjectTag/Global_ObjectTag.h"
#include"../AvoidStatus/AvoidStatus.h"
#include"../HatUi/HatUi.h"

namespace object
{
	Avoid::Avoid()
		:MouseBase(global_objecttag.AVOID)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Avoid::~Avoid()
	{
		//�����Ȃ�
	}

	void Avoid::LoadObject()
	{
		m_ObjPos.x = 170;
		m_ObjPos.y = 880;

		m_ObjSize.x = 600;
		m_ObjSize.y = 200;

		m_DrawOffset.x = 0;
		m_DrawOffset.y = 0;

		m_ClickCount = m_CLICKCOUNT_MAX;

		//HatUi�̏�����
		HatUi::Initialize();
	}

	void Avoid::UpdateObj(const float deltatime)
	{
		CursorHit();	//�J�[�\���Ƃ̓����蔻��

		if (GetCursorHit())	//�������Ă�����
		{
			CanClick();		//�N���b�N�ł��邩�H

			//�N���b�N��Ԃ̎�
			if (GetStateClick()&& m_IsClick)
			{
				if (!AvoidStatus::GetIsAvoid())
				{
					HatUi::SetMove();
					//����s���t���O��true��
					AvoidStatus::SetIsAvoid(true);
#ifdef DEBUG
					m_avoid_status = "����s����";
#endif
				}
				else
				{
					HatUi::SetMove();
#ifdef DEBUG
					m_avoid_status = "�ʏ���";
#endif
				}
				
				m_IsClick = false;
			}
		}

		//Ui�̓�������
		if (!HatUi::GetIsMoveDone())
		{
			MoveObj(deltatime);
		}

		//�ĂуN���b�N�ł���܂ŃJ�E���g
		if (!m_IsClick)
		{
			m_ClickCount -- ;
			if (m_ClickCount == 0.0f)
			{
				m_ClickCount = m_CLICKCOUNT_MAX;
				m_IsClick = true;
			}
		}
	}

	void Avoid::DrawObj()
	{
		//����s������Ui��\��
		if (AvoidStatus::GetIsAvoid())
		{
			HatUi::DrawUi();
		}
#ifdef DEBUG
		DrawBox(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), static_cast<int>(m_ObjPos.x) + m_ObjSize.x, static_cast<int>(m_ObjPos.y) + m_ObjSize.y, GetColor(static_cast<int>(m_collarcode.x), static_cast<int>(m_collarcode.y), static_cast<int>(m_collarcode.z)), FALSE);
		DrawFormatString(0, 400, GetColor(255, 255, 255), "������:%s", m_avoid_status.c_str());
		DrawFormatString(0, 420, GetColor(255, 255, 255), "�Ăщ���ł���܂�:%f", m_ClickCount);
#endif
	}

	void Avoid::MoveObj(const float deltatime)
	{
		HatUi::MoveUi();
	}
}

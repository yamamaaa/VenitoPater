#include "EnemyBase.h"
#include "../../../../GameSystem/Window/Window.h"
#include "../../../StageObj/AreaNumController/AreaNumController.h"
#include"../../../ObjectManager/ObjectManager.h"
#include "../../LightController/LightController.h"

namespace object
{
	EnemyBase::EnemyBase(std::string tagname)
		:ObjectBase(tagname),
		m_ObjImg(),
		m_HitLineIndex(-1),
		m_ObjDrawArea(-1),
		m_IsActionLine(false),
		m_CanAvoid(false),
		m_IsAppear(false),
		m_BlinkingCount(0.0f),
		m_ResetCount(0.0f),
		m_IsEmyReset(false),
		m_DrawObjPos(0)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	EnemyBase::~EnemyBase()
	{
		//�������̉��
		delete window;
	}

	void EnemyBase::LoadObject()
	{
		window = nullptr;	//window�̃C���X�^���X����

		m_ObjSize = window->GetWindowSize();	//window�T�C�Y�̎擾
		m_ObjSize.y = 0;
	}

	void EnemyBase::IsHitEnemyLine()
	{
		bool hitstatus = false;	//Hit���
		m_HitLineIndex = 0;		//Index������

		//enemyline�Ƃ̓����蔻��𒲂ׂ�
		for (std::string& tag : EnemyLine_TagAll)
		{
			hitstatus = CheckHitSquare(m_EmyLine_Pos[tag].x, m_EmyLine_Pos[tag].y, m_ObjSize.x, m_ObjSize.y, m_EnemyBoxPos.x, m_EnemyBoxPos.y, m_EMYBOX_SIZE.x, m_EMYBOX_SIZE.y);

			//�������Ă�����
			if (hitstatus)
			{
				return;
			}
			m_HitLineIndex++;
		}
	}

	const bool EnemyBase::IsObjDraw()
	{
		//�G���A�ԍ��̎擾
		int infodata = AreaNumController::GetAreaNum();

		//enemy�̕\�����ł��邩
		if (infodata == m_ObjDrawArea)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void EnemyBase::AvoidAction()
	{
		//����ł��Ȃ��Ȃ珈���Ȃ�
		if (!m_CanAvoid)
			return;

		//�G���o�����ŕ\���ł���Ƃ�
		if (m_IsAppear && IsObjDraw())
		{
			m_ResetCount++;
			if (m_ResetCount >= 100.0f)	//�J�E���g���K��l�ɒB�����烊�Z�b�g
			{
				m_IsEmyReset = true;
				m_ResetCount = 0.0f;
			}
		}
	}

	void EnemyBase::ObjStatusUp()
	{
		//��������Emyline�ɂ���ď�Ԑ؂�ւ�
		switch (GetHitLineIndex())
		{
		case appear:
			m_IsAppear = true;					//�I�u�W�F�N�g���o������
			m_ObjHandle = m_ObjImg[0];			//�\���摜�̃Z�b�g
			m_ObjPos = m_DrawObjPos[appear];	//�摜�̕\���ʒu�X�V
			break;
		case replace:
			m_ObjHandle = m_ObjImg[1];
			m_ObjPos = m_DrawObjPos[replace];
			m_CanAvoid = true;					//����ł����Ԃ�
			break;
		case replace_2:
			m_ObjHandle = m_ObjImg[2];
			m_ObjPos = m_DrawObjPos[replace_2];
			break;
		case action:
			m_ObjHandle = m_ObjImg[3];
			m_ObjPos = m_DrawObjPos[action];
			m_IsActionLine = true;	//�t���O��true��
			break;
		}
	}

	void EnemyBase::ExitObj()
	{
		//�G�̑ޏo����ʂ�_�ł�����
		LightController::SetIsBlinking(true);
		m_BlinkingCount++;
		if (m_BlinkingCount >= 20.0f)
		{
			ResetObj();
			m_IsEmyReset = false;
			LightController::SetIsBlinking(false);
		}
	}

	void EnemyBase::ResetObj()
	{
		//�G���̏�����
		m_IsAppear = false;
		m_EnemyBoxPos = m_EMYBOX_RESETPOS;
		m_ObjHandle = -0;
		m_ObjPos = { 0.0f,0.0f };
		m_BlinkingCount = 0;
		EnemyManager::SetIsAppear(m_IDnumber, false);

		//�G�̏o�����������炷
		int num = EnemyManager::GetAppearNumNow();
		num--;
		EnemyManager::SetAppearNumNow(num);
	}

	void EnemyBase::EnemyInAction()
	{
		//�Q�[����Ԃ��Q�[���I�[�o�[��
		ObjectManager::SetNextGameState(GameOver);
	}

#ifdef DEBUG
	void EnemyBase::EnemyLineDraw()
	{
		//enemyline�̕\��
		for (std::string& tag : EnemyLine_TagAll)
		{
			DrawLine(m_EmyLine_Pos[tag].x, m_EmyLine_Pos[tag].y, m_EmyLine_Pos[tag].x + m_ObjSize.x, m_EmyLine_Pos[tag].y + m_ObjSize.y, GetColor(static_cast<int>(m_collarcode[tag].x), static_cast<int>(m_collarcode[tag].y), static_cast<int>(m_collarcode[tag].z)), FALSE);
		}
	}
#endif
}
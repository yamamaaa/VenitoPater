#include "EnemyBase.h"
#include "../../../../GameSystem/Window/Window.h"
#include "../../../StageObj/AreaNumController/AreaNumController.h"
#include"../../../ObjectManager/ObjectManager.h"
#include "../../LightController/LightController.h"
#include "../../../../SoundController/SoundController.h"

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
		EnemyManager::Processing();
		m_DrawObjPos.clear();
		m_EmyLine_Pos.clear();
#if DEBUG
		m_collarcode.clear();
#endif // DEBUG
	}

	void EnemyBase::LoadObject()
	{
		window = nullptr;	//window�̃C���X�^���X����

		m_ObjSize = window->GetWindowSize();	//window�T�C�Y�̎擾
		m_ObjSize.y = 0;

		auto json = JsonManager::SoundData_Instance()->Get_Play_SoundData_Instance();
		m_JsonTag = json->GetLight_NameData();
		sound_controller::SoundController::AddSoundData(json->GetLight_PathData(), m_JsonTag, json->GetLight_VolumeData(), json->GetLight_TypeData());
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
		//�^�C���I�[�o�[���Ă�����
		if (TimeStatus::GetIsTimeOver())
		{
			//familia�ȊO�\���s��
			if (m_IDnumber != familia)
			{
				return false;
			}
		}

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

	void EnemyBase::AvoidAction(const float deltatime)
	{
		//����ł��Ȃ��Ȃ珈���Ȃ�
		if (!m_CanAvoid)
			return;

		//�G���o�����ŕ\���ł���Ƃ�
		if (m_IsAppear && IsObjDraw())
		{
			m_ResetCount+= m_COUNTSPPED_RESET *deltatime;
			if (m_ResetCount >= m_COUNTRESET_MAX)	//�J�E���g���K��l�ɒB�����烊�Z�b�g
			{
				m_IsEmyReset = true;
				m_ResetCount = 0.0f;
			}
		}
	}

	void EnemyBase::AvoidReset()
	{
		//�J�E���g�̃��Z�b�g
		m_ResetCount = 0.0f;
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

	void EnemyBase::ExitObj(const float deltatime)
	{
		//�G�̑ޏo����ʂ�_�ł�����
		LightController::SetIsBlinking(true);
		sound_controller::SoundController::StartSound(m_JsonTag);
		m_BlinkingCount+= m_COUSPPED_BLINKING*deltatime;
		if (m_BlinkingCount >= m_BLINKING_COUMAX)
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
		m_CanAvoid = false;
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

#if DEBUG
	void EnemyBase::EnemyLineDraw()
	{
		//enemyline�̕\��
		for (std::string& tag : EnemyLine_TagAll)
		{
			DrawLine(m_EmyLine_Pos[tag].x, m_EmyLine_Pos[tag].y, m_EmyLine_Pos[tag].x + m_ObjSize.x, m_EmyLine_Pos[tag].y + m_ObjSize.y, GetColor(static_cast<int>(m_collarcode[tag].x), static_cast<int>(m_collarcode[tag].y), static_cast<int>(m_collarcode[tag].z)), FALSE);
		}
		DrawFormatString(0, 800, GetColor(255, 255, 255), "�G�̃��Z�b�g�܂�:%f", m_ResetCount);
	}
#endif
}
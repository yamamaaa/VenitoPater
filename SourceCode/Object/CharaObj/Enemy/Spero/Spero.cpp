#include "Spero.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"

namespace object
{
	Spero::Spero()
		:EnemyBase(global_objecttag.SPERO)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Spero::~Spero()
	{
		//�����Ȃ�
	}

	void Spero::LoadObject()
	{
		m_IDnumber = spero;

		m_DrawObjPos[appear] = { 860.0f,530.0f };
		m_DrawObjPos[replace] = { 600.0f,505.0f };
		m_DrawObjPos[replace_2] = { 1028.0f,450.0 };

		m_MoveSpeed = 0.3f;
		m_ObjDrawArea = 0;

		m_ObjImg[0] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetSperoData(0).c_str());
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetSperoData(1).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetSperoData(2).c_str());
		m_ObjImg[3] = -1;
	}

	void Spero::UpdateObj(const float deltatime)
	{
		//�o����Ԏ擾
		bool is_appear = EnemyManager::GetIsAppear(m_IDnumber);

		//�o�����ĂȂ��Ȃ�ȉ��̏����Ȃ�
		if (!is_appear)
			return;

		//�v���C���[������s����������
		if (AvoidStatus::GetIsAvoid())
		{
			AvoidAction();	//����s��������
		}

		//���̓G���A�N�V�������N�����ĂȂ�������
		if (!EnemyManager::GetEmyIsAction())
		{
			MoveObj(deltatime);	//�ړ�����
			IsHitEnemyLine();	//enemyline�����蔻��
			ObjStatusUp();		//hit������obj�̃Z�b�g
		}

		//�A�N�V�������C���ɓ��B������
		if (m_IsActionLine)
		{
			EnemyManager::SetEmyIsAction(true);
			EnemyManager::SetEmyIDAction(m_IDnumber);
			EnemyInAction();
		}

		//�v���C���[����𐬌�������obj�̃��Z�b�g
		if (m_IsEmyReset)
		{
			ExitObj();
		}
	}

	void Spero::DrawObj()
	{
		//�\���ł����Ԃ̎�
		if (IsObjDraw() || m_IsActionLine)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}

#ifdef DEBUG
		//emyline,box��,enemybox�\��
		EnemyManager::D_DrawStatus();
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Spero");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Spero::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed;	//�ړ����x�v�Z
	}
}
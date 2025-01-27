#include "Nil.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"

namespace object
{
	Nil::Nil()
		:EnemyBase(global_objecttag.NIL)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Nil::~Nil()
	{
		//�����Ȃ�
	}

	void Nil::LoadObject()
	{
		m_IDnumber = nil;

		m_DrawObjPos[appear] = { 940.0f,500.0 };
		m_DrawObjPos[replace] = { 900.0f,450.0f };
		m_DrawObjPos[replace_2] = { 770.0f,270.0f };

		m_MoveSpeed = 24.0f;
		m_ObjDrawArea = 1;

		m_ObjImg[0] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetNilData(0).c_str());
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetNilData(1).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetNilData(2).c_str());
		m_ObjImg[3] = -1;
	}

	void Nil::UpdateObj(const float deltatime)
	{
		//�^�C���I�[�o�[���Ă����珈���Ȃ�
		if (TimeStatus::GetIsTimeOver())
			return;
		//�o����Ԏ擾
		bool is_appear = EnemyManager::GetIsAppear(m_IDnumber);

		//�o�����ĂȂ��Ȃ�ȉ��̏����Ȃ�
		if (!is_appear)
			return;

		//�v���C���[������s����������
		if (AvoidStatus::GetIsAvoid())
		{
			AvoidAction(deltatime);	//����s��������
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
			ExitObj(deltatime);
		}
	}

	void Nil::DrawObj()
	{
		//�\���ł����Ԃ̎�
		if (IsObjDraw())
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}

#ifdef DEBUG
		//emyline,box��,enemybox�\��
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Nil");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Nil::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed* deltatime;	//�ړ����x�v�Z
	}
}
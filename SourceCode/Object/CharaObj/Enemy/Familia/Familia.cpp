#include "Familia.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../StageObj/ClockWork/RPMController/RPMController.h"

namespace object
{
	Familia::Familia()
		:EnemyBase(global_objecttag.FAMILIA)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Familia::~Familia()
	{
		//�����Ȃ�
	}

	void Familia::LoadObject()
	{
		m_MoveSpeed = 0.3f;
		m_ObjDrawArea = 3;

		m_IDnumber = familia;

		m_DrawObjPos[appear] = { 400.0f,0.0f };
		m_DrawObjPos[replace] = m_DrawObjPos[appear];
		m_DrawObjPos[replace_2] = { 230.0f,0.0f };
		m_DrawObjPos[action] = { 0.0f,0.0f };

		m_ObjImg[0] = -1;
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetFamiliaData(0).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetFamiliaData(1).c_str());
		m_ObjImg[3] = -1;
	}

	void Familia::UpdateObj(const float deltatime)
	{
		//��]�ʂ�0�ȉ��ɂȂ������o��
		if (!RPMController::GetIsRPMLost())
			return;

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
	}

	void Familia::DrawObj()
	{
		//��]�ʂ�0�ȉ��ɂȂ������o��
		if (!RPMController::GetIsRPMLost())
			return;

		//�\���ł��鎞
		if (IsObjDraw())
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}


#ifdef DEBUG
		//emyline,box��,enemybox�\��
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Familia");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Familia::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed;	//�ړ����x�v�Z
	}
}
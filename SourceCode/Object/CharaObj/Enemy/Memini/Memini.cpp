#include "Memini.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"

namespace object
{
	Memini::Memini()
		:EnemyBase(global_objecttag.MEMINI)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Memini::~Memini()
	{
		//�����Ȃ�
	}

	void Memini::LoadObject()
	{
		m_IDnumber = memini;

		m_DrawObjPos[appear] = { 850.0f,505.0f };
		m_DrawObjPos[replace] = { 1020.0f,538.0f };
		m_DrawObjPos[replace_2] = { 720.0f,214.0f };

		m_MoveSpeed = 0.5f;
		m_ObjDrawArea = 2;

		m_ObjImg[0] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetMeminiData(0).c_str());
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetMeminiData(1).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetMeminiData(2).c_str());
		m_ObjImg[3] = -1;
	}

	void Memini::UpdateObj(const float deltatime)
	{
		//�^�C���I�[�o�[���Ă����珈���Ȃ�
		if (TimeStatus::GetIsTimeOver())
			return;

		EnemyManager::EmyAppearSetting();

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
			LightController::SetIsBlinking(true);
			ExitObj();
		}
	}

	void Memini::DrawObj()
	{
		//�\���ł����Ԃ̎�
		if (IsObjDraw())
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}

#ifdef DEBUG
		//emyline,box��,enemybox�\��
		EnemyManager::D_DrawStatus();
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Memini");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Memini::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed;	//�ړ����x�v�Z
	}
}
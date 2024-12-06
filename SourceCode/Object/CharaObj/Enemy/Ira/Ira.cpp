#include "Ira.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"

namespace object
{
	Ira::Ira()
		:EnemyBase(global_objecttag.IRA)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Ira::~Ira()
	{
		//�����Ȃ�
	}

	void Ira::LoadObject()
	{
		m_Idnumber = ira;

		m_DrawObjPos[appear] = { 1000.0f,630.0f };
		m_DrawObjPos[replace] = { 632.0f,525.0f };
		m_DrawObjPos[replace_2] = m_DrawObjPos[replace];
		m_DrawObjPos[action] = { 0.0f,665.0f };

		m_MoveSpeed = 10.0f;
		m_ObjDrawArea = 0;

		m_ObjImg[0] = LoadGraph("../Asset/image/enemy/ira/place_0.png");
		m_ObjImg[1] = LoadGraph("../Asset/image/enemy/ira/place_1.png");
		m_ObjImg[2] = m_ObjImg[1];
		m_ObjImg[3] = LoadGraph("../Asset/image/enemy/ira/place_2.png");
	}

	void Ira::UpdateObj(const float deltatime)
	{
		//�o����Ԏ擾
		bool is_appear = EnemyManager::GetIsAppear(m_Idnumber);

		//�o�����ĂȂ��Ȃ�ȉ��̏����Ȃ�
		if (!is_appear)
			return;

		//�v���C���[������s����������
		if (AvoidStatus::GetIsAvoid())
		{
			if (!EnemyManager::GetBeefUpEmyIsAction())
			{
				AvoidAction();	//����s��������
			}
		}

		//�������ԂȂ�
		if (EnemyManager::GetCanMove())
		{
			MoveObj(deltatime);	//�ړ�����
			IsHitEnemyLine();	//enemyline�����蔻��
			ObjStatusUp();		//hit������obj�̃Z�b�g
		}

		//�����������C���𒲂ׂ�
		int linenum=GetHitLineIndex();

		//actionline�ɓ������Ă�����G�S�̂̋���
		if (action == linenum)
		{
			EnemyManager::SetBeefUpEmyIsAction(true);
		}

		//�v���C���[����𐬌�������obj�̃��Z�b�g
		if (m_IsEmyReset)
		{
			ExitObj();
		}
	}

	void Ira::DrawObj()
	{
		//�\���ł����Ԃ̎�
		if (IsObjDraw())
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}

		//���Z�b�g����ʂ̖���
		if (m_IsEmyReset)
		{
			LightController::ScreenBlinking();
		}

#ifdef DEBUG
		//emyline,box��,enemybox�\��
		EnemyManager::D_DrawStatus();
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Ira");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Ira::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed;	//�ړ����x�v�Z
	}
}
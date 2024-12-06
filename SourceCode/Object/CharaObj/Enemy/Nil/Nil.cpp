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
		m_Idnumber = nil;

		m_DrawObjPos[appear] = { 940.0f,500.0 };
		m_DrawObjPos[replace] = { 900.0f,450.0f };
		m_DrawObjPos[replace_2] = { 770.0f,270.0f };
		m_DrawObjPos[action] = { 0.0f,0.0f };

		m_MoveSpeed = 0.1f;
		m_ObjDrawArea = 1;

		m_ObjImg[0] = LoadGraph("../Asset/image/enemy/nil/place_0.png");
		m_ObjImg[1] = LoadGraph("../Asset/image/enemy/nil/place_1.png");
		m_ObjImg[2] = LoadGraph("../Asset/image/enemy/nil/place_2.png");
		m_ObjImg[3] = LoadGraph("../Asset/image/enemy/nil/place_3.png");
	}

	void Nil::UpdateObj(const float deltatime)
	{
		//�o����Ԏ擾
		bool is_appear = EnemyManager::GetIsAppear(m_Idnumber);

		//�o�����ĂȂ��Ȃ�ȉ��̏����Ȃ�
		if (!is_appear)
			return;

		//�v���C���[������s����������
		if (AvoidStatus::GetIsAvoid())
		{
			AvoidAction();	//����s��������
		}

		//���������X�^�[���A�N�V�������N��������
		if (EnemyManager::GetBeefUpEmyIsAction())
		{
			BeefUpEmyAction();	//���g�̋���
		}

		//�������ԂȂ�
		if (EnemyManager::GetCanMove())
		{
			MoveObj(deltatime);	//�ړ�����
			IsHitEnemyLine();	//enemyline�����蔻��
			ObjStatusUp();		//hit������obj�̃Z�b�g
		}

		//�A�N�V�������C���ɓ��B������
		if (m_IsActionLine)
		{
			EnemyManager::SetCanMove(false);	//�S�G�̍X�V���~�߂�
			EnemyInAction();
		}

		//�v���C���[����𐬌�������obj�̃��Z�b�g
		if (m_IsEmyReset)
		{
			ExitObj();
		}

	}

	void Nil::DrawObj()
	{
		//�\���ł����Ԃ̎�
		if (IsObjDraw() || m_IsActionLine)
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
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Nil");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Nil::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed;	//�ړ����x�v�Z
	}
}
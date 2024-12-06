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
		m_Idnumber = memini;

		m_DrawObjPos[appear] = { 850.0f,505.0f };
		m_DrawObjPos[replace] = { 1020.0f,538.0f };
		m_DrawObjPos[replace_2] = { 720.0f,214.0f };
		m_DrawObjPos[action] = { 0.0f,0.0f };

		m_MoveSpeed = 0.1f;
		m_ObjDrawArea = 2;

		m_ObjImg[0] = LoadGraph("../Asset/image/enemy/memini/place_0.png");
		m_ObjImg[1] = LoadGraph("../Asset/image/enemy/memini/place_1.png");
		m_ObjImg[2] = LoadGraph("../Asset/image/enemy/memini/place_2.png");
		m_ObjImg[3] = LoadGraph("../Asset/image/enemy/memini/place_3.png");
	}

	void Memini::UpdateObj(const float deltatime)
	{
		EnemyManager::EmyAppearSetting();

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
		if(EnemyManager::GetCanMove())
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

	void Memini::DrawObj()
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
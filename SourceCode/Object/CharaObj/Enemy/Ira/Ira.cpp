#include "Ira.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"
#include "../../../ObjectManager/ObjectManager.h"
#include "../../../NumDays/NumDays.h"

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
		m_IDnumber = ira;

		m_DrawObjPos[replace] = { 1000.0f,630.0f };
		m_DrawObjPos[replace_2] = { 632.0f,525.0f };
		m_DrawObjPos[action] = { 0.0f,665.0f };

		m_MoveSpeed[0] = 6.0f;
		m_MoveSpeed[1] = 18.0f;
		m_MoveSpeed[2] = 24.0f;

		//�v���C���[�h�ʂɏ����ݒ�
		PlayMenu menu = ObjectManager::GetPlayMode();
		if (menu == PlayNewGame)
		{
			//���݂������ڂ��擾
			int day = NumDays::GetNumDays();

			//�J�E���g�l�̏�����
			m_NowMoveSpeed = m_MoveSpeed[day-1];
		}
		else
		{
			//�J�E���g�l�̏�����
			m_NowMoveSpeed = m_MoveSpeed[2];
		}

		m_ObjDrawArea = 0;

		m_ObjImg[0] = -1;
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetIraData(0).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetIraData(1).c_str());
		m_ObjImg[3] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetIraData(2).c_str());
	}

	void Ira::UpdateObj(const float deltatime)
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
			if (!EnemyManager::GetBeefUpEmyIsAction())
			{
				AvoidAction(deltatime);	//����s��������
			}
		}

		//���̓G���A�N�V�������N�����ĂȂ�������
		if (!EnemyManager::GetEmyIsAction())
		{
			MoveObj(deltatime);	//�ړ�����
			IsHitEnemyLine();	//enemyline�����蔻��
			ObjStatusUp();		//hit������obj�̃Z�b�g
		}

		//�����������C���𒲂ׂ�
		int linenum = GetHitLineIndex();

		//actionline�ɓ������Ă�����[���}�C��]�𑁂߂�
		if (action == linenum)
		{
			EnemyManager::SetBeefUpEmyIsAction(true);
		}

		//�v���C���[����𐬌�������obj�̃��Z�b�g
		if (m_IsEmyReset)
		{
			ExitObj(deltatime);
		}
	}

	void Ira::DrawObj()
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
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Ira");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Ira::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_NowMoveSpeed * deltatime;	//�ړ����x�v�Z
	}
}
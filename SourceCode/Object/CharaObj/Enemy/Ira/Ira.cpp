#include "Ira.h"
#include "../../../ObjectTag/Play_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"
#include "../../../ObjectManager/ObjectManager.h"
#include "../../../../NumDays/NumDays.h"
#include "../../../../SoundController/SoundController.h"

namespace object
{
	Ira::Ira()
		:EnemyBase(play_ObjectTag.IRA)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Ira::~Ira()
	{
		DeleteGraph(m_ObjHandle);

		for (int i = 0; i < 4; i++)
		{
			DeleteGraph(m_ObjImg[i]);
		}
	}

	void Ira::LoadObject()
	{
		m_IDnumber = ira;

		m_DrawObjPos[replace] = { 1000.0f,630.0f };
		m_DrawObjPos[replace_2] = { 632.0f,525.0f };
		m_DrawObjPos[action] = { 0.0f,700.0f };

		m_MoveSpeed[0] = 18.0f;
		m_MoveSpeed[1] = 24.0f;
		m_MoveSpeed[2] = 30.0f;

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

		auto json = JsonManager::SoundData_Instance()->Get_Play_SoundData_Instance();
		m_JsonTag = json->GetIra_NameData();
		sound_controller::SoundController::AddSoundData(json->GetIra_PathData(), m_JsonTag, json->GetIra_VolumeData(), json->GetIra_TypeData());

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
		else
		{
			AvoidReset();
		}

		//�����������C���𒲂ׂ�
		int linenum = GetHitLineIndex();

		//actionline�ɓ������Ă�����[���}�C��]�𑁂߂�
		if (action == linenum)
		{
			EnemyManager::SetBeefUpEmyIsAction(true);

			//action���ŕ\���ł���Ƃ�BGM�𗬂�
			if (IsObjDraw()&& !EnemyManager::GetEmyIsAction())
				sound_controller::SoundController::StartSound(m_JsonTag);
			else
				sound_controller::SoundController::StopSound(m_JsonTag);
		}
		else
		{
			//���̓G���A�N�V�������N�����ĂȂ�������
			if (!EnemyManager::GetEmyIsAction())
			{
				MoveObj(deltatime);	//�ړ�����
				IsHitEnemyLine();	//enemyline�����蔻��
				ObjStatusUp();		//hit������obj�̃Z�b�g
			}
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

#if DEBUG
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
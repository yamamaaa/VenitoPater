#include "ThreeDays.h"

#include"../../Object/ObjectManager/ObjectManager.h"
#include"../../Object/ObjectTag/ThreeDays_ObjectTag.h"

#include"../Result/Result.h"

#include"../../Object/CharaObj/AvoidStatus/AvoidStatus.h"

#include"../../Object/StageObj/ItemGetNum/ItemGetNum.h"
#include"../../Object/StageObj/Area/Area.h"
#include"../../Object/StageObj/MoveArea/MoveArea.h"
#include"../../Object/StageObj/ClockWork/ClockWork/ClockWork.h"
#include"../../Object/StageObj/Item/Item.h"

#include"../../Object/CharaObj/Enemy/EnemyManager/EnemyManager.h"
#include"../../Object/CharaObj/Enemy/Familia/Familia.h"
#include"../../Object/CharaObj/Enemy/Memini/Memini.h"
#include"../../Object/CharaObj/Enemy/Nil/Nil.h"
#include"../../Object/CharaObj/Enemy/Spero/Spero.h"
#include"../../Object/CharaObj/Enemy/Ira/Ira.h"

#include"../../Object/CharaObj/Avoid/Avoid.h"
#include"../../Object/CharaObj/Player/Player.h"

#include"../../Object/GameUi/ItemUi/ItemUi.h"
#include"../../Object/GameUi/RPMHPUi/RPMHPUi.h"
#include"../../Object/GameUi/AvoidUi/AvoidUi.h"
#include"../../Object/GameUi/WarningUi/WarningUi.h"

#include"../../Object/NumDays/NumDays.h"
#include"../../Object/Time/Time/Time.h"
#include"../../Object/Time/TimeStatus/TimeStatus.h"

#include"../../Object/CharaObj/Enemy/EnemyAction/EnemyAction.h"

namespace scene
{
	ThreeDays::ThreeDays()
		:SceneBase()
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	ThreeDays::~ThreeDays()
	{
		//�����Ȃ�
	}

	void ThreeDays::LoadObject()
	{
		//�I�u�W�F�N�g�^�O���Z�b�g
		object::ObjectManager::NowSceneSet(objecttag::ThreeDays_ObjTagAll);
		//Game��Ԃ��Z�b�g
		object::ObjectManager::SetNowGameState(object::GamePlay);
		object::ObjectManager::SetNextGameState(object::GamePlay);

		//�X�e�[�W���I�u�W�F�̐���
		object::AvoidStatus::Initialize();
		object::ObjectManager::Entry(new object::Area);
		object::ObjectManager::Entry(new object::MoveArea);
		object::ObjectManager::Entry(new object::ClockWork);
		object::ItemGetNum::Initialize();
		object::ObjectManager::Entry(new object::Item);

		//�G�̐���
		object::EnemyManager::Initialize();
		object::ObjectManager::Entry(new object::Familia);
		object::ObjectManager::Entry(new object::Memini);
		object::ObjectManager::Entry(new object::Nil);
		object::ObjectManager::Entry(new object::Spero);
		object::ObjectManager::Entry(new object::Ira);

		//�v���C���[�֘A����
		object::ObjectManager::Entry(new object::Avoid);
		object::ObjectManager::Entry(new object::Player);

		//�Q�[��Ui����
		object::ObjectManager::Entry(new object::ItemUi);
		object::ObjectManager::Entry(new object::RPMHPUi);
		object::ObjectManager::Entry(new object::AvoidUi);
		object::ObjectManager::Entry(new object::WarningUi);

		//Time�֘A����
		object::TimeStatus::Initialize();
		object::ObjectManager::Entry(new object::Time);

		//�G�̃A�N�V��������
		object::ObjectManager::Entry(new object::EnemyAction);

		//�t�F�[�h�t���O������
		m_FadeInSet = false;
	}

	SceneBase* ThreeDays::UpdateScene(const float deltaTime)
	{
		object::ObjectManager::UpdateAllObj(deltaTime);

		//�Q�[���N���A������
		if (object::GameClear== object::ObjectManager::GetNowGameState() || object::GameOver == object::ObjectManager::GetNowGameState())
		{
			object::ObjectManager::ReleaseAllObj();
			return new Result;
		}

		return this;
	}

	void ThreeDays::DrawScene()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "3Days");

		//�Q�[���X�e�[�^�X���ς������
		if (object::ObjectManager::GetNowGameState() != object::ObjectManager::GetNextGameState())
		{
			//�t�F�[�h����������
			fade_transitor->FadeOutStart(true);
			TransitorScene();
		}

		if (!m_FadeInSet)
		{
			//�t�F�[�h�C��
			fade_transitor->FadeInStart(false);
			LoadScene();
		}

		object::ObjectManager::DrawAllObj();
		object::NumDays::DrawNumDays();
	}
}

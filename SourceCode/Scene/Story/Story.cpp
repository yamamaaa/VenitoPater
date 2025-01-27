#include "Story.h"

#include"../../Object/ObjectTag/Story_ObjectTag.h"

#include"../ThreeDays/ThreeDays.h"

#include"../../Object/StoryObj/LineStatus/LineStatus.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/StoryObj/Character/Character.h"
#include"../../Object/StoryObj/StoryItem/StoryItem.h"
#include"../../Object/StoryObj/Line/Line.h"

#include"../../Object/ObjectTag/Still_ObjectTag.h"

#include"../../Object/StoryObj/StillDraw/StillDraw.h"

namespace scene
{
	Story::Story()
		:SceneBase()
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Story::~Story()
	{
		//�����Ȃ�
	}

	void Story::LoadObject()
	{
		if (object::Story == object::ObjectManager::GetNowGameState())
		{
			//�I�u�W�F�N�g�^�O���Z�b�g
			object::ObjectManager::NowSceneSet(objecttag::Story_ObjectTagAll);
			//Game��Ԃ��Z�b�g
			object::ObjectManager::SetNextGameState(object::Story);

			object::LineStatus::Initialize();
			object::ObjectManager::Entry(new object::BackGround);
			object::ObjectManager::Entry(new object::Character);
			object::ObjectManager::Entry(new object::StoryItem);
			object::ObjectManager::Entry(new object::Line);
		}
		if (object::Still == object::ObjectManager::GetNowGameState())
		{
			//�I�u�W�F�N�g�^�O���Z�b�g
			object::ObjectManager::NowSceneSet(objecttag::still_ObjectTagAll);
			//Game��Ԃ��Z�b�g
			object::ObjectManager::SetNextGameState(object::Still);

			object::LineStatus::Initialize();
			object::ObjectManager::Entry(new object::StillDraw);
			object::ObjectManager::Entry(new object::Line);
		}

		//�t�F�[�h�t���O������
		m_FadeInSet = false;
		IsNextStory = false;
	}

	SceneBase* Story::UpdateScene(const float deltaTime)
	{
		if (!m_FadeInSet)
		{
			transitor::FadeTransitor::FadeInStart(deltaTime);
			LoadScene();
		}

		//���݂̃X�e�[�^�X���擾
		object::GameStatus status = object::ObjectManager::GetNowGameState();

		//�Q�[���X�e�[�^�X���ς������V�[���؂�ւ�����������
		if (status != object::ObjectManager::GetNextGameState())
		{
			m_IsChangeScene = true;
			transitor::FadeTransitor::FadeOutStart(deltaTime);

			//�������I�������X�e�[�^�X�̕ύX�ƌ㏈��
			if (transitor::FadeTransitor::IsFadeDone())
			{
				//���̃X�e�[�^�X���擾���Z�b�g
				object::GameStatus status_next = object::ObjectManager::GetNextGameState();
				object::ObjectManager::SetNowGameState(status);

				object::ObjectManager::ReleaseAllObj();
				transitor::FadeTransitor::FadeProcessing();

				//���̃V�[���������X�g�[���[�V�[����
				if (object::Story == status_next || object::Still == status_next)
				{
					IsNextStory = true;
				}
			}
		}
		else
		{
			object::ObjectManager::UpdateAllObj(deltaTime);
		}

		if (object::GamePlay == status)
		{
			return new ThreeDays;
		}

		if (IsNextStory)
		{
			IsNextStory = false;
			return new Story;
		}

		return this;
	}

	void Story::DrawScene()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Story");

		if (m_IsChangeScene || !m_FadeInSet)
		{
			transitor::FadeTransitor::DrawFade();
		}

		object::ObjectManager::DrawAllObj();
	}
}
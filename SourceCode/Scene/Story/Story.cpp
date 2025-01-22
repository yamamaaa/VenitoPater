#include "Story.h"

#include"../../Object/ObjectTag/Story_ObjectTag.h"

#include"../ThreeDays/ThreeDays.h"

#include"../../Object/StoryObj/LineStatus/LineStatus.h"

#include"../../Object/StoryObj/Character/Character.h"
#include"../../Object/Result/BackGround/BackGround.h"
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
		object::ObjectManager::UpdateAllObj(deltaTime);

		if (object::GamePlay == object::ObjectManager::GetNowGameState())
		{
			object::ObjectManager::ReleaseAllObj();
			return new ThreeDays;
		}

		if (IsNextStory && fade_transitor->IsFadeDone())
		{
			object::ObjectManager::ReleaseAllObj();
			return new Story;
		}
		return this;
	}

	void Story::DrawScene()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Story");

		//�Q�[���X�e�[�^�X���ς������
		if (object::ObjectManager::GetNowGameState() != object::ObjectManager::GetNextGameState())
		{
			//�t�F�[�h����������
			fade_transitor->FadeOutStart(true);
			TransitorScene();
			
			//���̃V�[���������X�g�[���[�V�[����
			if (object::Story == object::ObjectManager::GetNextGameState() || object::Still == object::ObjectManager::GetNextGameState())
			{
				IsNextStory = true;
			}
		}

		if (!m_FadeInSet)
		{
			//�t�F�[�h�C��
			fade_transitor->FadeInStart(false);
			LoadScene();
		}

		object::ObjectManager::DrawAllObj();
	}
}
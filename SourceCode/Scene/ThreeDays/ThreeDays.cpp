#include "ThreeDays.h"

namespace scene
{
	ThreeDays::ThreeDays()
	{
	}

	ThreeDays::~ThreeDays()
	{
		//�����Ȃ�
	}

	SceneBase* ThreeDays::UpdateScene(const float deltaTime)
	{

		//�V�[���؂�ւ�
		/*if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
		{
			ObjManager::DeleteAllObj();
			return new Title;
		}*/

		return this;
	}

	void ThreeDays::DrawScene()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "3Days");
	}
}

#include "Area.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../AreaNumController/AreaNumController.h"
#include "../../../SoundController/SoundController.h"

namespace object
{
	Area::Area()
		:ObjectBase(global_objecttag.AREA)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Area::~Area()
	{
		//�����Ȃ�
	}

	void Area::LoadObject()
	{
		//�C���X�^���X����
		AreaNumController::Initialize();

		//���W�ݒ�
		m_ObjPos.x = 0;
		m_ObjPos.y = 0;

		//�摜�̓ǂݍ���
		for (int i = 0; i < 4; i++)
		{
			m_AreaImg[i] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetStageData(i).c_str());
		}

		//�\���G���A�̏����l�Z�b�g
		m_ObjHandle = m_AreaImg[AreaNumController::GetAreaNum()];

		sound_controller::SoundController::AddSoundData("../Asset/sound/play/bgm.mp3","bgm", 150, true);
	}

	void Area::UpdateObj(const float deltatime)
	{
		//�\���G���A�̍X�V
		m_ObjHandle = m_AreaImg[AreaNumController::GetAreaNum()];
		sound_controller::SoundController::StartSound("bgm");
	}

	void Area::DrawObj()
	{
		//�G���A�̕\��
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}
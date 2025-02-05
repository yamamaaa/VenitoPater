#include "Area.h"
#include "../../ObjectTag/Play_ObjectTag.h"
#include "../AreaNumController/AreaNumController.h"
#include "../../../SoundController/SoundController.h"

namespace object
{
	Area::Area()
		:ObjectBase(play_ObjectTag.AREA)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Area::~Area()
	{
		for (int i = 0; i < 4; i++)
		{
			DeleteGraph(m_AreaImg[i]);
		}
		DeleteGraph(m_ObjHandle);
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

		auto json = JsonManager::SoundData_Instance()->Get_Play_SoundData_Instance();
		m_JsonTag = json->GetBgmNameData();
		sound_controller::SoundController::AddSoundData(json->GetBgmPathData(), m_JsonTag, json->GetBgmVolumeData(), json->GetBgmTypeData());
	}

	void Area::UpdateObj(const float deltatime)
	{
		//�\���G���A�̍X�V
		m_ObjHandle = m_AreaImg[AreaNumController::GetAreaNum()];
		sound_controller::SoundController::StartSound(m_JsonTag);
	}

	void Area::DrawObj()
	{
		//�G���A�̕\��
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}
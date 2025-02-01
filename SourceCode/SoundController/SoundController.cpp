#include <Dxlib.h>
#include "SoundController.h"

namespace sound_controller
{
	std::unique_ptr<SoundController>SoundController::soundcontroller = nullptr;

	SoundController::SoundController()
	{
	}

	SoundController::~SoundController()
	{
		Release_AllSound();
	}

	void SoundController::Initialize()
	{
		//実態が空ならインスタンス生成
		if (!soundcontroller)
		{
			soundcontroller.reset(new SoundController);
		}

		soundcontroller->m_BGMAns = 0;
		soundcontroller->m_IsDone_Fade = false;
	}

	void SoundController::AddSoundData(std::string filename, std::string soundname, int volume, bool type)
	{	
		soundcontroller->m_SoundName.push_back(soundname);
		soundcontroller->m_Soundlist[soundname].m_Handle= LoadSoundMem(filename.c_str());
		soundcontroller->m_Soundlist[soundname].m_Volume = volume;
		soundcontroller->m_Soundlist[soundname].m_IsType = type;

		if (type)
		{
			soundcontroller->m_BGMAns++;
		}

		soundcontroller->m_SoundAns++;
	}

	void SoundController::StartSound(std::string soundname)
	{
		auto sound = soundcontroller->m_Soundlist[soundname];

		ChangeVolumeSoundMem(sound.m_Volume, sound.m_Handle);

		//再生されてなかったらサウンド再生
		if (sound.m_IsType)
		{
			//BGMならループ再生
			if (!CheckSoundMem(sound.m_Handle))
			{
				PlaySoundMem(sound.m_Handle, DX_PLAYTYPE_BACK + DX_PLAYTYPE_LOOP);
			}
		}
		else
		{
			PlaySoundMem(sound.m_Handle, DX_PLAYTYPE_BACK);
		}
	}

	void SoundController::StopSound(std::string soundname)
	{
		auto sound = soundcontroller->m_Soundlist[soundname];

		ChangeVolumeSoundMem(sound.m_Volume, sound.m_Handle);

		//再生中なら停止
		if (CheckSoundMem(sound.m_Handle))
		{
			StopSoundMem(sound.m_Handle);
		}
	}

	void SoundController::BGMSoundFadeOut(const float deltatime)
	{
		static int volume;

		for (std::string name_se : soundcontroller->m_SoundName)
		{
			auto& sound_se = soundcontroller->m_Soundlist[name_se];
			if (CheckSoundMem(sound_se.m_Handle) && !sound_se.m_IsType)
				return;
		}

		for (std::string name : soundcontroller->m_SoundName)
		{
			auto &sound = soundcontroller->m_Soundlist[name];

			if (sound.m_IsType)
			{
				sound.m_Volume -= volume;
				volume += static_cast <int>(110.0f * deltatime);
				ChangeVolumeSoundMem(sound.m_Volume, sound.m_Handle);

				if (sound.m_Volume <= 0&& soundcontroller->m_BGMAns>0)
				{
					soundcontroller->m_BGMAns--;
				}
			}
		}

		if (soundcontroller->m_BGMAns==0)
		{
			soundcontroller->m_IsDone_Fade = true;
		}
	}

	void SoundController::FadeSoundProcessing()
	{
		soundcontroller->m_BGMAns = 0;
		soundcontroller->m_IsDone_Fade = false;
		Release_AllSound();
	}

	void SoundController::Release_AllSound()
	{
		//サウンドの削除
		for (std::string name : soundcontroller->m_SoundName)
		{
			if (soundcontroller->m_Soundlist.empty())
			{
				DeleteSoundMem(soundcontroller->m_Soundlist[name].m_Handle);
			}
		}

		soundcontroller->m_SoundName.clear();
		soundcontroller->m_Soundlist.clear();
	}

	SoundController::SoundData::SoundData()
		:m_Handle(-1),
		m_Volume(200),
		m_IsType(false)
	{
	}
}
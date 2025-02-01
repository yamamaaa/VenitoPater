#pragma once
#include<memory>
#include <unordered_map>
#include <string>

namespace sound_controller
{
	/// <summary>
	/// �Q�[�����̃T�E���h�֘A
	/// </summary>
	class SoundController final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~SoundController();

		/// <summary>
		/// �T�E���h�̒ǉ�
		/// </summary>
		/// <param name="filename">�t�@�C����</param>
		/// <param name="soundname">�T�E���h��</param>
		/// <param name="volume">����</param>
		/// <param name="type">�T�E���h�^�C�v|true:���[�v|false:���[�v���Ȃ�</param>
		static void AddSoundData(std::string filename, std::string soundname, int volume, bool type);

		/// <summary>
		/// �T�E���h�̍Đ�
		/// </summary>
		/// <param name="soundname">�T�E���h�l�[��</param>
		static void StartSound(std::string soundname);

		/// <summary>
		/// �T�E���h�̒�~
		/// </summary>
		/// <param name="soundname">�T�E���h�l�[��</param>
		static void StopSound(std::string soundname);

		/// <summary>
		/// �S�ẴT�E���h�̃t�F�[�h�A�E�g
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		static void BGMSoundFadeOut(const float deltatime);

		/// <summary>
		/// �t�F�[�h�������I���������H
		/// </summary>
		/// <returns>true:����|false:������</returns>
		static bool IsDoneSoundFade() { return soundcontroller->m_IsDone_Fade; }

		/// <summary>
		/// �t�F�[�h�㏈��
		/// </summary>
		/// <returns></returns>
		static void FadeSoundProcessing();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		SoundController();

		/// <summary>
		/// �T�E���h���X�g�̍폜
		/// </summary>
		static void Release_AllSound();

		/// <summary>
		/// �T�E���h�f�[�^
		/// </summary>
		struct SoundData
		{
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			SoundData();

			int m_Handle;             //�T�E���h�n���h��
			int m_Volume;             //����
			bool m_IsType;			  //���̃^�C�v��Bgm���H
		};

		bool m_IsDone_Fade;		//�t�F�[�h�������I��������H
		int m_BGMAns;			//�o�^���ꂽBGM�̑���
		int m_SoundAns;			//�o�^���ꂽ�T�E���h�̑���

		std::vector<std::string> m_SoundName;
		std::unordered_map<std::string, SoundData> m_Soundlist;		//�T�E���h���X�g

		static std::unique_ptr<class SoundController> soundcontroller;//���g�̎���
	};
}
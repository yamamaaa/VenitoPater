#pragma once
#include<memory>
#include <unordered_map>
#include <string>

namespace sound_controller
{
	/// <summary>
	/// ゲーム内のサウンド関連
	/// </summary>
	class SoundController final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~SoundController();

		/// <summary>
		/// サウンドの追加
		/// </summary>
		/// <param name="filename">ファイル名</param>
		/// <param name="soundname">サウンド名</param>
		/// <param name="volume">音量</param>
		/// <param name="type">サウンドタイプ|true:ループ|false:ループしない</param>
		static void AddSoundData(std::string filename, std::string soundname, int volume, bool type);

		/// <summary>
		/// サウンドの再生
		/// </summary>
		/// <param name="soundname">サウンドネーム</param>
		static void StartSound(std::string soundname);

		/// <summary>
		/// サウンドの停止
		/// </summary>
		/// <param name="soundname">サウンドネーム</param>
		static void StopSound(std::string soundname);

		/// <summary>
		/// 全てのサウンドのフェードアウト
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		static void BGMSoundFadeOut(const float deltatime);

		/// <summary>
		/// フェード処理が終了したか？
		/// </summary>
		/// <returns>true:完了|false:未完成</returns>
		static bool IsDoneSoundFade() { return soundcontroller->m_IsDone_Fade; }

		/// <summary>
		/// フェード後処理
		/// </summary>
		/// <returns></returns>
		static void FadeSoundProcessing();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		SoundController();

		/// <summary>
		/// サウンドリストの削除
		/// </summary>
		static void Release_AllSound();

		/// <summary>
		/// サウンドデータ
		/// </summary>
		struct SoundData
		{
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			SoundData();

			int m_Handle;             //サウンドハンドル
			int m_Volume;             //音量
			bool m_IsType;			  //音のタイプがBgmか？
		};

		bool m_IsDone_Fade;		//フェード処理が終わったか？
		int m_BGMAns;			//登録されたBGMの総数
		int m_SoundAns;			//登録されたサウンドの総数

		std::vector<std::string> m_SoundName;
		std::unordered_map<std::string, SoundData> m_Soundlist;		//サウンドリスト

		static std::unique_ptr<class SoundController> soundcontroller;//自身の実態
	};
}
#pragma once
#include<memory>

namespace transitor
{
	/// <summary>
	/// 場面切り替え関連_フェード
	/// </summary>
	class FadeTransitor final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~FadeTransitor();

		/// <summary>
		/// フェードインさせる
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		static void FadeInStart(const float deltatime);

		/// <summary>
		/// フェードアウトさせる
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		static void FadeOutStart(const float deltatime);

		/// <summary>
		/// フェードの描画
		/// </summary>
		static void DrawFade();

		/// <summary>
		/// フェード処理が完了したか
		/// </summary>
		/// <returns>true:完了|false:未完成</returns>
		static const bool IsFadeDone() { return fadetransitor->m_IsFadeDone; }

		/// <summary>
		/// フェード後処理
		/// </summary>
		/// <returns></returns>
		static const void FadeProcessing();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		FadeTransitor();

		/// <summary>
		/// 一定時間待つ
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		static void WaitTime(const float deltatime);

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObject();

		const float m_DROPSPEED = 50.0f;		//減分速度
		const float m_RISESPEED = 1.0f;			//増化速度

		static const int m_COLORCODE = 255;	//カラーコード

		const float m_WAITMAX = 1.2f;			//待ち時間
		const float m_COUNT_DECREMENT = 3.0f;	//カウント減分値

		int m_Color;					//カラーコード
		float m_Calculation;			//算出

		bool m_IsFadeDone;				//処理が終わったか
		bool m_IsWait;					//一定時間待つか
		bool m_CanFade;					//フェード開始できるか

		float m_WaitCount;				//一定時間カウント

		static std::unique_ptr<class FadeTransitor> fadetransitor;//自身の実態
	};

}
#pragma once

namespace transitor
{
	class FadeTransitor
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		FadeTransitor();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~FadeTransitor();

		/// <summary>
		/// フェードアウトさせる
		/// </summary>
		/// <param name="wait">true:startをずらす|false:startをずらさない</param>
		void FadeOutStart(bool wait);

		/// <summary>
		/// フェードインさせる
		/// </summary>
		/// <param name="wait">true:startをずらす|false:startをずらさない</param>
		void FadeInStart(bool wait);

		/// <summary>
		/// フェード処理が完了したか
		/// </summary>
		/// <returns>true:完了|false:未完成</returns>
		const bool IsFadeDone() const { return m_IsFadeDone; }

		/// <summary>
		/// フェード後処理
		/// </summary>
		/// <returns></returns>
		const void FadeProcessing();

	private:

		/// <summary>
		/// 一定時間待つ
		/// </summary>
		void WaitTime();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		void LoadObject();

		const float m_DROPSPEED = 5.0f;				//減分速度
		const float m_RISESPEED = 0.01f;			//増化速度

		const int m_COLORCODE = 255;	//カラーコード

		const float m_WAITMAX = 50.0f;			//待ち時間
		const float m_COUNT_DECREMENT = 1.0f;	//カウント減分値

		int m_Color;					//カラーコード
		float m_Calculation;			//算出

		bool m_IsFadeDone;				//処理が終わったか
		bool m_WaitDone;				//一定時間待ったか
		bool m_CanFade;					//フェード開始できるか

		float m_WaitCount;				//一定時間カウント
	};

}
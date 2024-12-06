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
		/// フェード処理が完了したか
		/// </summary>
		/// <returns>true:完了|false:未完成</returns>
		const bool IsFadeDone() const { return m_IsFadeDone; }

	private:

		/// <summary>
		/// WaitTimerで一定時間待つ
		/// </summary>
		void WaitTimerStart();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		void LoadObject();

		const int m_DROPSPEED = 15;		//減分速度
		const int m_COLLARCODE = 255;	//カラーコード

		int m_DropCollar;				//減分カラーコード

		bool m_IsFadeDone;				//処理が終わったか
		bool m_WaitDone;				//一定時間待ったか

		float m_WaitCount;				//一定時間カウント
	};

}
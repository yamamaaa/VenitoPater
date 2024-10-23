#pragma once
#include <DxLib.h>

namespace Fps
{
	class Fps
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Fps();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Fps();

		/// <summary>
		/// 更新処理
		/// </summary>
		void Update();

		/// <summary>
		/// デルタタイム取得
		/// </summary>
		/// <returns>デルタタイム</returns>
		float GetDeltaTime()const { return m_deltaTime; }

	private:

		float m_nowTime;		//現在の時間
		float m_prevTime;		//過去の時間
		float m_deltaTime;		//デルタタイム
	};
}


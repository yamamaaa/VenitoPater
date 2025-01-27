#pragma once
#include "../../MouseBase/MouseBase.h"

namespace object
{
	/// <summary>
	/// 回避動作関連
	/// </summary>
	class Avoid :public MouseBase
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Avoid();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Avoid();

	private:

		/// <summary>
		/// 読み込み関連
		/// </summary>
		void LoadObject() override ;

		/// <summary>
		/// オブジェクトの更新
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		void UpdateObj(const float deltatime) override;

		/// <summary>
		/// オブジェクトの描画
		/// </summary>
		void DrawObj()override;

		/// <summary>
		/// 移動処理
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		void MoveObj(const float deltatime)override;

		POINTFLOAT m_DrawPos;	//画像表示座標

		const int m_AVOID_NOTNUM = 3;		//回避行動不可エリア

		const float m_CLICKCOUNT_MAX = 5.0f;	//再びクリックできるまで
		const float m_COUNTSPPED = 20.0f;		//カウントスピード

		float m_ClickCount ;		//クリックできるまでのカウント
		bool m_IsClick = true;		//クリックができるか

#ifdef DEBUG
		std::string m_avoid_status = "";			//回避状態の表示
		const VECTOR m_collarcode = {255,20,147};	//カラーコード
#endif
	};
}
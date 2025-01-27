#pragma once
#include<memory>

namespace object
{
	/// <summary>
	/// 回避中のUi関連
	/// </summary>
	class HatUi final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// Uiの描画
		/// </summary>
		static void DrawUi();

		/// <summary>
		/// 移動処理
		/// </summary>
		static void MoveUi();

		/// <summary>
		/// 移動値セット
		/// </summary>
		static void SetMove();

		/// <summary>
		/// UiのMove状態取得
		/// </summary>
		/// <returns></returns>
		static const bool GetIsMoveDone() { return hatui->m_IsMoveDone; }

		/// <summary>
		/// デストラクタ
		/// </summary>
		~HatUi();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		HatUi();

		/// <summary>
		/// Uiの読み込み
		/// </summary>
		static void LoadUi();

		POINTFLOAT m_UiPos;		//Ui座標

		int m_UiHandle;		//Uiハンドル

		bool m_IsMoveDone;		//Uiの動きが完了したか
		bool m_IsMoveDown;		//下に動き処理するか

		const float m_UIMOVE_POS = -320.0f;		//Ui移動座標
		const float m_UIMOVE_SPEED = 30.0f;		//Ui座標移動速度

		static std::unique_ptr<HatUi> hatui;	//自身の実態
	};
}
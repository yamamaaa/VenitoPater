#pragma once
#include <Dxlib.h>
#include <memory>

namespace object
{
	/// <summary>
	/// 照明関連クラス
	/// </summary>
	class LightController final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// ライトの描画
		/// </summary>
		static void DrawLight();

		/// <summary>
		/// 画面を点滅をさせるかセット
		/// </summary>
		/// <param name="status">true:点滅|false:点滅しない</param>
		static void SetIsBlinking(const bool status) { light_controller->m_IsBlinking = status; }

		/// <summary>
		/// デストラクタ
		/// </summary>
		~LightController();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		LightController();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObject();

		int m_DrawCount;	//点滅用画像表示カウント

		static const int m_PWRIOD = 10;		//表示周期
		static const int m_NUMTIMES = 5;	//表示回数

		int m_ShadowHandol;		//影画像ハンドル
		int m_LightHandol;		//ライト画像ハンドル
		int m_BlackImgHandol;	//黒画像ハンドル

		bool m_IsBlinking;		//画面を点滅するか
		POINTS m_LightPos;	//ライト座標

		static std::unique_ptr<LightController> light_controller;	//自身の実態
	};
}
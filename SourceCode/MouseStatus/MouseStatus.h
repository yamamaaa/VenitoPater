#pragma once
#include <memory>

namespace mousestatus
{
	/// <summary>
	/// マウス状態関連
	/// </summary>
	class MouseStatus final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~MouseStatus();

		/// <summary>
		/// フェード処理が終わって入力を受け付けるか取得
		/// </summary>
		/// <returns>true:入力可|false:入力不可</returns>
		static const bool GetIsFadeDone() { return mousestatus->m_IsInput_Fade; }

		/// <summary>
		/// フェード処理語入力を受け付ける状態かセット
		/// </summary>
		/// <param name="status">true:入力可|false:入力不可</param>
		static void SetIsFadeDone(const bool status) { mousestatus->m_IsInput_Fade = status; }

		/// <summary>
		/// メニュー画面中か？
		/// </summary>
		/// <returns>true:メニュー画面|false:通常画面</returns>
		static bool GetIsMenuMode() { return mousestatus->m_IsInput_Menu; }

		/// <summary>
		/// メニュー画面中かセット
		/// </summary>
		/// <param name="status">true:メニュー画面|false:通常画面</param>
		static void SetIsMenuMode(const bool status) { mousestatus->m_IsInput_Menu = status; }

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		MouseStatus();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObject();

		bool m_IsInput_Fade;		//入力受け付けできるか_フェード状態
		bool m_IsInput_Menu;		//入力受け付けできるか_メニュー状態

		static std::unique_ptr<class MouseStatus> mousestatus;//自身の実態
	};
}

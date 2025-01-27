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
		/// 入力を受け付ける状態か取得
		/// </summary>
		/// <returns>true:入力可|false:入力不可</returns>
		static const bool GetIsFadeDone() { return mousestatus->m_IsInput; }

		/// <summary>
		/// 入力を受け付ける状態かセット
		/// </summary>
		/// <param name="status">true:入力可|false:入力不可</param>
		static void SetIsFadeDone(const bool status) { mousestatus->m_IsInput = status; }

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		MouseStatus();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObject();

		bool m_IsInput;		//入力受け付けできるか

		static std::unique_ptr<class MouseStatus> mousestatus;//自身の実態
	};
}

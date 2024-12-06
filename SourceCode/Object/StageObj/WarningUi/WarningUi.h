#pragma once

namespace object
{
	/// <summary>
	/// 警告Ui関連
	/// </summary>
	class WarningUi final
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		WarningUi();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~WarningUi();

		/// <summary>
		/// 画像の表示
		/// </summary>
		void DrawUi();

		/// <summary>
		/// 警告状態の取得
		/// </summary>
		/// <returns>true:警告|false:警告不可</returns>
		const bool GetIsWarning() const{ return m_IsWarning; }

		/// <summary>
		/// 警告状態のセット
		/// </summary>
		/// <param name="status">true:警告|false:警告不可</param>
		void SetIsWarning(const bool status) {m_IsWarning= status; }

		/// <summary>
		/// 画像を点滅状態にするか
		/// </summary>
		/// <param name="status">true:点滅|false:点滅させない</param>
		void SetIsBlinking(const bool status) { m_IsBlinking = status;}

	private:

		/// <summary>
		/// 読み込み
		/// </summary>
		void LoadUi();

		const int m_PWRIOD = 20;	//表示周期
		const int m_NUMTIMES = 10;	//表示回数

		POINTS m_UiPos;	//画像座標

		int m_DrawCount;	//表示カウント
		int m_UiHandol;		//画像ハンドル
		bool m_IsWarning;	//警告を出せるか
		bool m_IsBlinking;	//画像を点滅させるか
	};
}
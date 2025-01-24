#pragma once
#include <memory>

namespace object
{
    /// <summary>
    /// タイム状態関連
    /// </summary>
    class TimeStatus final
    {
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// タイム状態を取得
		/// </summary>
		/// <returns>true:タイムオーバー|false:ゲームクリア</returns>
		static bool GetIsTimeOver() { return timestatus->m_IsTimeOver; }

		/// <summary>
		/// タイム状態をセット
		/// </summary>
		/// <param name="status">true:タイムオーバー|false:ゲームクリア</param>
		static void SetIsTimeOver(const bool status) { timestatus->m_IsTimeOver = status; }

		/// <summary>
		/// デストラクタ
		/// </summary>
		~TimeStatus();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		TimeStatus();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObject();

		bool m_IsTimeOver;	//タイムオーバーしたか?

		static std::unique_ptr<TimeStatus> timestatus;	//自身の実態
    };
}
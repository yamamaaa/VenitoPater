#pragma once
#include<memory>

namespace object
{
	/// <summary>
	/// 回避状態関連
	/// </summary>
	class AvoidStatus final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~AvoidStatus();

		/// <summary>
		/// 回避状態を取得
		/// </summary>
		/// <returns>true:回避中|false:回避していない</returns>
		static const bool GetIsAvoid(){ return avoidstatus->m_IsAvoid; }

		/// <summary>
		/// 回避状態をセット
		/// </summary>
		/// <param name="status">true:回避中|false:回避していない</param>
		static void SetIsAvoid(const bool status) { avoidstatus->m_IsAvoid= status; }

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		AvoidStatus();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObjec();

		bool m_IsAvoid ;			//回避行動中か

		static std::unique_ptr<AvoidStatus> avoidstatus;	//自身の実態
	};
}
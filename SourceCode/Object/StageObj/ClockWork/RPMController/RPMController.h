#pragma once
#include <memory>

namespace object
{
	/// <summary>
	/// ゼンマイ回転量関連
	/// </summary>
	class RPMController final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// 回転量Hpの取得
		/// </summary>
		/// <returns>回転量Hp</returns>
		static const float GetRPMHp() { return rpm_controller->m_RPMHp; }

		/// <summary>
		/// 回転量Hpのセット
		/// </summary>
		/// <param name="areanum">セットしたい数値</param>
		static void SetRPMHp(const float rpmhp) { rpm_controller->m_RPMHp = rpmhp; }

		/// <summary>
		/// 回転量HP最大値取得
		/// </summary>
		/// <returns>回転量HP最大値</returns>
		static const float GetRPMHpMax() { return rpm_controller->m_RPMHPMAX; }

		/// <summary>
		/// 回転減分量取得
		/// </summary>
		/// <returns>回転減分量</returns>
		static const float GetRPMDecrement() { return rpm_controller->m_RPM_DECREMENT; }

		/// <summary>
		/// 回転量HPの状態を取得
		/// </summary>
		/// <returns>true:HP0以下|false:HP0以上</returns>
		static const bool GetIsRPMLost() { return rpm_controller->m_IsRPMLost; }

		/// <summary>
		/// 回転量HPの状態をセット
		/// </summary>
		/// <param name="status">true:HP0以下|false:HP0以上</param>
		static void SetIsRPMLost(const bool status) { rpm_controller->m_IsRPMLost = status; }

		/// <summary>
		/// デストラクタ
		/// </summary>
		~RPMController();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		RPMController();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObjec();

		const float m_RPM_DECREMENT = 0.1f;		//回転減分量
		const float m_RPMHPMAX = 500;			//回転量HP最大値

		float m_RPMHp;						   //ゼンマイ回転量HP
		bool m_IsRPMLost;					   //回転量が0になったか

		static std::unique_ptr<RPMController> rpm_controller;	//自身の実態
	};
}
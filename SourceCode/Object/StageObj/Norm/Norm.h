#pragma once
#include <memory>

namespace object
{
	/// <summary>
	/// ノルマ関連
	/// </summary>
	class Norm final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// ノルマ更新
		/// </summary>
		static void UpdateNorm();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Norm();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Norm();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObjec();

		int m_NowNolm;				//現在のノルマ
		const int m_MAXNOLM = 20;	//ノルマ達成値

		static std::unique_ptr<Norm> norm;	//自身の実態
	};

}

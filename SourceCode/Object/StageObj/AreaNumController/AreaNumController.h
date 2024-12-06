#pragma once
#include <memory>

namespace object
{
	/// <summary>
	/// エリアナンバー関連
	/// </summary>
	class AreaNumController final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// 現在のエリア番号を取得
		/// </summary>
		/// <returns>現在のエリア番号</returns>
		static const int GetAreaNum() { return areanum_controller->m_NowAreaNum; }

		/// <summary>
		/// エリア番号をセット
		/// </summary>
		/// <param name="areanum">セットしたい番号</param>
		static void SetAreaNum(const int areanum) { areanum_controller->m_NowAreaNum = areanum; }

		/// <summary>
		/// デストラクタ
		/// </summary>
		~AreaNumController();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		AreaNumController();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObjec();

		int m_NowAreaNum;	//現在のエリア番号

		static std::unique_ptr<AreaNumController> areanum_controller;	//自身の実態
	};
}
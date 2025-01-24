#pragma once
#include <memory>

namespace object
{
	/// <summary>
	/// ノルマ関連
	/// </summary>
	class ItemGetNum final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// アイテムの獲得数更新
		/// </summary>
		/// <param name="israre">true:レアアイテム|false:ノーマルアイテム</param>
		static void UpdateItemNum(bool israre);

		/// <summary>
		/// 獲得したノーマルアイテム数の取得
		/// </summary>
		/// <returns>ノーマルアイテム総数</returns>
		static int GetNowNItem() { return itemgetnum->m_NowGet_NItem; }

		/// <summary>
		/// 獲得したレアアイテム数の取得
		/// </summary>
		/// <returns>レアアイテム総数</returns>
		static int GetNowRItem() { return itemgetnum->m_NowGet_RItem; }

		/// <summary>
		/// ノルマを達成しているか？
		/// </summary>
		/// <returns>true:達成|false:未達成</returns>
		static bool GetIsNolmClear() { return itemgetnum->m_IsNolmClear; }

		/// <summary>
		/// デストラクタ
		/// </summary>
		~ItemGetNum();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		ItemGetNum();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObjec();

		int m_NowGet_NItem;			//現在のノーマルアイテム獲得数
		int m_NowGet_RItem;			//現在のレアアイテム獲得数

		const int m_MAXNOLM = 20;	//ノルマ達成値
		bool m_IsNolmClear;			//ノルマを達成したか？

		static std::unique_ptr<ItemGetNum> itemgetnum;	//自身の実態
	};
}

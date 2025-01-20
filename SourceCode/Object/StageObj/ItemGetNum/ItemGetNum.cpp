#include "ItemGetNum.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
	//実体の中身を空に
	std::unique_ptr<ItemGetNum>ItemGetNum::itemgetnum = nullptr;

	ItemGetNum::ItemGetNum()
	{
		//処理なし
	}

	ItemGetNum::~ItemGetNum()
	{
		//処理なし
	}

	void ItemGetNum::Initialize()
	{
		//実態がなかったら
		if (!itemgetnum)
		{
			//インスタンス生成
			itemgetnum.reset(new ItemGetNum);
		}

		LoadObjec();
	}

	void ItemGetNum::LoadObjec()
	{
		//初期化
		itemgetnum->m_NowGet_NItem = 0;
		itemgetnum->m_NowGet_RItem = 0;
	}

	void ItemGetNum::UpdateItemNum(bool israre)
	{
		static int itemnum;
		static int itemans;

		if (israre)	//レアアイテムか？
		{
			itemnum = itemgetnum->m_NowGet_RItem;	//代入して数の更新
		}
		else
		{
			itemnum = itemgetnum->m_NowGet_NItem;
		}

		itemnum++;

		if (israre)
		{
			itemgetnum->m_NowGet_RItem = itemnum;
		}
		else
		{
			itemgetnum->m_NowGet_NItem = itemnum;
		}

		//アイテムの総数
		itemans = itemgetnum->m_NowGet_RItem + itemgetnum->m_NowGet_NItem;

		//もしノルマ達成したら
		if (itemans <= itemgetnum->m_MAXNOLM)
		{
			//ゲームクリア
			ObjectManager::SetGameState(GameClear);
		}
	}
}



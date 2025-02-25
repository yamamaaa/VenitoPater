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

		//読み込み関連
		LoadObjec();
	}

	void ItemGetNum::LoadObjec()
	{
		//初期化
		itemgetnum->m_NowGet_NItem = 0;
		itemgetnum->m_NowGet_RItem = 0;
		itemgetnum->m_IsNolmClear = false;
	}

	void ItemGetNum::UpdateItemNum(bool israre)
	{
		int itemnum = 0;	//アイテム種類別総数
		int itemans = 0;	//アイテム総数

		//取得したのはレアアイテムか？
		if (israre)
		{
			//代入して総数を増やす
			itemnum = itemgetnum->m_NowGet_RItem;
			itemnum++;
			itemgetnum->m_NowGet_RItem = itemnum;
		}
		else
		{
			itemnum = itemgetnum->m_NowGet_NItem;
			itemnum++;
			itemgetnum->m_NowGet_NItem = itemnum;
		}

		//取得したアイテムの総数
		itemans = itemgetnum->m_NowGet_RItem + itemgetnum->m_NowGet_NItem;

		//もしノルマ達成したら
		if (itemans == itemgetnum->m_MAXNOLM)
		{
			//ゲームクリア
			itemgetnum->m_IsNolmClear = true;
		}
	}
}



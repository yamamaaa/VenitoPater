#include <ctime>

#include "Item.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../AreaNumController/AreaNumController.h"
#include "../ItemGetNum/ItemGetNum.h"

namespace object
{
	Item::Item()
		:MouseBase(global_objecttag.ITEM)
	{
		//読み込み関連
		LoadObject();
	}

	Item::~Item()
	{
		//処理なし
	}

	void Item::LoadObject()
	{
		//全フラグの初期化
		m_IsOccur = false;
		m_IsRareItem = false;
		m_IsSet = false;
		m_IsGet = false;
		m_CanDraw = false;

		m_OccurCount = m_OCCURCOUNT_MAX;

		//クリック可能状態
		m_CanClick = true;

		//ランダム生成の初期化
		srand(static_cast<unsigned int>(time(0)));

		//各アイテムの読み込み
		//jsonファイル完成次第書き換え予定
		m_ItemImg_area0[0] = LoadGraph("../Asset/image/item/area0/duck_0.png");
		m_ItemImg_area0[1] = LoadGraph("../Asset/image/item/area0/duck_1.png");
		m_ItemImg_area0[2] = LoadGraph("../Asset/image/item/area0/duck_2.png");
		m_ItemImg_area0[3] = LoadGraph("../Asset/image/item/area0/duck_3.png");
		m_ItemImg_area0[4] = LoadGraph("../Asset/image/item/area0/duck_4.png");

		m_ItemImg_area1[0] = LoadGraph("../Asset/image/item/area1/duck_0.png");
		m_ItemImg_area1[1] = LoadGraph("../Asset/image/item/area1/duck_1.png");
		m_ItemImg_area1[2] = LoadGraph("../Asset/image/item/area1/duck_2.png");
		m_ItemImg_area1[3] = LoadGraph("../Asset/image/item/area1/duck_3.png");
		m_ItemImg_area1[4] = LoadGraph("../Asset/image/item/area1/duck_4.png");

		m_ItemImg_area2[0] = LoadGraph("../Asset/image/item/area2/duck_0.png");
		m_ItemImg_area2[1] = LoadGraph("../Asset/image/item/area2/duck_1.png");
		m_ItemImg_area2[2] = LoadGraph("../Asset/image/item/area2/duck_2.png");
		m_ItemImg_area2[3] = LoadGraph("../Asset/image/item/area2/duck_3.png");
		m_ItemImg_area2[4] = LoadGraph("../Asset/image/item/area2/duck_4.png");

		m_ItemImg_area0[5] = LoadGraph("../Asset/image/item/area0/nekoinu.png");
		m_ItemImg_area1[5] = LoadGraph("../Asset/image/item/area1/nekoinu.png");
		m_ItemImg_area2[5] = LoadGraph("../Asset/image/item/area2/nekoinu.png");
	}

	void Item::UpdateObj(const float deltatime)
	{
#ifdef DEBUG
		//スペースキーでノルマ達成
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			//アイテム数の更新
			ItemGetNum::UpdateItemNum(false);
		}
#endif // DEBUG

		//アイテムが出現し表示されているとき
		if (m_IsOccur && m_CanDraw)
		{
			//マウスとの当たり判定
			CursorHit();
			CanClick();

			//アイテムをクリックしたら
			if (GetStateClick() && GetCursorHit())
			{
				m_IsGet = true;
				m_IsOccur = false;

				//アイテム数の更新
				ItemGetNum::UpdateItemNum(m_IsRareItem);
			}
		}

		//アイテムのセットアップ
		if (m_IsSet == false)
		{
			ItemNumSet();
			m_IsSet = true;
			m_IsOccur = true;
			ScreenFlip();
		}

		//アイテムをゲットしたら
		if (m_IsGet)
		{
			m_OccurCount -= m_COUNT_DECREMENT;
			if (m_OccurCount <= 0.0f)
			{
				m_IsSet = false;
				m_IsGet = false;
				m_OccurCount = m_OCCURCOUNT_MAX;

				if (m_IsRareItem)	//レアアイテムだったら初期化
					m_IsRareItem = false;
			}
		}

		//表示アイテムの更新
		DrawItemSet();

		//現在のエリア番号を取得
		int infodata = AreaNumController::GetAreaNum();

		//アイテムの表示ができるか
		if (infodata == m_DrawItemArea)
		{
			m_CanDraw = true;
		}
		else
		{
			m_CanDraw = false;
		}
	}

	void Item::DrawObj()
	{
		//アイテムが出現し表示されているとき
		if (m_IsOccur && m_CanDraw)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
#ifdef DEBUG
			DrawBox(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), static_cast<int>(m_ObjPos.x) + m_ObjSize.x, static_cast<int>(m_ObjPos.y) + m_ObjSize.y, GetColor(255, 40, 0), FALSE);
#endif
		}
#ifdef DEBUG
		DrawFormatString(0, 260, GetColor(255, 255, 255), "アイテム表示エリア:%d", m_DrawItemArea);
		DrawFormatString(0, 280, GetColor(255, 255, 255), "アイテム番号:%d", m_NowItemNumber);
		DrawFormatString(0, 300, GetColor(255, 255, 255), "アイテム再表示まで:%f", m_OccurCount);
		DrawFormatString(0, 340, GetColor(255, 0, 0), "スペース長押しでノルマ達成");
#endif
	}

	void Item::ItemNumSet()
	{
		//アイテムの出現設定
		int range = 100;
		int itemnum = rand() % range;

		//レアアイテムだったら
		if (itemnum <= m_RARECHANCA)
		{
			//現在のアイテム番号をレアアイテムに
			m_NowItemNumber = m_RAREITEM_INDEX;
			m_IsRareItem = true;
		}
		else
		{
			//出現するアイテムの番号をセット
			int range = m_TOTAlITEM_NUM;
			m_NowItemNumber = rand() % range;	//ランダム生成
		}

		//出現させるエリアのセット
		m_DrawItemArea = rand() % m_ITEMOCCUR_AREA;
	}

	void Item::DrawItemSet()
	{
		//表示エリアでセットするアイテムの分岐
		switch (m_DrawItemArea)
		{
		case 0:
			m_NowDrawItem_Data = m_HitSize_area0;				//あたり判定のデータ
			m_NowDrawItem = m_ItemImg_area0[m_NowItemNumber];	//表示するアイテム
			m_ObjPos.x = m_ItemPos_area0[m_NowItemNumber].x;	//アイテムの位置
			m_ObjPos.y = m_ItemPos_area0[m_NowItemNumber].y;
			break;
		case 1:
			m_NowDrawItem_Data = m_HitSize_area1;
			m_NowDrawItem = m_ItemImg_area1[m_NowItemNumber];
			m_ObjPos.x = m_ItemPos_area1[m_NowItemNumber].x;
			m_ObjPos.y = m_ItemPos_area1[m_NowItemNumber].y;
			break;
		case 2:
			m_NowDrawItem_Data = m_HitSize_area2;
			m_NowDrawItem = m_ItemImg_area2[m_NowItemNumber];
			m_ObjPos.x = m_ItemPos_area2[m_NowItemNumber].x;
			m_ObjPos.y = m_ItemPos_area2[m_NowItemNumber].y;
			break;
		}

		//アイテムのあたり判定をセット
		m_NowItem_collision = m_NowDrawItem_Data[m_NowItemNumber];
		m_ObjSize.x = static_cast<int>(m_NowItem_collision.x);
		m_ObjSize.y = static_cast<int>(m_NowItem_collision.y);
		m_ObjHandle = m_NowDrawItem;
	}
}
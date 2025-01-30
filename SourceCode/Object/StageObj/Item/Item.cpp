#include <ctime>

#include "Item.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../AreaNumController/AreaNumController.h"
#include "../ItemGetNum/ItemGetNum.h"
#include "../../Time/TimeStatus/TimeStatus.h"
#include "../../CharaObj/Enemy/EnemyManager/EnemyManager.h"
#include "../../../SoundController/SoundController.h"

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

		//出現カウント
		m_OccurCount = 0;

		//クリック可能状態
		m_CanClick = true;

		//ランダム生成の初期化
		srand(static_cast<unsigned int>(time(0)));

		//各アイテムの読み込み
		for (int i = 0; i < 6; i++)
		{
			m_ItemImg_area0[i]= LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->Get_ItemData_Area_0(i).c_str());
			m_ItemImg_area1[i] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->Get_ItemData_Area_1(i).c_str());
			m_ItemImg_area2[i] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->Get_ItemData_Area_2(i).c_str());
		}

		sound_controller::SoundController::AddSoundData("../Asset/sound/play/duck_0.mp3", "duck_0", 200, false);
		sound_controller::SoundController::AddSoundData("../Asset/sound/play/duck_1.mp3", "duck_1", 200, false);
		sound_controller::SoundController::AddSoundData("../Asset/sound/play/duck_2.mp3", "duck_2", 200, false);
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

		//タイムオーバーしていたら
		if (TimeStatus::GetIsTimeOver())
		{
			//もしアイテム出現中ならリセット
			if (m_IsOccur)
			{
				m_IsOccur = false;
			}
			return;
		}

		if (m_IsOccur)
		{
			//状態リセットまでカウント
			CountTime(deltatime);

			//emyが出現中でレアアイテムがあればアイテム削除
			int emy = EnemyManager::GetAppearNumNow();
			if (emy > 0 && m_IsRareItem)
			{
				m_IsOccur = false;
				m_IsSet = false;
				m_IsRareItem = false;
			}
		}

		//アイテムが出現し表示されているとき
		if (m_IsOccur && m_CanDraw)
		{
			//マウスとの当たり判定
			CursorHit();
			CanClick();

			//アイテムをクリックしたら
			if (GetStateClick() && GetCursorHit())
			{
				int range = 3;
				int getse = rand() % range;

				switch (getse)
				{
				case 0:
					sound_controller::SoundController::StartSound("duck_0");
					break;
				case 1:
					sound_controller::SoundController::StartSound("duck_1");
					break;
				case 2:
					sound_controller::SoundController::StartSound("duck_2");
					break;
				}

				//再出現カウントをセット
				m_OccurCount = m_OCCURCOUNT_MAX;

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
			//リセットカウントをセット
			m_OccurCount = m_OCCURCOUNT_RESET;
			ScreenFlip();
		}

		//アイテムをゲットしたら
		if (m_IsGet)
		{
			//再出現までカウント
			CountTime(deltatime);
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

	void Item::CountTime(const float deltatime)
	{
		m_OccurCount -= m_COUNT_DECREMENT* deltatime;
		if (m_OccurCount <= 0.0f)
		{
			m_IsSet = false;
			m_IsGet = false;
			m_IsRareItem = false;
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
		DrawFormatString(0, 300, GetColor(255, 255, 255), "アイテム再表示,出現リセットまで:%f", m_OccurCount);
		DrawString(0, 340, "スペースキーでアイテムゲット",GetColor(255, 0, 0));
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
			//敵が出現していないならレアアイテムセット
			int emy = EnemyManager::GetAppearNumNow();
			if (emy > 0)
			{
				//出現するアイテムの番号をセット
				int range = m_TOTAlITEM_NUM;
				m_NowItemNumber = rand() % range;	//ランダム生成
			}
			else
			{
				//現在のアイテム番号をレアアイテムに
				m_NowItemNumber = m_RAREITEM_INDEX;
				m_IsRareItem = true;
			}
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
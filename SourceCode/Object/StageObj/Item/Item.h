#pragma once
#include <unordered_map>
#include"../../MouseBase/MouseBase.h"

namespace object
{
	/// <summary>
	/// ゲーム内アイテム関連
	/// </summary>
	class Item:public MouseBase
	{
	public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        Item();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Item();

	private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// オブジェクトの更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// オブジェクトの描画
        /// </summary>
        void DrawObj() override;

        /// <summary>
        /// アイテムナンバーをセット
        /// </summary>
        void ItemNumSet();

        /// <summary>
        /// 表示するアイテムをセット
        /// </summary>
        void DrawItemSet();

        const int m_TOTAlITEM_NUM = 5;    //エリア内のアイテム総数
        const int m_ITEMOCCUR_AREA = 3;   //アイテムを表示するエリアの数
        const int m_RARECHANCA = 3;       //レアアイテム出現確率
        const int m_RAREITEM_INDEX = 5;   //レアアイテムの添え字

        int m_NowItemNumber;    //現在のアイテム番号
        int m_DrawItemArea;     //アイテムを表示するエリア
        int m_NowDrawItem;      //画面に表示するアイテム

        POINTS m_NowItem_collision; //現在のアイテムのあたり判定

        //各エリアのアイテム画像
        int m_ItemImg_area0[6]; //左の部屋
        int m_ItemImg_area1[6]; //正面の部屋
        int m_ItemImg_area2[6]; //右の部屋

        bool m_IsOccur;     //アイテムが出現したか
        bool m_IsRareItem ;  //レアアイテムか
        bool m_IsSet ;        //セットアップが完了したか
        bool m_IsGet ;       //アイテムをゲットしたか
        bool m_CanDraw ;    //アイテムを表示できるか

        const float m_OCCURCOUNT_MAX = 500.0f;  //アイテム出現間隔
        const float m_COUNT_DECREMENT = 0.1f;   //カウント減分量
        float m_OccurCount;                     //出現までのカウント

        //現在のアイテムデータ保管用
        std::unordered_map<int, POINTS> m_NowDrawItem_Data;

        //各エリアのアイテムHitサイズ
        //VECTOR.x:横サイズ|VECTOR.y:縦サイズ
        std::unordered_map<int,POINTS> m_HitSize_area0{
            {0,{110,120}},
            {1,{80,80}},
            {2,{50,50}},
            {3,{70,70}},
            {4,{80,80}},
            {5,{200,120}},
        };

        std::unordered_map<int, POINTS> m_HitSize_area1{
            {0,{110,120}},
            {1,{90,100}},
            {2,{140,150}},
            {3,{80,70}},
            {4,{140,110}},
            {5,{130,200}},
        };

        std::unordered_map<int, POINTS> m_HitSize_area2{
            {0,{110,120}},
            {1,{80,60}},
            {2,{120,120}},
            {3,{50,50}},
            {4,{100,80}},
            {5,{130,120}},
        };

        //各アイテムの座標
        std::unordered_map<int, POINTS> m_ItemPos_area0{
            {0,{250,880}},
            {1,{450,546}},
            {2,{805,650}},
            {3,{1000,500}},
            {4,{1240,750}},
            {5,{900,760}},
        };

        std::unordered_map<int, POINTS> m_ItemPos_area1{
           {0,{510,720}},
           {1,{830,890}},
           {2,{1045,890}},
           {3,{1150,760}},
           {4,{1350,333}},
           {5,{850,660}},
        };

        std::unordered_map<int, POINTS> m_ItemPos_area2{
           {0,{520,880}},
           {1,{830,725}},
           {2,{1350,880}},
           {3,{1251,675}},
           {4,{1360,670}},
           {5,{1095,765}},
        };
	};
}
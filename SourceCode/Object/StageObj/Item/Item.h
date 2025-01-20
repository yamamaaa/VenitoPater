#pragma once
#include <unordered_map>
#include"../../MouseBase/MouseBase.h"

namespace object
{
    /// <summary>
    /// ゲーム内アイテム関連
    /// </summary>
    class Item :public MouseBase
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
        bool m_IsRareItem;  //レアアイテムか
        bool m_IsSet;        //セットアップが完了したか
        bool m_IsGet;       //アイテムをゲットしたか
        bool m_CanDraw;    //アイテムを表示できるか

        const float m_OCCURCOUNT_MAX = 300.0f;  //アイテム出現間隔
        const float m_COUNT_DECREMENT = 0.1f;   //カウント減分量
        float m_OccurCount;                     //出現までのカウント

        //現在のアイテムデータ保管用
        std::unordered_map<int, POINTS> m_NowDrawItem_Data;

        //各エリアのアイテムHitサイズ
        //VECTOR.x:横サイズ|VECTOR.y:縦サイズ
        std::unordered_map<int, POINTS> m_HitSize_area0{
            {0,{80,75}},
            {1,{30,40}},
            {2,{70,75}},
            {3,{40,40}},
            {4,{60,60}},
            {5,{50,60}},
        };

        std::unordered_map<int, POINTS> m_HitSize_area1{
            {0,{50,60}},
            {1,{115,120}},
            {2,{80,70}},
            {3,{140,110}},
            {4,{125,53}},
            {5,{150,200}},
        };

        std::unordered_map<int, POINTS> m_HitSize_area2{
            {0,{80,90}},
            {1,{90,100}},
            {2,{60,60}},
            {3,{50,40}},
            {4,{50,60}},
            {5,{130,120}},
        };

        //各アイテムの座標
        std::unordered_map<int, POINTS> m_ItemPos_area0{
            {0,{360,555}},
            {1,{839,811}},
            {2,{1000,500}},
            {3,{1292,766}},
            {4,{1436,256}},
            {5,{991,628}},
        };

        std::unordered_map<int, POINTS> m_ItemPos_area1{
           {0,{1220,855}},
           {1,{500,730}},
           {2,{1150,760}},
           {3,{1350,333}},
           {4,{1500,1025}},
           {5,{850,660}},
        };

        std::unordered_map<int, POINTS> m_ItemPos_area2{
           {0,{100,635}},
           {1,{421,780}},
           {2,{773,837}},
           {3,{1006,903}},
           {4,{1511,883}},
           {5,{1095,765}},
        };
    };
}
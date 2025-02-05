#pragma once
#include <unordered_map>
#include<vector>
#include "../MouseBase/MouseBase.h"
#include "../ObjectManager/ObjectManager.h"

namespace object
{
    /// <summary>
    /// Menu画面関連
    /// </summary>
    class Menu :public MouseBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        Menu();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Menu();

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
        /// クリック判定
        /// </summary>
        bool ClickDetect(POINTFLOAT& objpos, POINTS& objsize);

        /// <summary>
        /// カーソル判定
        /// </summary>
        bool CursorDetect(POINTFLOAT& objpos, POINTS& objsize);

        /// <summary>
        /// メニュー選択後のステータスセット
        /// </summary>
        void GameStatusSet();

        /// <summary>
        /// オブジェクトの描画
        /// </summary>
        void DrawObj() override;

        std::string m_JsonTag[3];  //サウンド用Jsonタグ

        int m_IconImg;      //メニューアイコン画像
        int m_MenuBack_Img; //メニュー背景画像
        int m_SelectImg;    //セレクト画像

        POINTFLOAT m_MenuBack_Pos;          //メニュー背景画像位置

        POINTFLOAT m_SelectPos_Offset;    //セレクト画像位置_ずらし量

        POINTFLOAT m_IconHitPos;    //アイコン当たり判定位置
        POINTS m_IconHit_Size;      //当たり判定サイズ

        POINTFLOAT m_BackHit_Pos;   //ゲームに戻るボタン当たり位置
        POINTS m_BackHit_Size;      //当たり判定サイズ

        std::vector<POINTFLOAT> m_MenuHit_Pos;  //メニューボタン当たり判定
        POINTS m_MenuHit_Size;      //当たり判定サイズ

        int m_HitIndex;     //当たったメニュー
        bool m_IsMenuMode;  //メニューアイコンが押されたか
    };
}


#pragma once
#include <unordered_map>
#include<vector>
#include "../MouseBase/MouseBase.h"
#include "../ObjectManager/ObjectManager.h"

namespace object
{
    /// <summary>
    /// Tutorial画面関連
    /// </summary>
    class TutorialUi :public MouseBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        TutorialUi();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~TutorialUi();

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

        std::string m_JsonTag[3];  //サウンド用Jsonタグ

        std::vector<int> m_Tutorial_Img;   //チュートリアル画像

        int m_MenuImg;      //メニュー画像
        int m_SelectImg;    //セレクト画像
        int m_BackImg;      //戻るボタン画像

        const int m_SelectImg_Color = 170;  //セレクト画像透明度

        POINTFLOAT m_SelectPos;    //セレクト画像位置

        POINTFLOAT m_BackHit_Pos;   //タイトルに戻るボタン当たり位置
        POINTS m_BackHit_Size;  //当たり判定サイズ

        std::vector<POINTFLOAT> m_MenuHit_Pos;  //メニューボタン当たり判定
        POINTS m_MenuHit_Size;  //当たり判定サイズ

        int m_HitIndex;     //当たったメニュー
    };
}

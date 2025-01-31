#pragma once
#include"../../../MouseBase/MouseBase.h"

namespace object
{
    /// <summary>
    /// 天井エリアのゼンマイ関連
    /// </summary>
    class ClockWork :public MouseBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        ClockWork();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~ClockWork();

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
        /// 移動処理
        /// </summary>
        void MoveObj(const float deltatime) override;

        /// <summary>
        /// マウス関連との当たり判定
        /// </summary>
        void CheckHitMouse();

        /// <summary>
        /// オブジェクトの描画
        /// </summary>
        void DrawObj() override;

        const float m_RPMHP_COUNTSPEED = 24.0f;     //Hp増量スピード
        static const int m_AnimPattern = 4;         // アニメーションのパターン数
        const int m_AnimType = 1;                   // アニメーションの種類

        int m_Handle[m_AnimPattern];                //画像ハンドル

        const float m_ANIMTIMER_MAX = 1.0f;            // アニメーションタイマー最大値
        float m_AnimTimer;                             // アニメーションタイマー
        int m_AnimNowPattern;                          // 現在のアニメパターン
        int m_AnimNowIndex;                            // アニメーション画像配列の添え字

        const float m_CLICK_FPS = 4.2f;              // クリック状態時FPS
        const float m_DEFAULT_FPS = 3.0f;           // デフォルトFPS
        float m_AnimationFPS;                       // アニメーションFPS

        static const int m_colwidth = 160;        //横サイズ
        static const int m_colheight = 180;       //縦サイズ

        bool m_CanDraw = false;              //画像を表示できるか
        bool m_IsClickNow = false;           //クリック中か
        const int m_DrawAreaNum = 3;         //表示できるエリアナンバー

        const float m_EMYRPM_DECREMENT = 150.0f;   //強化モンスターRPM減らし量
    };

}
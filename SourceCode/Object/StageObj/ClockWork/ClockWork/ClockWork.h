#pragma once
#include"../../../MouseBase/MouseBase.h"

namespace object
{
    /// <summary>
    /// 警告Ui
    /// </summary>
    class WarningUi;

	/// <summary>
	/// 天井エリアのゼンマイ関連
	/// </summary>
	class ClockWork:public MouseBase
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

        static const int m_AnimPattern = 4;         // アニメーションのパターン数
        const int m_AnimType = 1;            // アニメーションの種類

        int m_Handle[m_AnimPattern];                //画像ハンドル

        const float m_ANIMTIMER_MAX = 1.0f;            // アニメーションタイマー最大値
        float m_AnimTimer;                             // アニメーションタイマー
        int m_AnimNowPattern;                          // 現在のアニメパターン
        int m_AnimNowIndex;                            // アニメーション画像配列の添え字

        const float m_CLICK_FPS = 8.0;              // クリック状態時FPS
        const float m_DEFAULT_FPS = 6.0f;           // デフォルトFPS
        float m_AnimationFPS = m_DEFAULT_FPS;       // アニメーションFPS

        static const int m_colwidth = 160;        //横サイズ
        static const int m_colheight = 180;       //縦サイズ

        bool m_CanDraw = false;              //画像を表示できるか
        bool m_CanDrawHP = false;            //HPを表示できるか
        bool m_IsClickNow = false;           //クリック中か
        const int m_DrawAreaNum = 3;         //表示できるエリアナンバー

        float DrawValue;       //表示用HP

        const float m_WARNING_VALUE = 200.0f;    //警告を出すHPの残量値

        POINTS m_HPDrawPos;       //回転量Hpバー表示位置

        POINTS m_FillBoxSize;     //回転量HP残量表示サイズ
        POINTS m_LineBoxSize;     //HPバーの囲いサイズ

        VECTOR m_FillBox_Collar;    //カラーコード
        VECTOR m_LineBox_Collar;

        WarningUi* warningui;     //警告Uiインスタンス
	};

}
#pragma once
#include<Dxlib.h>
#include <memory>

namespace object
{
    /// <summary>
    /// ゲーム内日数関連
    /// </summary>
    class NumDays final
    {
    public:

        /// <summary>
        /// 初期化
        /// </summary>
        static void Initialize();

        /// <summary>
        /// 現在の日数を取得
        /// </summary>
        /// <returns>現在の日数</returns>
        static int GetNumDays() { return numdays->m_NumDays; }

        /// <summary>
        /// 日数を増やす
        /// </summary>
        static void UpdateNumDays();

        /// <summary>
        /// 日数の表示
        /// </summary>
        static void DrawNumDays();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~NumDays();

    private:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        NumDays();

        /// <summary>
        /// 読み込み関連
        /// </summary>
        static void LoadObject();

        static const int m_DROPSPEED = 15;		    	    //減分速度
        static const int m_COLLARCODE = 255;	            //カラーコード
        static const int m_FONTSIZE = 160;                  //フォントサイズ
        const float m_COUNTSPEED = 0.1f;              //タイムカウントスピード
        const float m_COUNTMAX = 100.0f;             //カウント最大値

        POINTFLOAT m_ObjPos;            //文字表示位置

        int m_NumDays;                  //ゲーム内日数
        int m_Collar;                   //文字透明度
        float m_DrawCount;              //文字の透過を開始するまで

        bool m_IsFadeDone;				//処理が終わったか

        static std::unique_ptr<NumDays> numdays;	//自身の実態
    };
}
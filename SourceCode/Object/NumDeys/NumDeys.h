#pragma once
#include <memory>

namespace object
{
    class NumDeys final
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
        static int GetNumDeys() { return numdeys->m_NumDeys; }

        /// <summary>
        /// 日数を増やす
        /// </summary>
        static void UpdateNumDeys();

        /// <summary>
        /// 日数の表示
        /// </summary>
        static void DrawNumDeys();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~NumDeys();

    private:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        NumDeys();

        /// <summary>
        /// 読み込み関連
        /// </summary>
        static void LoadObject();

        static const int m_DROPSPEED = 15;		    	    //減分速度
        static const int m_COLLARCODE = 255;	            //カラーコード

        int m_NumDeys;                  //ゲーム内日数
        int m_Collar = 255;
        float m_DrawCount = 0.0f;

        bool m_IsFadeDone;				//処理が終わったか

        static std::unique_ptr<NumDeys> numdeys;	//自身の実態
    };
}
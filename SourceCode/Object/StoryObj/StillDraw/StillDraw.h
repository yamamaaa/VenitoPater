#pragma once
#include <vector>
#include <fstream>
#include"../../ObjectBase/ObjectBase.h"

namespace object
{
    //Still関連
    class StillDraw:public ObjectBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        StillDraw();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~StillDraw();

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// 更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// 表示状態の更新
        /// </summary>
        void UpdateDrawStatus();

        /// <summary>
        /// 描画
        /// </summary>
        void DrawObj()override;

        /// <summary>
        /// フェード処理
        /// </summary>
        void FadeObj();

        std::ifstream m_TxtFile;    //読み込まれたファイル
        std::string m_Line;         //ファイルから取得した文字

        const std::string m_END = "null";           //ファイル末端コード
        const std::string m_NEXT = "n";             //画像変更なし
        const std::string m_BLACKOUT = "black";     //画像表示なし
        const std::string m_STILLDRAW = "still";    //Still画像表示

        bool IsBlackOut = false;    //画像を非表示にするか

        const float m_FADESPEED = 1.0f; //フェード速度
        const int m_COLLARCODE = 255;	//カラーコード

        float m_Collar;       //画像透明度
        float m_Calculation;  //透明度変動分

        bool m_IsFadeIn_Done; //フェードインがおわったか
        bool m_IsFade ;       //フェードが終わったか

        std::vector<int> m_ObjImg;  //スチル画像
        int m_Index;                //スチル画像インデックス
    };
}
#pragma once
#include <vector>
#include <fstream>
#include"../../ObjectBase/ObjectBase.h"
#include"CharaItem_Tag.h"

namespace object
{
    class StoryItem :public ObjectBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        StoryItem();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~StoryItem();

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

        int m_BackFade;     //背景画像

        const std::string m_END = "null";           //ファイル末端コード
        const std::string m_NEXT = "n";             //画像変更なし
        const std::string m_BLACKOUT = "black";     //画像表示なし

        bool m_IsDrawObj;    //画像を表示するか

        const float m_FADESPEED = 1.5f; //フェード速度
        const int m_COLORCODE = 255;	//カラーコード

        float m_Color;       //画像透明度
        float m_Calculation;  //透明度変動分

        bool m_IsFade;              //フェードが終わったか
        bool m_IsReleaseObj;        //処理を終わるか

        std::unordered_map<std::string, int> m_ObjImg;  //画像データ

        //画像位置
        std::unordered_map<std::string, POINTFLOAT> m_ImgPos{
            {charaItem_Tag.DUCK,{830,270}},
            {charaItem_Tag.GUARD_SET,{ 520,330}},
            {charaItem_Tag.MEDICINE,{ 860,360}},
        };
    };
}


#pragma once
#include <fstream>
#include <unordered_map>
#include"../../ObjectBase/ObjectBase.h"
#include"CharaStatus.h"

namespace object
{
    class Character:public ObjectBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        Character();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Character();

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// 更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override ;

        /// <summary>
        /// 表示状態の更新
        /// </summary>
        void UpdateDrawStatus();

        /// <summary>
        /// フェード処理
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void FadeObj(const float deltatime);

        /// <summary>
        /// 描画
        /// </summary>
        void DrawObj()override ;

        std::ifstream m_TxtFile;//読み込まれたファイル
        std::string m_Status;   //キャラクター状態

        //キャラクター画像
        std::unordered_map<std::string, int> m_Objimg{};

        //画像位置
        std::unordered_map<std::string, POINTFLOAT> m_ImgPos{
            {charaStatus.NORMAL,{790,57}},
            {charaStatus.WORRY,{ 670,94}},
            {charaStatus.DISMAYER,{ 710,71}},
            {charaStatus.HAPPY,{585,33}},
            {charaStatus.SURPRISE,{690,95}},
        };
    };
}
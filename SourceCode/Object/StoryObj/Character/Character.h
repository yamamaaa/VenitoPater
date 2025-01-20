#pragma once
#include <fstream>
#include <unordered_map>
#include"../../ObjectBase/ObjectBase.h"

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
        /// 描画
        /// </summary>
        void DrawObj()override ;

        std::ifstream m_TxtFile;//読み込まれたファイル
        std::string m_Status;   //キャラクター状態

        //キャラクター画像
        std::unordered_map<std::string, int> m_Objimg{};
    };
}
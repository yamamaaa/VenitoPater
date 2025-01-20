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
        /// 描画
        /// </summary>
        void DrawObj()override;

        std::ifstream m_TxtFile;    //読み込まれたファイル

        std::vector<int> m_ObjImg;  //スチル画像
        int m_Index;                //スチル画像インデックス
    };
}
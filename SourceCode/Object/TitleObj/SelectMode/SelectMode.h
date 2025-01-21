#pragma once
#include <unordered_map>
#include "../../MouseBase/MouseBase.h"
#include "PlayMenu.h"

namespace object
{
	/// <summary>
	/// Title画面でのmode選択関連
	/// </summary>
	class SelectMode :public MouseBase
	{
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        SelectMode();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~SelectMode();

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

        int m_SelectIndex;        //インデックス

        int m_MenuHandol;         //メニュー画像ハンドル
        POINTFLOAT m_MenuPos;     //メニュー画像位置
        POINTFLOAT m_SelectPos;   //セレクト画像位置

        //TitleMenuのカーソルHit位置
        std::unordered_map<int, POINTFLOAT> m_HitPos{
            {PlayMenu::PlayTutorial,{650.0f,450.0f}},
            {PlayMenu::PlayNewGame,{650.0f,570.0f}},
            {PlayMenu::PlayRankingMode,{650.0f,690.0f}},
        };

        //TitleMenuのselectUi位置
        std::unordered_map<int, POINTFLOAT> m_SelectMenuPos{
            {PlayMenu::PlayTutorial,{537.0f,437.0f}},
            {PlayMenu::PlayNewGame,{537.0f,550.0f}},
            {PlayMenu::PlayRankingMode,{537.0f,670.0f}},
        };
	};
}
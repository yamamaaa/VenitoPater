#pragma once
#include <string>
#include <memory>
#include <unordered_map>

namespace level_controller
{
    /// <summary>
    /// 難易度関係
    /// </summary>
    class LevelController final
    {
    public:

        /// <summary>
        /// インスタンス生成
        /// </summary>
        static void Initialize();

        /// <summary>
        /// 難易度のセット
        /// </summary>
        /// <param name="select_level">難易度</param>
        static void SetLevel(const std::string select_level) { levelcontroller->m_NowLevel = select_level; }

        /// <summary>
        /// 難易度の取得
        /// </summary>
        /// <returns>設定された難易度</returns>
        static const std::string GetLevel(){ return levelcontroller->m_NowLevel; }

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~LevelController();

    private:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        LevelController();

        std::string m_NowLevel;    //実際にセットするレベル

        static std::unique_ptr<LevelController> levelcontroller;    //自身の実態
    };
}



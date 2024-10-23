#include<DxLib.h>
#include<memory>

namespace GameSystem
{
    class Window;
    class GameSetting;

    /// <summary>
    /// ゲーム全体の進行管理クラス
    /// </summary>
    class GameManager final
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        GameManager();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~GameManager();

        /// <summary>
        /// 後処理
        /// </summary>
        void Finalize();

    private:

        Window* window;
        GameSetting* gamesetting;

        //シーンマネージャー
        std::unique_ptr<class SceneManager> sceneManager;
    };
}
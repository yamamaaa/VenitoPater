#pragma once
#include<memory>
#include<stack>

//using namespace Fps;

/// <summary>
/// タイム関連
/// </summary>
namespace fps
{
	class Fps;
}

namespace scene
{
	/// <summary>
	/// シーン管理
	/// </summary>
	class SceneManager final
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		SceneManager();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~SceneManager();

		/// <summary>
		/// ゲームループ
		/// </summary>
		void GameLoop();

		/// <summary>
		/// シーン更新処理
		/// </summary>
		void UpdateScene();

		/// <summary>
		/// シーン描画処理
		/// </summary>
		void DrawScene();

		/// <summary>
		/// シーン切り替え処理
		/// </summary>
		void ChangeScene();

	private:

		std::shared_ptr<class fps::Fps> fps;						//タイムマネージャー

		std::stack<std::shared_ptr<class SceneBase>> m_NowScene;	//現在のシーン
		SceneBase* m_HoldScene;										//次のシーン
	};

}



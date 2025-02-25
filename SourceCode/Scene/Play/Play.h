#pragma once
#include<string>
#include"../SceneBase/SceneBase.h"

namespace scene
{
	/// <summary>
	/// ゲーム中の進行管理クラス
	/// </summary>
	class Play:public SceneBase
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Play();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Play();

	private:

		/// <summary>
		/// オブジェクト読み込み関連
		/// </summary>
		void LoadObject()override;

		/// <summary>
		/// シーン更新処理
		/// </summary>
		/// <param name="deltaTime">デルタタイム</param>
		/// <returns>次のフレームシーン</returns>
		SceneBase* UpdateScene(const float deltaTime)override;

		/// <summary>
		/// シーン更新処理
		/// </summary>
		void DrawScene()override;
	};
}
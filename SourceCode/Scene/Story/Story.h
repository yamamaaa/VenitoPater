#pragma once
#include"../SceneBase/SceneBase.h"

namespace scene
{
	class Story :public SceneBase
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Story();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Story();

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
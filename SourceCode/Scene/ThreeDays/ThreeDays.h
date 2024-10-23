#pragma once
#include"../SceneBase/SceneBase.h"

namespace scene
{
	/// <summary>
	/// 3Daysモードの進行管理クラス
	/// </summary>
	class ThreeDays:public SceneBase
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		ThreeDays();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~ThreeDays();

	private:

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
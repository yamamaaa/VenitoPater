#pragma once
#include"../EnemyBase/EnemyBase.h"

namespace object
{
	/// <summary>
	/// Enemy_Familia関連
	/// </summary>
	class Familia:public EnemyBase
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Familia();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Familia();

	private:

		/// <summary>
		/// 読み込み関連
		/// </summary>
		void LoadObject() override;

		/// <summary>
		/// 更新
		/// </summary>
		/// <param name="deltatime"></param>
		void UpdateObj(const float deltatime) override;

		/// <summary>
		/// 描画
		/// </summary>
		void DrawObj()override;

		/// <summary>
		/// 移動処理
		/// </summary>
		void MoveObj(const float deltatime)override;
	};
}
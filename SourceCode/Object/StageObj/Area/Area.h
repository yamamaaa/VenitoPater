#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// エリア関連
	/// </summary>
	class Area :public ObjectBase
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Area();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Area();

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

		int m_AreaImg[4];       //各エリアの画像
	};
}
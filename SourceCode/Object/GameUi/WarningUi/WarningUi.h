#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// 警告Ui関連
	/// </summary>
	class WarningUi :public ObjectBase
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		WarningUi();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~WarningUi();

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

		const int m_Hide_DrawArea = 3;			 //Uiを表示できないエリア
		const float m_WARNING_VALUE = 100.0f;    //警告を出すHPの残量値

		const int m_PWRIOD = 20;	//表示周期
		const int m_NUMTIMES = 10;	//表示回数

		int m_DrawCount;	//表示カウント
		bool m_CanDraw;		//Uiを表示できるか
		bool m_IsBlinking;	//画像を点滅させるか
	};
}
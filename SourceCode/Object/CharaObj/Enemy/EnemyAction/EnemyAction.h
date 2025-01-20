#pragma once
#include "../../../ObjectBase/ObjectBase.h"

namespace object
{
	class EnemyAction :public ObjectBase
	{
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        EnemyAction();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~EnemyAction();

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

        int m_EmyActionImg[4];
	};
}
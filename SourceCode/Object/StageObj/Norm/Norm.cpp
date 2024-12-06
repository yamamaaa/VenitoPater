#include "Norm.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
	//実体の中身を空に
	std::unique_ptr<Norm>Norm::norm = nullptr;

	Norm::Norm()
	{
		//処理なし
	}

	Norm::~Norm()
	{
		//処理なし
	}

	void Norm::Initialize()
	{
		//実態がなかったら
		if (!norm)
		{
			//インスタンス生成
			norm.reset(new Norm);
		}

		LoadObjec();
	}

	void Norm::LoadObjec()
	{
		//ノルマ初期化
		norm->m_NowNolm = 0;
	}

	void Norm::UpdateNorm()
	{
		norm->m_NowNolm++;

		//もしノルマ達成したら
		if (norm->m_NowNolm == norm->m_MAXNOLM)
		{
			//ゲームクリア
			ObjectManager::SetGameState(GameClear);
		}
	}
}



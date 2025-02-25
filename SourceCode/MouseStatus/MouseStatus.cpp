#include "MouseStatus.h"

namespace mousestatus
{
	std::unique_ptr<MouseStatus>MouseStatus::mousestatus = nullptr;

	MouseStatus::MouseStatus()
	{
		//処理なし
	}

	MouseStatus::~MouseStatus()
	{
		//処理なし
	}

	void MouseStatus::Initialize()
	{
		//実態が空ならインスタンス生成
		if (!mousestatus)
		{
			mousestatus.reset(new MouseStatus);
		}

		//読み込み関連
		LoadObject();
	}

	void MouseStatus::LoadObject()
	{
		//初期化
		mousestatus->m_IsInput_Fade = false;
		mousestatus->m_IsInput_Menu = false;
	}
}
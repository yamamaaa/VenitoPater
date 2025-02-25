#include "AvoidStatus.h"

namespace object
{
	//実態を空に
	std::unique_ptr<AvoidStatus>AvoidStatus::avoidstatus = nullptr;

	AvoidStatus::AvoidStatus()
	{
		//処理なし
	}

	AvoidStatus::~AvoidStatus()
	{
		//処理なし
	}

	void AvoidStatus::Initialize()
	{
		//もし実体がなかったらインスタンス生成
		if (!avoidstatus)
		{
			avoidstatus.reset(new AvoidStatus);
		}

		LoadObjec();
	}

	void AvoidStatus::LoadObjec()
	{
		avoidstatus->m_IsAvoid = false;
	}

	void AvoidStatus::Processing()
	{
		avoidstatus.reset();
	}
}
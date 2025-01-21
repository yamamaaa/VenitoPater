#include "LineStatus.h"

namespace object
{
	std::unique_ptr<LineStatus>LineStatus::linestatus = nullptr;

	LineStatus::LineStatus()
	{
		//処理なし
	}

	LineStatus::~LineStatus()
	{
		//処理なし
	}

	void LineStatus::Initialize()
	{
		//実態が空ならインスタンス生成
		if (!linestatus)
		{
			linestatus.reset(new LineStatus);
		}

		LoadObject();
	}

	void LineStatus::LoadObject()
	{
		linestatus->m_IsDoneAnim = false;
	}
}
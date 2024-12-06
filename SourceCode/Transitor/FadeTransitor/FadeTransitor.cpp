#include <Dxlib.h>
#include "FadeTransitor.h"

namespace transitor
{
	FadeTransitor::FadeTransitor()
	{
		//読み込み関連
		LoadObject();
	}

	FadeTransitor::~FadeTransitor()
	{
		//処理無し
	}

	void FadeTransitor::WaitTimerStart()
	{
		if (!m_WaitDone)
		{
			m_WaitCount += 1.0f;

			if (m_WaitCount >= 50.0f)
			{
				m_WaitDone = true;
			}
		}
	}

	void FadeTransitor::LoadObject()
	{
		m_DropCollar = m_COLLARCODE;	//カラーコード減分初期値
		m_IsFadeDone = false;			//終了ステータス初期値
		m_WaitDone = false;				//待機状態初期化
		m_WaitCount = 0.0f;
	}

	void FadeTransitor::FadeOutStart(bool wait)
	{
		static int drop;
		static bool iswait = wait;

		if (iswait)
		{
			WaitTimerStart();
		}
		else
		{
			m_WaitDone = true;
		}

		if (m_WaitDone)
		{
			//だんだん画面を暗くする
			SetDrawBright(m_DropCollar, m_DropCollar, m_DropCollar);
			m_DropCollar -= drop;
			drop += m_DROPSPEED;

			if (m_DropCollar <= 0)
			{
				m_IsFadeDone = true;	//処理の完了
				m_WaitDone = false;		//待機状態初期化
			}
		}
	}
}
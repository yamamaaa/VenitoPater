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

	void FadeTransitor::WaitTime()
	{
		if (!m_WaitDone)
		{
			m_WaitCount -= m_COUNT_DECREMENT;

			if (m_WaitCount == 0)
			{
				m_WaitDone = true;
				m_WaitCount = m_WAITMAX;
			}
		}
	}

	void FadeTransitor::LoadObject()
	{
		m_DropCollar = m_COLLARCODE;	//カラーコード減分初期値
		m_IsFadeDone = false;			//終了ステータス初期値
		m_WaitDone = false;				//待機状態初期化
		m_WaitCount = m_WAITMAX;		//待ち時間カウント初期化
	}

	void FadeTransitor::FadeOutStart(bool wait)
	{
		static int drop;

		//スタートを遅らせるか
		if (wait)
		{
			WaitTime();	//遅らせるならカウント
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

	void FadeTransitor::FadeInStart(bool wait)
	{
		static int drop;

		//スタートを遅らせるか
		if (wait)
		{
			WaitTime();		//遅らせるならカウント
		}
		else
		{
			m_WaitDone = true;
		}

		if (m_WaitDone)
		{
			//だんだん画面を明るく
			SetDrawBright(m_DropCollar, m_DropCollar, m_DropCollar);
			m_DropCollar += drop;
			drop -= m_DROPSPEED;

			if (m_DropCollar == m_COLLARCODE)
			{
				m_IsFadeDone = true;	//処理の完了
				m_WaitDone = false;		//待機状態初期化
			}
		}
	}
}
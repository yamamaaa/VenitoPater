#include "ItemGetNum.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
	//���̂̒��g�����
	std::unique_ptr<ItemGetNum>ItemGetNum::itemgetnum = nullptr;

	ItemGetNum::ItemGetNum()
	{
		//�����Ȃ�
	}

	ItemGetNum::~ItemGetNum()
	{
		//�����Ȃ�
	}

	void ItemGetNum::Initialize()
	{
		//���Ԃ��Ȃ�������
		if (!itemgetnum)
		{
			//�C���X�^���X����
			itemgetnum.reset(new ItemGetNum);
		}

		LoadObjec();
	}

	void ItemGetNum::LoadObjec()
	{
		//������
		itemgetnum->m_NowGet_NItem = 0;
		itemgetnum->m_NowGet_RItem = 0;
	}

	void ItemGetNum::UpdateItemNum(bool israre)
	{
		static int itemnum;
		static int itemans;

		if (israre)	//���A�A�C�e�����H
		{
			itemnum = itemgetnum->m_NowGet_RItem;	//������Đ��̍X�V
		}
		else
		{
			itemnum = itemgetnum->m_NowGet_NItem;
		}

		itemnum++;

		if (israre)
		{
			itemgetnum->m_NowGet_RItem = itemnum;
		}
		else
		{
			itemgetnum->m_NowGet_NItem = itemnum;
		}

		//�A�C�e���̑���
		itemans = itemgetnum->m_NowGet_RItem + itemgetnum->m_NowGet_NItem;

		//�����m���}�B��������
		if (itemans <= itemgetnum->m_MAXNOLM)
		{
			//�Q�[���N���A
			ObjectManager::SetGameState(GameClear);
		}
	}
}



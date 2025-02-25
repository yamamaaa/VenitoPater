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

		//�ǂݍ��݊֘A
		LoadObjec();
	}

	void ItemGetNum::LoadObjec()
	{
		//������
		itemgetnum->m_NowGet_NItem = 0;
		itemgetnum->m_NowGet_RItem = 0;
		itemgetnum->m_IsNolmClear = false;
	}

	void ItemGetNum::UpdateItemNum(bool israre)
	{
		int itemnum = 0;	//�A�C�e����ޕʑ���
		int itemans = 0;	//�A�C�e������

		//�擾�����̂̓��A�A�C�e�����H
		if (israre)
		{
			//������đ����𑝂₷
			itemnum = itemgetnum->m_NowGet_RItem;
			itemnum++;
			itemgetnum->m_NowGet_RItem = itemnum;
		}
		else
		{
			itemnum = itemgetnum->m_NowGet_NItem;
			itemnum++;
			itemgetnum->m_NowGet_NItem = itemnum;
		}

		//�擾�����A�C�e���̑���
		itemans = itemgetnum->m_NowGet_RItem + itemgetnum->m_NowGet_NItem;

		//�����m���}�B��������
		if (itemans == itemgetnum->m_MAXNOLM)
		{
			//�Q�[���N���A
			itemgetnum->m_IsNolmClear = true;
		}
	}
}



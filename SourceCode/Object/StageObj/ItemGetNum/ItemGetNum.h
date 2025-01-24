#pragma once
#include <memory>

namespace object
{
	/// <summary>
	/// �m���}�֘A
	/// </summary>
	class ItemGetNum final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// �A�C�e���̊l�����X�V
		/// </summary>
		/// <param name="israre">true:���A�A�C�e��|false:�m�[�}���A�C�e��</param>
		static void UpdateItemNum(bool israre);

		/// <summary>
		/// �l�������m�[�}���A�C�e�����̎擾
		/// </summary>
		/// <returns>�m�[�}���A�C�e������</returns>
		static int GetNowNItem() { return itemgetnum->m_NowGet_NItem; }

		/// <summary>
		/// �l���������A�A�C�e�����̎擾
		/// </summary>
		/// <returns>���A�A�C�e������</returns>
		static int GetNowRItem() { return itemgetnum->m_NowGet_RItem; }

		/// <summary>
		/// �m���}��B�����Ă��邩�H
		/// </summary>
		/// <returns>true:�B��|false:���B��</returns>
		static bool GetIsNolmClear() { return itemgetnum->m_IsNolmClear; }

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~ItemGetNum();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		ItemGetNum();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObjec();

		int m_NowGet_NItem;			//���݂̃m�[�}���A�C�e���l����
		int m_NowGet_RItem;			//���݂̃��A�A�C�e���l����

		const int m_MAXNOLM = 20;	//�m���}�B���l
		bool m_IsNolmClear;			//�m���}��B���������H

		static std::unique_ptr<ItemGetNum> itemgetnum;	//���g�̎���
	};
}

#include "ItemUi.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../../StageObj/ItemGetNum/ItemGetNum.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
    ItemUi::ItemUi()
        :ObjectBase(global_objecttag.ITEMUI)
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    ItemUi::~ItemUi()
    {
        //�t�H���g�n���h���̉��
        DeleteFontToHandle(m_FontHandle);
    }

    void ItemUi::LoadObject()
    {
        //�I���������[�h�ɂ����W�ύX
        PlayMenu  menu = ObjectManager::GetPlayMode();

        if (menu == PlayMenu::PlayNewGame)
        {
            //���W������
            m_ObjPos = { 320,35 };

            //���̃I�u�W�F�N�g����ɍ��W��ݒ�
            m_RItem_ObjPos = { 70,-5 };
            m_NItemNum_Pos = { 110,5 };
            m_RItem_ObjPos += m_ObjPos;
            m_NItemNum_Pos += m_RItem_ObjPos;
        }
        else if (menu == PlayMenu::PlayRankingMode)
        {
            //���W������
            m_ObjPos = { 320,30 };
            m_RItem_ObjPos = { 210,-5 };

            m_NItemNum_Pos = { 80,5 };
            m_RItemNum_Pos = { 110,10 };

            //���̃I�u�W�F�N�g����ɍ��W��ݒ�
            m_RItem_ObjPos += m_ObjPos;

            m_NItemNum_Pos += m_ObjPos;
            m_RItemNum_Pos += m_RItem_ObjPos;
        }

        //�摜�ǂݍ���
        m_ObjHandle= LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Duck().c_str());
        m_RItem_Handole = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Nekoinu().c_str());

        //�t�H���g�n���h���̐���
        m_FontHandle = CreateFontToHandle("���C���I", m_FONTSIZE.x, m_FONTSIZE.y, DX_FONTTYPE_ANTIALIASING);
    }

    void ItemUi::DrawObj()
    {
        unsigned int cr = GetColor(m_COLOR, m_COLOR, m_COLOR);
        int item_n = ItemGetNum::GetNowNItem();
        int item_r = ItemGetNum::GetNowRItem();

        //�����A�C�e�����\��
        DrawFormatStringFToHandle(m_NItemNum_Pos.x, m_NItemNum_Pos.y, cr, m_FontHandle, m_ItemText.c_str(), item_n);
        DrawFormatStringFToHandle(m_RItemNum_Pos.x, m_RItemNum_Pos.y, cr, m_FontHandle, m_ItemText.c_str(), item_n);

        //�A�C�e���A�C�R���\��
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
        DrawGraph(static_cast<int>(m_RItem_ObjPos.x), static_cast<int>(m_RItem_ObjPos.y), m_RItem_Handole, TRUE);
    }
}
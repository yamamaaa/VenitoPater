#include "ItemUi.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../../StageObj/ItemGetNum/ItemGetNum.h"

namespace object
{
    ItemUi::ItemUi()
        :ObjectBase(global_objecttag.ITEMUI)
    {
        //読み込み関連
        LoadObject();
    }

    ItemUi::~ItemUi()
    {
        //処理なし
    }

    void ItemUi::LoadObject()
    {
        //座標初期化
        m_ObjPos = {320,30};
        m_RItem_ObjPos = { 200,-5 };

        m_NItemNum_Pos = { 70,10 };
        m_RItemNum_Pos = { 100,15 };

        //左のオブジェクトを基準に座標を設定
        m_RItem_ObjPos += m_ObjPos;

        m_NItemNum_Pos += m_ObjPos;
        m_RItemNum_Pos += m_RItem_ObjPos;

        //画像読み込み
        m_ObjHandle= LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Duck().c_str());
        m_RItem_Handole = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Nekoinu().c_str());
    }

    void ItemUi::DrawObj()
    {
        //アイテムゲット数表示
        SetFontSize(m_FONTSIZE);
        DrawFormatString(static_cast<int>(m_NItemNum_Pos.x), static_cast<int>(m_NItemNum_Pos.y), GetColor(m_COLLARCODE, m_COLLARCODE, m_COLLARCODE), "%d", ItemGetNum::GetNowNItem());
        DrawFormatString(static_cast<int>(m_RItemNum_Pos.x), static_cast<int>(m_RItemNum_Pos.y), GetColor(m_COLLARCODE, m_COLLARCODE, m_COLLARCODE), "%d", ItemGetNum::GetNowRItem());
#ifdef DEBUG
        SetFontSize(m_DEBUG_FONTSIZE);
#endif
        //アイテムアイコン表示
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
        DrawGraph(static_cast<int>(m_RItem_ObjPos.x), static_cast<int>(m_RItem_ObjPos.y), m_RItem_Handole, TRUE);
    }
}
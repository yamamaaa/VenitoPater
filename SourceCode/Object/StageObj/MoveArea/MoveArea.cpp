#include "MoveArea.h"
#include "../../ObjectTag/Play_ObjectTag.h"
#include "../../StageObj/AreaNumController/AreaNumController.h"
#include "../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../../MouseStatus/MouseStatus.h"

namespace object
{
    MoveArea::MoveArea()
        :MouseBase(play_ObjectTag.MOVEAREA)
    {
        //読み込み関連
        LoadObject();
    }

    MoveArea::~MoveArea()
    {
        m_HitSize.clear();
        m_MovePos.clear();
        m_AreaNumber.clear();
#ifdef DEBUG
        d_ColorCode.clear();
        d_CursorHit.clear();
#endif // DEBUG
    }

    void MoveArea::LoadObject()
    {
        m_IsMove = false;
        m_CanMove = true;
        m_MoveCount = m_MOVECOUNT_MAX;

        m_MoveUiImg[areaMove_PosTag.UP] = LoadGraph("../Asset/image/gameobj/ui/up.png");
        m_MoveUiImg[areaMove_PosTag.RIGHT] = LoadGraph("../Asset/image/gameobj/ui/right.png");
        m_MoveUiImg[areaMove_PosTag.LEFT] = LoadGraph("../Asset/image/gameobj/ui/left.png");
        m_MoveUiImg[areaMove_PosTag.DOWN] = LoadGraph("../Asset/image/gameobj/ui/down.png");

        m_MoveUiPos[areaMove_PosTag.UP] = { 670.0f,0.0f };
        m_MoveUiPos[areaMove_PosTag.RIGHT] = { 0.0f,300.0f };
        m_MoveUiPos[areaMove_PosTag.LEFT] = { 1770.0f,300.0f };
        m_MoveUiPos[areaMove_PosTag.DOWN] = { 310.0f,920.0f };
    }

    void MoveArea::UpdateObj(const float deltatime)
    {
        //入力状態が不可の時は処理なし
        if (!mousestatus::MouseStatus::GetIsFadeDone())
            return;

        //移動したら
        if (m_IsMove)
        {
            //再び移動できるまでカウント
            m_MoveCount-=m_COUNTSPPED_MOVE* deltatime;
            if (m_MoveCount <= 0.0f)
            {
                m_IsMove = false;
                m_CanMove = true;
                m_MoveCount = m_MOVECOUNT_MAX;
            }
        }

        //回避中はエリア移動不可
        if (AvoidStatus::GetIsAvoid())
            return;

        for (std::string& tag : AreaMove_PosTagAll)
        {
            //エリア移動できる状態か
            if (m_AreaNumber[tag] == true && m_CanMove)
            {
                //マウスがエリア移動の位置にあるか
                m_ObjPos.x = m_MovePos[tag].x;
                m_ObjPos.y = m_MovePos[tag].y;

                m_ObjSize.x = static_cast<int>(m_HitSize[tag].x);
                m_ObjSize.y = static_cast<int>(m_HitSize[tag].y);

                CursorHit();

                //もし移動出来たら
                if (GetCursorHit())
                {
#ifdef DEBUG
                    d_CursorHit[tag] = "Hit";
#endif
                    Update_AreaNumber(tag);
                    CursorHitControl();
                    m_IsMove = true;
                    m_CanMove = false;
                }
#ifdef DEBUG
                else
                {
                    d_CursorHit[tag] = "NoHit";
                }
#endif
            }
        }

        //初期化
        m_ObjPos.x = 0.0f;
        m_ObjPos.y = 0.0f;
    }

    void MoveArea::CursorHitControl()
    {
        //初期化
        for (std::string& tag : AreaMove_PosTagAll)
        {
            m_AreaNumber[tag] = false;
        }

        //表示エリアにより状態変化
        switch (AreaNumController::GetAreaNum())
        {
        case 0:
            m_AreaNumber[areaMove_PosTag.LEFT] = true;
            break;
        case 1:
            m_AreaNumber[areaMove_PosTag.UP] = true;
            m_AreaNumber[areaMove_PosTag.RIGHT] = true;
            m_AreaNumber[areaMove_PosTag.LEFT] = true;
            break;
        case 2:
            m_AreaNumber[areaMove_PosTag.RIGHT] = true;
            break;
        case 3:
            m_AreaNumber[areaMove_PosTag.DOWN] = true;
            break;
        }
    }

    void MoveArea::DrawObj()
    {
        for (std::string& tag : AreaMove_PosTagAll)
        {
            if (m_AreaNumber[tag] == true)
            {
                //Uiの表示
                DrawGraphF(m_MoveUiPos[tag].x, m_MoveUiPos[tag].y, m_MoveUiImg[tag], TRUE);
#ifdef DEBUG
                //HitBoxの表示
                m_ObjPos.x = m_MovePos[tag].x;
                m_ObjPos.y = m_MovePos[tag].y;

                m_ObjSize.x = static_cast<int>(m_HitSize[tag].x);
                m_ObjSize.y = static_cast<int>(m_HitSize[tag].y);

                DrawBox(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), static_cast<int>(m_ObjPos.x) + m_ObjSize.x, static_cast<int>(m_ObjPos.y) + m_ObjSize.y, GetColor(static_cast<int>(d_ColorCode[tag].x), static_cast<int>(d_ColorCode[tag].y), static_cast<int>(d_ColorCode[tag].z)), FALSE);
#endif
            }
        }
#ifdef DEBUG
        DrawFormatString(0, 180, GetColor(255, 255, 255), "上:%s", d_CursorHit[areaMove_PosTag.UP].c_str());
        DrawFormatString(0, 200, GetColor(255, 255, 255), "左:%s", d_CursorHit[areaMove_PosTag.RIGHT].c_str());
        DrawFormatString(0, 220, GetColor(255, 255, 255), "右:%s", d_CursorHit[areaMove_PosTag.LEFT].c_str());
        DrawFormatString(0, 240, GetColor(255, 255, 255), "下:%s", d_CursorHit[areaMove_PosTag.DOWN].c_str());
        DrawFormatString(0, 320, GetColor(255, 255, 255), "表示中エリア:%d", AreaNumController::GetAreaNum());
        DrawFormatString(300, 320, GetColor(255, 255, 255), "エリア移動できるまで:%f", m_MoveCount);
#endif
    }

    void MoveArea::Update_AreaNumber(std::string tagname)
    {
        int tmp = AreaNumController::GetAreaNum();

        //エリア番号の切り替え
        if (tagname == areaMove_PosTag.UP)
        {
            tmp = m_CEILINGAREA_NUM;
        }
        if (tagname == areaMove_PosTag.DOWN)
        {
            tmp = m_FRONTAREA_NUM;
        }
        if (tagname == areaMove_PosTag.LEFT)
        {
            tmp++;
        }
        if (tagname == areaMove_PosTag.RIGHT)
        {
            tmp--;
        }

        //エリア番号の更新
        AreaNumController::SetAreaNum(tmp);
    }
}
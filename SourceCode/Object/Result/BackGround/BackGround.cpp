#include "BackGround.h"
#include "../../ObjectTag/Result_ObjectTag.h"

namespace object
{
    BackGround::BackGround()
        :ObjectBase(result_objecttag.BACKGROUND)
    {
        //“Ç‚İ‚İŠÖ˜A
        LoadObject();
    }

    BackGround::~BackGround()
    {
        //ˆ—‚È‚µ
    }

    void BackGround::LoadObject()
    {
        m_ObjPos = { 0,0 };
        m_ObjHandle= LoadGraph("../Asset/image/result/gameover/background.png");
    }

    void BackGround::DrawObj()
    {
        //‰æ‘œ‚Ì•\¦
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
    }
}
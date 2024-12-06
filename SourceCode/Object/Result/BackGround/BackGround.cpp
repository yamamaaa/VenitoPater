#include "BackGround.h"
#include "../../ObjectTag/Result_ObjectTag.h"

namespace object
{
    BackGround::BackGround()
        :ObjectBase(result_objecttag.BACKGROUND)
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    BackGround::~BackGround()
    {
        //�����Ȃ�
    }

    void BackGround::LoadObject()
    {
        m_ObjPos = { 0,0 };
        m_ObjHandle= LoadGraph("../Asset/image/result/gameover/background.png");
    }

    void BackGround::DrawObj()
    {
        //�摜�̕\��
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
    }
}
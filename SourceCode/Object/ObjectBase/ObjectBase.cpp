#include "ObjectBase.h"
#include"../../Collision/Collision.h"

namespace object
{
    ObjectBase::ObjectBase(std::string tagname)
        :m_ObjTag(tagname),
        m_ObjPos({ 0.0f ,0.0f }),
        m_ObjSize({0,0}),
        m_DrawOffset({ 0,0 }),
        m_Alive(true),
        m_ObjHandle(0),
        m_MoveSpeed(0.0f),
        m_MaxMoveSpeed(0.0f)
    {
        //ˆ—‚È‚µ
    }

    ObjectBase::~ObjectBase()
    {
        //ˆ—‚È‚µ
    }
}

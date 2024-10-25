#include "ObjectBase.h"

namespace object
{
    ObjectBase::ObjectBase(std::string tagname)
        :m_ObjTag(""),
        m_ObjPos(VGet(0,0,0)),
        m_Alive(true),
        m_ObjHandle(0),
        m_ImgSize_Y(0),
        m_ImgSize_X(0),
        m_MoveSpeed(0.0f)
    {
        //ˆ—‚È‚µ
    }

    ObjectBase::~ObjectBase()
    {
        //ˆ—‚È‚µ
    }
}

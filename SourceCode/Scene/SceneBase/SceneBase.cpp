#include"SceneBase.h"

namespace scene
{
    SceneBase::SceneBase()
        :fade_transitor (new transitor::FadeTransitor)
    {
        //�����Ȃ�
    }
    SceneBase::~SceneBase()
    {
        //�������̉��
        delete fade_transitor;
    }
}
#include"SceneBase.h"

namespace scene
{
    SceneBase::SceneBase()
        :fade_transitor (new transitor::FadeTransitor)
    {
        //ˆ—‚È‚µ
    }
    SceneBase::~SceneBase()
    {
        //ƒƒ‚ƒŠ‚Ì‰ğ•ú
        delete fade_transitor;
    }
}
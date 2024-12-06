#include"SceneBase.h"

namespace scene
{
    SceneBase::SceneBase()
        :fade_transitor (new transitor::FadeTransitor)
    {
        //処理なし
    }
    SceneBase::~SceneBase()
    {
        //メモリの解放
        delete fade_transitor;
    }
}
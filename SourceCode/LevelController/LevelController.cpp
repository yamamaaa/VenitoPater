#include "LevelController.h"

namespace level_controller
{
    //実体の中身を空に
    std::unique_ptr<LevelController>LevelController::levelcontroller = nullptr;

    LevelController::LevelController()
    {
        //処理なし
    }

    LevelController::~LevelController()
    {
        //処理なし
    }

    void LevelController::Initialize()
    {
        //実態がなかったら
        if (!levelcontroller)
        {
            //インスタンス生成
            levelcontroller.reset(new LevelController);
        }
    }

}
#include "LevelController.h"

namespace level_controller
{
    //���̂̒��g�����
    std::unique_ptr<LevelController>LevelController::levelcontroller = nullptr;

    LevelController::LevelController()
    {
        //�����Ȃ�
    }

    LevelController::~LevelController()
    {
        //�����Ȃ�
    }

    void LevelController::Initialize()
    {
        //���Ԃ��Ȃ�������
        if (!levelcontroller)
        {
            //�C���X�^���X����
            levelcontroller.reset(new LevelController);
        }
    }

}
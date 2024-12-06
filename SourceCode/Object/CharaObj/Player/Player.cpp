#include "Player.h"
#include"../../../LevelController/LevelController.h"
#include"../../ObjectTag/Global_ObjectTag.h"
#include"../LightController/LightController.h"

using namespace level_controller;

namespace object
{
    Player::Player()
        :MouseBase(global_objecttag.PLAYER)
    {
        LoadObject();
    }
    Player::~Player()
    {
    }

    void Player::LoadObject()
    {
        LightController::Initialize();
#ifdef DEBUG
        select_level =LevelController::GetLevel();
#endif
    }
    void Player::UpdateObj(const float deltatime)
    {
        MoveObj(deltatime);
    }
    void Player::DrawObj()
    {
        LightController::DrawLight();
#ifdef DEBUG
        DrawFormatString(0, 20, GetColor(255, 255, 255), "��Փx:%s", select_level.c_str());
        Debug_DrawObj();
        DrawFormatString(0, 80, GetColor(255, 255, 255), "�}�E�X���{�^��:%s", mouse_click.c_str());
#endif
    }
    void Player::MoveObj(const float deltatime)
    {
#ifdef DEBUG
        m_CanClick = true;
        MouseClick();

        //�}�E�X�̍��{�^����������Ă�����
        if (GetStateClick())
        {
            mouse_click = "input";
        }
        else
        {
            mouse_click = "no";
        }

#endif
    }
}
#include <fstream>

#include "ScoreDraw.h"
#include"../../Object/ObjectTag/GameClear_ObjectTag.h"
#include "../../GameSystem/Window/Window.h"
#include "../StageObj/ItemGetNum/ItemGetNum.h"
#include "../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"
#include"../../MouseStatus/MouseStatus.h"
#include"../../SoundController/SoundController.h"
#include"../ObjectManager/ObjectManager.h"

namespace object
{
    ScoreDraw::ScoreDraw()
        :ObjectBase(gameClear_ObjectTag.SCORE)
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    ScoreDraw::~ScoreDraw()
    {
        //�������̉��
        delete window;
        //�t�H���g�n���h���̍폜
        DeleteFontToHandle(m_FontHandle_Item);
        DeleteFontToHandle(m_FontHandle_Score);
        DeleteGraph(m_ObjHandle);
    }

    void ScoreDraw::LoadObject()
    {
        window = nullptr;	//window�̃C���X�^���X����
        m_WindowSize = window->GetWindowSize(); //��ʃT�C�Y�擾

        m_IsNItemSet = true;
        m_IsRItemSet = false;
        m_IsScoreSet = false;
        m_IsWait = true;
        m_CanClick = false;
        m_IsClick = false;
        m_IsHighScore_Up = false;

        m_WaitCount = m_WEIT_MAX;
        m_Compute_Spped = m_COMPUTE_SPEED_ITEM;
        m_NowColor = m_COLOR_DEFAULT;
        m_Score_Draw = 0;

        m_UiPos = m_UIPOS_RESET;
        m_NItem_Pos = { 600,400 };
        m_RItem_Pos = { 1200,400 };

        m_NItemNum = ItemGetNum::GetNowNItem();
        m_RItemNum = ItemGetNum::GetNowRItem();

        int n_item_s=0;
        int r_item_s=0;
        std::string level= level_controller::LevelController::GetLevel();
        if (level_controller::levelStatus.NOMAL == level)
        {
            n_item_s = m_NItemNum * 50;
            r_item_s = m_RItemNum * 100;
        }
        else
        {
            n_item_s = m_NItemNum * 50;
            r_item_s = m_RItemNum * 100;
        }

        m_Score = n_item_s + r_item_s;
        HighScoreGet();

        //�t�H���g�n���h���̐���
        m_FontHandle_Text = CreateFontToHandle("���C���I", m_FONTSIZE_TEXT.x, m_FONTSIZE_TEXT.y, DX_FONTTYPE_ANTIALIASING);
        m_FontHandle_Item = CreateFontToHandle("���C���I", m_FONTSIZE_ITEM.x, m_FONTSIZE_ITEM.y, DX_FONTTYPE_ANTIALIASING);
        m_FontHandle_Score = CreateFontToHandle("���C���I", m_FONTSIZE_SCORE.x, m_FONTSIZE_SCORE.y, DX_FONTTYPE_ANTIALIASING);

        //�����̒������擾���ĉ�ʒ����ɍ��W��ݒ�
        int x = GetDrawFormatStringWidthToHandle(m_FontHandle_Score, "%d�_", 0);
        float ans_x = static_cast<float>((m_WindowSize.x - x) / 2);
        m_ObjPos = { ans_x,810.0f };

        auto json = JsonManager::SoundData_Instance()->Get_Score_SoundData_Instance();
        m_JsonTag[0] = json->GetBgmNameData();
        m_JsonTag[1] = json->GetFanfare_NameData();
        m_JsonTag[2] = json->GetItem_NameData();
        m_JsonTag[3] = json->GetRoll_NameData();
        m_JsonTag[4] = json->GetScore_NameData();
        m_JsonTag[5] = json->GetButtonNameData();
        sound_controller::SoundController::AddSoundData(json->GetBgmPathData(), m_JsonTag[0], json->GetBgmVolumeData(), json->GetBgmTypeData());
        sound_controller::SoundController::AddSoundData(json->GetFanfare_PathData(), m_JsonTag[1], json->GetFanfare_VolumeData(), json->GetFanfare_TypeData());
        sound_controller::SoundController::AddSoundData(json->GetItem_PathData(), m_JsonTag[2], json->GetItem_VolumeData(), json->GetItem_TypeData());
        sound_controller::SoundController::AddSoundData(json->GetRoll_PathData(), m_JsonTag[3], json->GetRoll_VolumeData(), json->GetRoll_TypeData());
        sound_controller::SoundController::AddSoundData(json->GetScore_PathData(), m_JsonTag[4], json->GetScore_VolumeData(), json->GetScore_TypeData());
        sound_controller::SoundController::AddSoundData(json->GetButtonPathData(), m_JsonTag[5], json->GetButtonVolumeData(), json->GetButtonTypeData());
    }

    void ScoreDraw::HighScoreGet()
    {
        //�t�@�C���̓ǂݍ���
        std::ifstream file("../Asset/text/score/high_score.txt");
        std::string score;
        file >> score;
        m_HighScore = std::stoi(score);

        //�n�C�X�R�A�X�V���Ă�����t���O�𗧂Ă�
        if (m_Score >= m_HighScore)
        {
            m_IsHighScore_Up = true;
        }

        m_HighScore_Draw = m_HighScore;

        file.close();
    }

    void ScoreDraw::HighScoreSet()
    {
        //�t�@�C���̓ǂݍ���
        std::ofstream file("../Asset/text/score/high_score.txt");
        std::string score = std::to_string(m_HighScore);
        file << score << std::endl;;
        file.close();
    }

    void ScoreDraw::UpdateObj(const float deltatime)
    {
        sound_controller::SoundController::StartSound(m_JsonTag[0]);

        //���͎�t�O�͏����Ȃ�
        if (!mousestatus::MouseStatus::GetIsFadeDone())
            return;

        if (m_IsWait)
        {
            if (m_WaitCount <= 0.0f)
            {
                m_WaitCount = m_WEIT_MAX;
                m_IsWait = false;
            }
            else
            {
                m_WaitCount -= m_COUNT_DECREMENT * deltatime;
            }
        }
        else
        {
            if (m_IsNItemSet)
            {
                DrawScoreSet(m_NItem_Draw, m_NItemNum, m_IsNItemSet, deltatime);
                if (!m_IsNItemSet)
                {
                    m_IsRItemSet = true;
                    sound_controller::SoundController::StartSound(m_JsonTag[2]);
                }
            }

            if (m_IsRItemSet)
            {
                DrawScoreSet(m_RItem_Draw, m_RItemNum, m_IsRItemSet, deltatime);
                if (!m_IsRItemSet)
                {
                    m_IsScoreSet = true;
                    m_Compute_Spped = m_COMPUTE_SPEED_SCORE;
                    sound_controller::SoundController::StartSound(m_JsonTag[2]);
                }
            }

            if (m_IsScoreSet)
            {
                DrawScoreSet(m_Score_Draw, m_Score, m_IsScoreSet, deltatime);
                int x = GetDrawFormatStringWidthToHandle(m_FontHandle_Score, "%d�_", m_Score_Draw);
                float ans_x = static_cast<float>((m_WindowSize.x - x) / 2);
                m_ObjPos.x = ans_x;
                if (!m_IsScoreSet)
                {
                    m_CanClick = true;
                    sound_controller::SoundController::StartSound(m_JsonTag[1]);
                    sound_controller::SoundController::StartSound(m_JsonTag[4]);
                }
            }
        }
        
        if (m_CanClick)
        {
            ClickUiMoveAnim(deltatime);
            if (GetMouseInput() & MOUSE_INPUT_LEFT)
            {
                sound_controller::SoundController::StartSound(m_JsonTag[5]);
                ObjectManager::SetNextGameState(GameStatus::PlayEnd);

                //�X�R�A�X�V���Ă�����X�V����
                if (m_IsHighScore_Up)
                {
                    m_HighScore = m_Score;
                    HighScoreSet();
                }
            }
        }
    }

    void ScoreDraw::DrawScoreSet(int& drawobj,int ans,bool& isset,const float deltatime)
    {
        if (m_IsWait)
            return;

        sound_controller::SoundController::StartSound(m_JsonTag[3]);

        if (drawobj <= ans)
        {
            float def = m_Compute_Spped * deltatime;
            drawobj += static_cast<int>(def);
        }
        else
        {
            drawobj = ans;
            isset = false;
            m_IsWait = true;
            sound_controller::SoundController::StopSound(m_JsonTag[3]);
        }
    }

    void ScoreDraw::ClickUiMoveAnim(const float deltatime)
    {
        //���݂�Ui�ʒu���擾
        float pos = m_UiPos.y;

        //��ړ����Ȃ班�����オ�鏈��
        if (m_IsMove_Up)
        {
            //�ʒu���ړ��ő�l�𒴂�����؂�ւ�����
            if (pos < m_UIPOS_RESET.y - m_MOVEPOS_MAX)
            {
                m_IsMove_Up = false;
            }
            else
            {
                pos -= m_MOVESPEED * deltatime;
            }
        }
        else
        {
            //�����������鏈��
            if (pos > m_UIPOS_RESET.y + m_MOVEPOS_MAX)
            {
                m_IsMove_Up = true;
            }
            else
            {
                pos += m_MOVESPEED * deltatime;
            }
        }

        m_UiPos.y = pos;
    }

    void ScoreDraw::HighScoreDraw()
    {
        int collar = static_cast<int>(m_NowColor.x);

        //�X�R�A�X�V���Ă�����\���؂�ւ�
        if (m_IsHighScore_Up)
        {
            DrawFormatStringFToHandle(1000, 960, GetColor(collar, collar, collar), m_FontHandle_Text, "�n�C�X�R�A�X�V�I �O��̃X�R�A %d�_", m_HighScore_Draw);
        }
        else
        {
            DrawFormatStringFToHandle(1300, 950, GetColor(collar, collar, collar), m_FontHandle_Text, "�n�C�X�R�A %d�_", m_HighScore_Draw);
        }
    }

    void ScoreDraw::DrawObj()
    {
        int collar = static_cast<int>(m_NowColor.x);
        if (m_CanClick)
        {
            HighScoreDraw();
            DrawStringFToHandle(m_UiPos.x, m_UiPos.y, "��", GetColor(collar, collar, collar), m_FontHandle_Item);
        }

        DrawFormatStringFToHandle(150, 580, GetColor(collar, collar, collar), m_FontHandle_Item, m_ItemText.c_str(), m_NItem_Draw);
        DrawFormatStringFToHandle(1470, 580, GetColor(collar, collar, collar), m_FontHandle_Item, m_ItemText.c_str(), m_RItem_Draw);
        DrawFormatStringFToHandle(m_ObjPos.x, m_ObjPos.y, GetColor(collar, collar, collar), m_FontHandle_Score, m_ScoreText.c_str(), m_Score_Draw);

#ifdef DEBUG
        DrawFormatString(0, 14, GetColor(collar, collar, collar),"�҂�����:%f", m_WaitCount);
#endif // DEBUG
    }
}

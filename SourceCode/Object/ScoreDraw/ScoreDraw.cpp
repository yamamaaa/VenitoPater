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
        //読み込み関連
        LoadObject();
    }

    ScoreDraw::~ScoreDraw()
    {
        //メモリの解放
        delete window;
        //フォントハンドルの削除
        DeleteFontToHandle(m_FontHandle_Item);
        DeleteFontToHandle(m_FontHandle_Score);
        DeleteGraph(m_ObjHandle);
    }

    void ScoreDraw::LoadObject()
    {
        window = nullptr;	//windowのインスタンス生成
        m_WindowSize = window->GetWindowSize(); //画面サイズ取得

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

        //フォントハンドルの生成
        m_FontHandle_Text = CreateFontToHandle("メイリオ", m_FONTSIZE_TEXT.x, m_FONTSIZE_TEXT.y, DX_FONTTYPE_ANTIALIASING);
        m_FontHandle_Item = CreateFontToHandle("メイリオ", m_FONTSIZE_ITEM.x, m_FONTSIZE_ITEM.y, DX_FONTTYPE_ANTIALIASING);
        m_FontHandle_Score = CreateFontToHandle("メイリオ", m_FONTSIZE_SCORE.x, m_FONTSIZE_SCORE.y, DX_FONTTYPE_ANTIALIASING);

        //文字の長さを取得して画面中央に座標を設定
        int x = GetDrawFormatStringWidthToHandle(m_FontHandle_Score, "%d点", 0);
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
        //ファイルの読み込み
        std::ifstream file("../Asset/text/score/high_score.txt");
        std::string score;
        file >> score;
        m_HighScore = std::stoi(score);

        //ハイスコア更新していたらフラグを立てる
        if (m_Score >= m_HighScore)
        {
            m_IsHighScore_Up = true;
        }

        m_HighScore_Draw = m_HighScore;

        file.close();
    }

    void ScoreDraw::HighScoreSet()
    {
        //ファイルの読み込み
        std::ofstream file("../Asset/text/score/high_score.txt");
        std::string score = std::to_string(m_HighScore);
        file << score << std::endl;;
        file.close();
    }

    void ScoreDraw::UpdateObj(const float deltatime)
    {
        sound_controller::SoundController::StartSound(m_JsonTag[0]);

        //入力受付前は処理なし
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
                int x = GetDrawFormatStringWidthToHandle(m_FontHandle_Score, "%d点", m_Score_Draw);
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

                //スコア更新していたら更新処理
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
        //現在のUi位置を取得
        float pos = m_UiPos.y;

        //上移動中なら少しずつ上がる処理
        if (m_IsMove_Up)
        {
            //位置が移動最大値を超えたら切り替え処理
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
            //少しずつ下がる処理
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

        //スコア更新していたら表示切り替え
        if (m_IsHighScore_Up)
        {
            DrawFormatStringFToHandle(1000, 960, GetColor(collar, collar, collar), m_FontHandle_Text, "ハイスコア更新！ 前回のスコア %d点", m_HighScore_Draw);
        }
        else
        {
            DrawFormatStringFToHandle(1300, 950, GetColor(collar, collar, collar), m_FontHandle_Text, "ハイスコア %d点", m_HighScore_Draw);
        }
    }

    void ScoreDraw::DrawObj()
    {
        int collar = static_cast<int>(m_NowColor.x);
        if (m_CanClick)
        {
            HighScoreDraw();
            DrawStringFToHandle(m_UiPos.x, m_UiPos.y, "▽", GetColor(collar, collar, collar), m_FontHandle_Item);
        }

        DrawFormatStringFToHandle(150, 580, GetColor(collar, collar, collar), m_FontHandle_Item, m_ItemText.c_str(), m_NItem_Draw);
        DrawFormatStringFToHandle(1470, 580, GetColor(collar, collar, collar), m_FontHandle_Item, m_ItemText.c_str(), m_RItem_Draw);
        DrawFormatStringFToHandle(m_ObjPos.x, m_ObjPos.y, GetColor(collar, collar, collar), m_FontHandle_Score, m_ScoreText.c_str(), m_Score_Draw);

#ifdef DEBUG
        DrawFormatString(0, 14, GetColor(collar, collar, collar),"待ち時間:%f", m_WaitCount);
#endif // DEBUG
    }
}

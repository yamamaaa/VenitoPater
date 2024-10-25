#pragma once
#include<Dxlib.h>
#include<string>

#include"../../JsonMaster/JsonManager/JsonManager.h"

namespace object
{
    /// <summary>
    /// ゲームオブジェクトの基底クラス
    /// </summary>
    class ObjectBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="tagname"></param>
        ObjectBase(std::string tagname);

        /// <summary>
        /// デストラクタ
        /// </summary>
        virtual ~ObjectBase();

        /// <summary>
        /// オブジェクトの初期化
        /// </summary>
        virtual void LoadObject() = 0;

        /// <summary>
        /// オブジェクトの更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        virtual void UpdateObj(float deltatime) = 0;

        /// <summary>
        /// オブジェクトの描画
        /// </summary>
        virtual void DrawObj() = 0;

        /// <summary>
        /// 移動処理
        /// </summary>
        virtual void MoveObj() {};

        /// <summary>
        /// オブジェクトのタグ名取得
        /// </summary>
        /// <returns>タグ名</returns>
        std::string GetTagName()const { return m_ObjTag; }

        /// <summary>
        /// 位置情報取得
        /// </summary>
        /// <returns></returns>
        const VECTOR& GetObjPos()const { return m_ObjPos; }

        /// <summary>
        /// オブジェクトの生死状態の取得
        /// </summary>
        /// <returns></returns>
        bool GetAlive() const { return m_Alive; }

        /// <summary>
        /// オブジェクトの生死状態セット
        /// </summary>
        /// <param name="alive"></param>
        void SetAlive(bool alive) { m_Alive = alive; }

    protected:

        std::string m_ObjTag;   //オブジェクトタグ

        VECTOR m_ObjPos;        //位置情報
        bool m_Alive;           //生死状態
        int m_ObjHandle;        //オブジェクトハンドル

        int m_ImgSize_Y;        //画像縦サイズ
        int m_ImgSize_X;        //画像横サイズ

        float m_MoveSpeed;      //動くスピード
    };
}
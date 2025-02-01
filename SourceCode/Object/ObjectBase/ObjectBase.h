#pragma once
#include<Dxlib.h>
#include<string>
#include"../../JsonMaster/JsonManager/JsonManager.h"
#include"../../Object/ObjectTag/Play_ObjectTag.h"
#include"../../Collision/Collision.h"
#include"../../Math2D/Math2D.h"

#define DEBUG
using namespace jsonmaster;
using namespace collision;
using namespace math2d;
using namespace objecttag;

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
        /// <param name="tagname">タグ名</param>
        ObjectBase(std::string tagname);

        /// <summary>
        /// デストラクタ
        /// </summary>
        virtual ~ObjectBase();

        /// <summary>
        /// オブジェクトの読み込み関連
        /// </summary>
        virtual void LoadObject() = 0;

        /// <summary>
        /// オブジェクトの更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        virtual void UpdateObj(const float deltatime) = 0;

        /// <summary>
        /// オブジェクトの描画
        /// </summary>
        virtual void DrawObj() = 0;

        /// <summary>
        /// 移動処理
        /// </summary>
        virtual void MoveObj(const float deltatime) {};

        /// <summary>
        /// オブジェクトのタグ名取得
        /// </summary>
        /// <returns>タグ名</returns>
        const std::string GetTagName()const { return m_ObjTag; }

    protected:

        std::string m_ObjTag;   //オブジェクトタグ

        POINTFLOAT m_ObjPos;    //オブジェクト座標
        POINTS m_ObjSize;       //オブジェクトサイズ
        POINTS m_DrawOffset;    // 当たり判定からの横方向ずらし量

        int m_ObjHandle;        //オブジェクトハンドル
    };
}
#include "ObjectManager.h"

namespace object
{
    //実体の中身を空に
    std::unique_ptr<ObjectManager>ObjectManager::objectmanager = nullptr;

    ObjectManager::ObjectManager()
        :m_Objects(0),
        m_NowScene_Name(""),
        m_GameStatus()
    {
        objectmanager = nullptr;
    }

    ObjectManager::~ObjectManager()
    {
        //処理なし
    }

    void ObjectManager::Initialize()
    {
        //自身の中身が空ならインスタンス生成
        if (!objectmanager)
        {
            objectmanager.reset(new ObjectManager);
        }
    }

    void ObjectManager::Entry(ObjectBase* newObj)
    {
        //タグの検索をしてオブジェクト登録
        std::string tag = newObj->GetTagName();
        objectmanager->m_Objects[tag].emplace_back(newObj);
    }

    void ObjectManager::ReleaseAllObj()
    {
        //空じゃなかったらオブジェクト削除
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            if (!objectmanager->m_Objects[tag].empty())
            {
                objectmanager->m_Objects[tag].clear();
            }
        }
    }

    void ObjectManager::UpdateAllObj(const float deltatime)
    {
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            // 該当タグにあるすべてのオブジェクトを更新
            for (auto& obj : objectmanager->m_Objects[tag])
            {
                //更新
                obj->UpdateObj(deltatime);
            }
        }

    }

    void ObjectManager::DrawAllObj()
    {
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            for (auto& obj : objectmanager->m_Objects[tag])
            {
                obj->DrawObj();
            }
        }
    }

    void ObjectManager::OnDeadObj(std::shared_ptr<ObjectBase> unnecobj)
    {
        //削除オブジェクトのタグ取得
        std::string tag = unnecobj->GetTagName();

        ////プレイヤーが死亡したら
        //if (tag == "player")
        //{

        //}

        //オブジェクトを検索
        //auto endObj = objectmanager->m_Objects[tag].end();
        //auto findObj = std::find(objectmanager->m_Objects[tag].begin(), endObj, unnecobj);

        ////見つかったら末尾に移動させて削除
        //if (findObj != endObj)
        //{
        //    std::swap(findObj, endObj);
        //    objectmanager->m_Objects[tag].pop_back();
        //}
    }

    ObjectBase* ObjectManager::GetFirstGameObj(std::string tagname)
    {
        //アクティブリストに何も入ってなかったら
        if (objectmanager->m_Objects[tagname].size() == 0)
        {
            //nullptr 空 何もない
            return nullptr;
        }

        //もし入っていたらアクティブリストのオブジェクトの一番目(個数)を返す
        return objectmanager->m_Objects[tagname][0].get();
    }
}

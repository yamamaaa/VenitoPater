#include "ObjectManager.h"

#include"../../Object/ObjectBase/ObjectBase.h"

namespace object
{
    //実体の中身を空に
    std::unique_ptr<ObjectManager>ObjectManager::objectmanager = nullptr;

    ObjectManager::ObjectManager()
        :m_Objects(0)
    {
        objectmanager = nullptr;
    }
    ObjectManager::~ObjectManager()
    {
        //  メモリの開放
        delete objectbase;
    }

    void ObjectManager::Initialize()
    {
        //自身の中身が空ならインスタンス生成
        if (!objectmanager)
        {
            objectmanager.reset(new ObjectManager);
        }
    }

    void ObjectManager::NowSceneSet(std::vector<std::string> scene_objtag)
    {
        objectmanager->m_SceneTag = scene_objtag;
    }

    void ObjectManager::Entry(ObjectBase* newObj)
    {
        //タグの検索をしてオブジェクト登録
        std::string tag = newObj->GetTagName();
        objectmanager->m_Objects[tag].emplace_back(newObj);
    }

    void ObjectManager::ReleaseAllObj()
    {
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            //末尾からアクティブオブジェクトの削除
            while (!objectmanager->m_Objects[tag].empty())
            {
                //要素を参照して削除
                delete objectmanager->m_Objects[tag].back().get();
                objectmanager->m_Objects[tag].pop_back();
            }
        }
    }

    void ObjectManager::UpdateAllObj(float deltatime)
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

    void ObjectManager::MoveAllObj()
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

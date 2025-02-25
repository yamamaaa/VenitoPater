#include "ObjectManager.h"
#include "../../MouseStatus/MouseStatus.h"

namespace object
{
    //実体の中身を空に
    std::unique_ptr<ObjectManager>ObjectManager::objectmanager = nullptr;

    ObjectManager::ObjectManager()
        :m_Objects(0),
        m_NextGameStatus()
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
        //オブジェクト削除
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            objectmanager->m_Objects[tag].clear();
        }

        objectmanager->m_Objects.clear();
    }

    void ObjectManager::UpdateAllObj(const float deltatime)
    {
        //メニューモードならメニューのみ更新
        if (mousestatus::MouseStatus::GetIsMenuMode())
        {
            for (auto& obj : objectmanager->m_Objects[objectmanager->MENU])
            {
                //更新
                obj->UpdateObj(deltatime);
            }
            return;
        }

        for (std::string& tag : objectmanager->m_SceneTag)
        {
            if (!objectmanager->m_Objects[tag].empty())
            {
                // 該当タグにあるすべてのオブジェクトを更新
                for (auto& obj : objectmanager->m_Objects[tag])
                {
                    //更新
                    obj->UpdateObj(deltatime);
                }
            }
        }
    }

    void ObjectManager::DrawAllObj()
    {
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            if (!objectmanager->m_Objects[tag].empty())
            {
                for (auto& obj : objectmanager->m_Objects[tag])
                {
                    obj->DrawObj();
                }
            }
        }
    }

    void ObjectManager::ReleaseObj(std::string tagname)
    {
        objectmanager->m_Objects[tagname].clear();
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

#include "ObjectManager.h"

#include"../../Object/ObjectBase/ObjectBase.h"

namespace object
{
    //���̂̒��g�����
    std::unique_ptr<ObjectManager>ObjectManager::objectmanager = nullptr;

    ObjectManager::ObjectManager()
        :m_Objects(0)
    {
        objectmanager = nullptr;
    }
    ObjectManager::~ObjectManager()
    {
        //  �������̊J��
        delete objectbase;
    }

    void ObjectManager::Initialize()
    {
        //���g�̒��g����Ȃ�C���X�^���X����
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
        //�^�O�̌��������ăI�u�W�F�N�g�o�^
        std::string tag = newObj->GetTagName();
        objectmanager->m_Objects[tag].emplace_back(newObj);
    }

    void ObjectManager::ReleaseAllObj()
    {
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            //��������A�N�e�B�u�I�u�W�F�N�g�̍폜
            while (!objectmanager->m_Objects[tag].empty())
            {
                //�v�f���Q�Ƃ��č폜
                delete objectmanager->m_Objects[tag].back().get();
                objectmanager->m_Objects[tag].pop_back();
            }
        }
    }

    void ObjectManager::UpdateAllObj(float deltatime)
    {
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            // �Y���^�O�ɂ��邷�ׂẴI�u�W�F�N�g���X�V
            for (auto& obj : objectmanager->m_Objects[tag])
            {
                //�X�V
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
        //�폜�I�u�W�F�N�g�̃^�O�擾
        std::string tag = unnecobj->GetTagName();

        ////�v���C���[�����S������
        //if (tag == "player")
        //{

        //}

        //�I�u�W�F�N�g������
        //auto endObj = objectmanager->m_Objects[tag].end();
        //auto findObj = std::find(objectmanager->m_Objects[tag].begin(), endObj, unnecobj);

        ////���������疖���Ɉړ������č폜
        //if (findObj != endObj)
        //{
        //    std::swap(findObj, endObj);
        //    objectmanager->m_Objects[tag].pop_back();
        //}
    }

    ObjectBase* ObjectManager::GetFirstGameObj(std::string tagname)
    {
        //�A�N�e�B�u���X�g�ɉ��������ĂȂ�������
        if (objectmanager->m_Objects[tagname].size() == 0)
        {
            //nullptr �� �����Ȃ�
            return nullptr;
        }

        //���������Ă�����A�N�e�B�u���X�g�̃I�u�W�F�N�g�̈�Ԗ�(��)��Ԃ�
        return objectmanager->m_Objects[tagname][0].get();
    }
}

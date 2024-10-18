#include "SceneManager.h"
#include "TestScene.h"
#include "PlayScene.h"
#include "Engine/Direct3D.h"
#include "Model.h"

SceneManager::SceneManager(GameObject* parent)
    :GameObject(parent,"SceneManager")
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID_ = SCENE_ID_TEST;
	nextSceneID_ = SCENE_ID_TEST;
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
    //���̃V�[�������݂̃V�[���ƈႤ �� �V�[����؂�ւ��Ȃ���΂Ȃ�Ȃ�
    if (currentSceneID_ != nextSceneID_)
    {
        //���̃V�[���̃I�u�W�F�N�g��S�폜(�q�I�u�W�F�N�g�����ׂč폜)

        for (auto itr : childList_) {
            itr->ReleaseSub();
            SAFE_DELETE(itr);
            childList_.clear();
        }

        Model::Release();

        //���[�h�����f�[�^��S�폜

        //���̃V�[�����쐬
        switch (nextSceneID_)
        {
        case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
        }

        //�����V�[���𐶐��o������A�J�����g�V�[�����X�V
        currentSceneID_ = nextSceneID_;
    }
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}

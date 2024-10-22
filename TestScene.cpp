#include "TestScene.h"
#include "Engine/Input.h"
#include "SceneManager.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent,"TestScene")
{
	sp = new Sprite();
}

void TestScene::Initialize()
{
	sp->Load("Assets\\Title.png");
}

void TestScene::Update()
{
	if (Input::IsKey(DIK_SPACE)) {
		SceneManager* pSceneManater = (SceneManager*)FindObject("SceneManager");
		pSceneManater->ChangeScene(SCENE_ID_PLAY);
	}
}

void TestScene::Draw()
{
	sp->Draw(transform_);
}

void TestScene::Release()
{
	SAFE_DELETE(sp);
}

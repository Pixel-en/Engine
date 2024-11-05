#include "ENDScene.h"
#include "Engine/Input.h"
#include "SceneManager.h"

ENDScene::ENDScene(GameObject* parent)
	:GameObject(parent, "ENDScene")
{
	sp = new Sprite();
}

void ENDScene::Initialize()
{
	sp->Load("Assets\\END.png");
}

void ENDScene::Update()
{
	if (Input::IsKeyUp(DIK_RETURN)) {
		SceneManager* pSceneManater = (SceneManager*)FindObject("SceneManager");
		pSceneManater->ChangeScene(SCENE_ID_TEST);
	}
}

void ENDScene::Draw()
{
	sp->Draw(transform_);
}

void ENDScene::Release()
{
	SAFE_DELETE(sp);
}

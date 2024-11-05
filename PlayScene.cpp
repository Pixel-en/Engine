#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/Input.h"
#include "SphereCollider.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
	transform_.position_ = { 0,0,0 };
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{

	Instantiate<Player>(this);
	
	SphereCollider* col = new SphereCollider(0.1f);
	this->AddCollider(col);
}

void PlayScene::Update()
{
	static int cnt = 0;
	cnt++;
	if (cnt > 60) {
		cnt = 0;
		int ran = rand() % 4;

		Enemy* e = Instantiate<Enemy>(this);
		if (ran == 0)
			e->SetPosition(rand() % 10 + 20, 0, rand() % 10 + 20);
		else if(ran == 1)
			e->SetPosition(rand() % 10 + 20, 0, rand() % 10 - 20);
		else if (ran == 2)
			e->SetPosition(rand() % 10 - 20, 0, rand() % 10 + 20);
		else
			e->SetPosition(rand() % 10 - 20, 0, rand() % 10 - 20);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}

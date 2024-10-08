#include "Player.h"
#include "Engine/FBX.h"
#include "ChildOden.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),pOden(nullptr)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	pOden = new FBX;
	pOden->Load("Assets//ODEN2.fbx");
	transform_.scale_ = { 0.7,0.7,0.7 };
	GameObject* pCo = Instantiate<ChildOden>(this);
	pCo->SetPosition(-2, 0, 1);
}

void Player::Update()
{
	transform_.rotate_.y += 0.1;
	if (transform_.rotate_.y > 60 * 1)
		Killme();
}

void Player::Draw()
{
	pOden->Draw(transform_);
}

void Player::Release()
{
	pOden->Release();
	delete pOden;
}

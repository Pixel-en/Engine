#include "Player.h"
#include "Engine/FBX.h"

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
}

void Player::Update()
{
	transform_.rotate_.y += 0.001;
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
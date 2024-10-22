#include "Enemy.h"
#include "Model.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy")
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Assets\\Enemy2.fbx");
	transform_.scale_ = { 0.5, 0.5, 0.5 };
	transform_.position_ = { 0,7,0 };
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

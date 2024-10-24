#include "Enemy.h"
#include "Model.h"
#include "SphereCollider.h"


Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy")
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Assets\\Enemy.fbx");
	transform_.scale_ = { 0.1, 0.1, 0.1 };
	transform_.position_ = { 0,7,0 };
	SphereCollider* col = new SphereCollider(0.1f);
	this->AddCollider(col);
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

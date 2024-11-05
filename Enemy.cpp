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
	hModel_ = Model::Load("Assets\\Enemy3.fbx");
	transform_.scale_ = { 1, 1, 1 };
	transform_.position_ = { 0,0,20 };
	SphereCollider* col = new SphereCollider(0.1f);
	this->AddCollider(col);
}

void Enemy::Update()
{
	XMVECTOR pos = XMLoadFloat3(&transform_.position_);

	XMVECTOR trans = pos - XMVectorSet(0, 0, 0, 0);

	pos -= trans * 0.005;
	XMStoreFloat3(&transform_.position_, pos);


}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

#include "ChildOden.h"
#include "Model.h"
#include "Enemy.h"
#include "SphereCollider.h"
#include "Engine/Input.h"
#include "Player.h"

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent,"ChildOden"),hModel_(-1)
{
}

void ChildOden::Initialize()
{
	hModel_ = Model::Load("Assets/ODEN2.fbx");

	SphereCollider* col = new SphereCollider(0.5f);
	AddCollider(col);
}

void ChildOden::Update()
{
	XMVECTOR pos = XMLoadFloat3(&transform_.position_);
	pos -= movevec * 0.5;
	XMStoreFloat3(&transform_.position_, pos);

	if (transform_.position_.x > 100 || transform_.position_.y > 100 || transform_.position_.z > 100)
		Killme();

}

void ChildOden::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void ChildOden::Release()
{
}

void ChildOden::onCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy") {
		pTarget->Killme();
		Killme();
	}
}

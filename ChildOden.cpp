#include "ChildOden.h"
#include "Model.h"
#include "Enemy.h"

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent,"ChildOden"),hModel_(-1)
{
}

void ChildOden::Initialize()
{
	hModel_ = Model::Load("Assets/ODEN2.fbx");
	transform_.scale_.x = 0.2f;
	transform_.scale_.y = 0.2f;
	transform_.scale_.z = 0.2f;
	transform_.position_.x = 2.0f;
	transform_.position_.y = 1.0f;
}

void ChildOden::Update()
{
	transform_.rotate_.y += 0.1;
	transform_.position_.y += 0.1;

	Enemy* enemy = (Enemy*)FindObject("Enemy");

	float er = 0.1;
	float br= 0.5;


	//XMFLOAT3 P1 = enemy->GetPosition();
	//XMFLOAT3 P2 = transform_.position_;
	
	//XMVECTOR Dist = XMVector3Length(XMVectorSet(P1.x, P1.y, P1.z, 1) - XMVectorSet(P2.x, P2.y, P2.z, 1));
	//float d = XMVectorGetX(Dist);
	
	//if (d <= er + br)
		//Killme();
	
	
	if (sqrtf(powf(transform_.position_.x - enemy->GetPosition().x, 2.0) +
		powf(transform_.position_.y - enemy->GetPosition().y, 2.0) +
		powf(transform_.position_.z - enemy->GetPosition().z, 2.0)) < er * er + br * br)
		Killme();
		
	if (transform_.position_.y > 20.0)
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

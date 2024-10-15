#include "ChildOden.h"
#include "Model.h"

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

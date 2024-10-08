#include "ChildOden.h"
#include "Engine/FBX.h"

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent,"ChildOden")
{
}

void ChildOden::Initialize()
{
	pFbx = new FBX;
	pFbx->Load("Assets/ODEN2.fbx");
	transform_.scale_.x = 0.2f;
	transform_.scale_.y = 0.2f;
	transform_.scale_.z = 0.2f;
	transform_.position_.x = 2.0f;
	transform_.position_.y = 1.0f;
}

void ChildOden::Update()
{
	transform_.rotate_.y += 0.1;
}

void ChildOden::Draw()
{
	pFbx->Draw(transform_);
}

void ChildOden::Release()
{
}

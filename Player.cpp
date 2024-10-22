#include "Player.h"
#include "Engine/FBX.h"
#include "ChildOden.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Model.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{

	hModel_=Model::Load("Assets\\ODEN2.fbx");
	//pOden = new FBX;
	//pOden->Load("Assets//ODEN2.fbx");
	transform_.scale_ = { 0.7,0.7,0.7 };
	//GameObject* pCo = Instantiate<ChildOden>(this);
	//pCo->SetPosition(-2, 0, 1);
	Camera::SetPosition(XMVectorSet(0, 3, -15, 0));
	Camera::SetTarget(XMVectorSet(0, 4, 0, 0));
	transform_.position_ = { 0, 0, 0 };
}

void Player::Update()
{
	transform_.rotate_.y += 0.1;

	if (Input::IsKey(DIK_D))
		transform_.position_.x += 0.1;
	if (Input::IsKey(DIK_A))
		transform_.position_.x -= 0.1;

	if (Input::IsKeyDown(DIK_SPACE)) {
		GameObject* pCo = Instantiate<ChildOden>(GetParent());
		pCo->SetPosition(transform_.position_.x, 4, 0);
		pCo->SetScale(0.1, 0.1, 0.1);
	}

}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

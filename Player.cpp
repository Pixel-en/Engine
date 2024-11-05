#include "Player.h"
#include "Engine/FBX.h"
#include "ChildOden.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Model.h"
#include "SphereCollider.h"
#include "SceneManager.h"

namespace {
	const float MOVESPEED{ 1.0f };
}

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
	speed_ = MOVESPEED;
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Assets\\Crosshair.fbx");

	SphereCollider* col = new SphereCollider(1.0f);
	AddCollider(col);
	

	//pOden = new FBX;
	//pOden->Load("Assets//ODEN2.fbx");
	transform_.scale_ = { 0.01,0.01,0.01 };

}

void Player::Update()
{
#if 0
	//オブジェクトを軸にカメラが回転
	Transform camrottrans = transform_;

	if (Input::IsKey(DIK_D)) {
		//trans += moveVector;
		camrottrans.rotate_.y += 1.0f;
		XMMATRIX camrotmatrix = XMMatrixRotationY(camrottrans.rotate_.y / 180.0f * 3.14f);

		Camera::SetPosition(XMVector3TransformCoord(Camera::GetPosition(), camrotmatrix));
	}
	if (Input::IsKey(DIK_A)) {
		//trans -= moveVector;
		camrottrans.rotate_.y -= 1.0f;
		XMMATRIX camrotmatrix = XMMatrixRotationY(camrottrans.rotate_.y / 180.0f * 3.14f);

		Camera::SetPosition(XMVector3TransformCoord(Camera::GetPosition(), camrotmatrix));
	}

#endif

	Transform camtrans = Camera::GetTrans();

	XMVECTOR camtar = Camera::GetPosition();

	if (Input::IsKey(DIK_D)) {
		camtrans.rotate_.y += speed_;
	}
	if (Input::IsKey(DIK_A)) {
		camtrans.rotate_.y -= speed_;
	}

	if (Input::IsKeyDown(DIK_SPACE)) {
		ChildOden* pCo = Instantiate<ChildOden>(this);
		XMFLOAT3 temp;
		XMVECTOR targetpos = XMVectorSet(XMVectorGetX(Camera::GetTarget()), XMVectorGetY(Camera::GetTarget()), XMVectorGetZ(Camera::GetTarget()), 0);
		XMStoreFloat3(&temp, targetpos);
		pCo->SetPosition(temp);
		pCo->SetScale(0.01, 0.01, 0.01);
		pCo->SetVec(Camera::GetPosition() - Camera::GetTarget());
	}

	XMMATRIX rot = XMMatrixRotationY(camtrans.rotate_.y / 180.0f * 3.14f);
	XMVECTOR move = XMVector3TransformCoord(XMVectorSet(0, 0,0.1f, 0), rot);
	camtar += move;

	Camera::SetTarget(camtar);
	Camera::SetTrans(camtrans);

	XMStoreFloat3(&transform_.position_, camtar);
	
	//XMStoreFloat3(&transform_.position_, trans);
	//Camera::SetTarget(trans);
	//Camera::SetTarget(XMLoadFloat3(&transform_.position_));
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::onCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy") {
		SceneManager* pSceneManater = (SceneManager*)FindObject("SceneManager");
		pSceneManater->ChangeScene(SCENE_ID_END);
	}
		

}

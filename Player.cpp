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
	Camera::SetPosition(XMVectorSet(0, 3, -20, 0));
	Camera::SetTarget(XMLoadFloat3(&transform_.position_));
	transform_.position_ = { 0, 0, 0 };


	GameObject* pCo = Instantiate<ChildOden>(this);
	pCo->SetPosition(transform_.position_.x+5, 0, 5);
	pCo->SetScale(0.1, 0.1, 0.1);
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
#if 0

	//カメラ用Transform
	Transform camtrans;
	camtrans = transform_;
	XMStoreFloat3(&camtrans.position_, Camera::GetPosition());

	XMVECTOR temp = XMLoadFloat3(&transform_.position_);

	if (Input::IsKey(DIK_D)) {
		camtrans.rotate_.y += 1.0f;
		XMMATRIX rotateMatrix = XMMatrixRotationY(camtrans.rotate_.y / 180.0f * 3.14f);
		XMVECTOR  moveVector = XMVector3TransformCoord(temp, rotateMatrix);
		//temp += moveVector;
		XMStoreFloat3(&transform_.position_, moveVector);

		//デバッグ
		wchar_t buffer[256];
		swprintf_s(buffer, L"%f\n",camtrans.rotate_.y);
		OutputDebugString(buffer);

		//Camera::SetTarget(temp);
	}
	if (Input::IsKey(DIK_A)) {
		camtrans.rotate_.y -= 1.0f;
	}
#endif

	if (Input::IsKey(DIK_D)) {
		
	}
	if (Input::IsKey(DIK_A)) {

	}

	if (Input::IsKey(DIK_RIGHT)) {
		transform_.position_.x += 0.1;
	}
	if (Input::IsKey(DIK_LEFT)) {
		transform_.position_.x -= 0.1;
	}

	if (Input::IsKeyDown(DIK_SPACE)) {
		GameObject* pCo = Instantiate<ChildOden>(this);
		pCo->SetPosition(transform_.position_);
		pCo->SetScale(0.1, 0.1, 0.1);
	}
	
	//XMStoreFloat3(&transform_.position_, trans);
	//Camera::SetTarget(trans);
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

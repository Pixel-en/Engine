#pragma once
#include "Engine/GameObject.h"

//前方宣言	これによりどこかで宣言されていると伝えて多重宣言を防ぐ
class FBX;

class Player : public GameObject
{
	//FBX* pOden;
	int hModel_;

	//カメラ用Transform
	Transform camtrans;

public:
	Player(GameObject* parent);
	~Player();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;


};


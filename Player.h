#pragma once
#include "Engine/GameObject.h"

//�O���錾	����ɂ��ǂ����Ő錾����Ă���Ɠ`���đ��d�錾��h��
class FBX;

class Player : public GameObject
{
	//FBX* pOden;
	int hModel_;

	//�J�����pTransform
	Transform camtrans;

public:
	Player(GameObject* parent);
	~Player();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;


};


#pragma once
#include "Engine/GameObject.h"

class FBX;

class ChildOden :
	public GameObject
{
	int hModel_;

	XMVECTOR movevec;
public:

	ChildOden(GameObject* parent);

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void SetVec(XMVECTOR move) { movevec = move; }

	void onCollision(GameObject* pTarget) override;
};


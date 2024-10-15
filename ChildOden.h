#pragma once
#include "Engine/GameObject.h"

class FBX;

class ChildOden :
	public GameObject
{
	int hModel_;
public:

	ChildOden(GameObject* parent);

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

};


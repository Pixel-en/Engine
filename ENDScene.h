#pragma once
#include "Engine/GameObject.h"
#include "Engine/Sprite.h"

class ENDScene :
	public GameObject
{
	Sprite* sp;

public:

	ENDScene(GameObject* parent);

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

};


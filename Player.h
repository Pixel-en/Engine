#pragma once
#include "Engine/GameObject.h"

//‘O•ûéŒ¾	‚±‚ê‚É‚æ‚è‚Ç‚±‚©‚ÅéŒ¾‚³‚ê‚Ä‚¢‚é‚Æ“`‚¦‚Ä‘½déŒ¾‚ğ–h‚®
class FBX;

class Player : public GameObject
{
	//FBX* pOden;
	int hModel_;


public:
	Player(GameObject* parent);
	~Player();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;


};


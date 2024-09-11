#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(nullptr),objectName_(name)
{
}

GameObject::~GameObject()
{
}

void GameObject::UpdateSub()
{
	Update();
	for (auto it : childList_) {
		it->UpdateSub();
	}
}

void GameObject::DrawSub()
{
	Draw();
	for (auto it : childList_){
		it->DrawSub();
	}
}

void GameObject::ReleaseSub()
{
	Release();
	for (auto it : childList_) {
		it->ReleaseSub();
	}
}

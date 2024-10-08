#include "GameObject.h"
#include "Direct3D.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent),objectName_(name)
{
	if (parent != nullptr)
		this->transform_.pParent_ = &(parent->transform_);
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
	for (auto itr = childList_.begin(); itr != childList_.end();) {
		if ((*itr)->isDead_) {
			(*itr)->ReleaseSub();
			//(*itr)->Release();
			SAFE_DELETE(*itr);
			itr = childList_.erase(itr);
		}
		else
			itr++;
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

void GameObject::Killme()
{
	isDead_ = true;
}

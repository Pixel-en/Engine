#include "GameObject.h"
#include "Direct3D.h"
#include "../SphereCollider.h"

GameObject::GameObject()
	:pParent_(nullptr),pCollider_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent),objectName_(name), pCollider_(nullptr)
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

void GameObject::AddCollider(SphereCollider* pColl)
{
	pCollider_ = pColl;
}

void GameObject::Collision(GameObject* pTarget)
{
	if (this->pCollider_ == nullptr || pTarget->pCollider_ == nullptr || this == pTarget)
		return;

	//�����ƃ^�[�Q�b�g�̃R���C�_�[���m�̓����蔻���`��
	XMFLOAT3 P1 = this->transform_.position_;
	XMFLOAT3 P2 = pTarget->transform_.position_;

	XMVECTOR dist = XMVector3Length(XMVectorSet(P1.x, P1.y, P1.z, 1) - XMVectorSet(P2.x, P2.y, P2.z, 1));
	if (XMVectorGetX(dist) <= (pTarget->pCollider_->GetRadius() + this->pCollider_->GetRadius())) {

	}


}

void GameObject::RoundRobin(GameObject* pTarget)
{
	//�����ƃ^�[�Q�b�g�̓����蔻��
	//�����ƃ^�[�Q�b�g�̎q�I�u�W�F�N�g�S���̓����蔻��

}

GameObject* GameObject::FindObject(std::string objName)
{
	//if (GetRootJob()->objectName_ == objName)
	//	return this;
	//else {
	//	for (auto itr : childList_) {
	//		GameObject* obj = itr->FindChildObject(objName);
	//		if (obj != nullptr)
	//			return obj;
	//	}
	//}

	//return nullptr;

	
	GameObject* rootJob = GetRootJob();
	GameObject* res = rootJob->FindChildObject(objName);

	return res;
	

	}

GameObject* GameObject::GetRootJob()
{
	if (pParent_ == nullptr)
		return this;

	//�ċN�Ăяo��
	return pParent_->GetRootJob();
}

GameObject* GameObject::FindChildObject(std::string objName)
{
	if (this->objectName_ == objName)
		return this;
	else {
		for (auto itr : childList_) {
			GameObject* obj = itr->FindChildObject(objName);
			if (obj != nullptr)
				return obj;
		}
	}

	return nullptr;
}

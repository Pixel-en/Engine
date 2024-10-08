#include "Transform.h"

Transform::Transform()
    :position_({0,0,0}),
    rotate_({0,0,0}),
    scale_({ 1, 1, 1 }),
    matTranslate_(XMMatrixIdentity()),
    matRotate_(XMMatrixIdentity()),
    matScale_(XMMatrixIdentity())
{
    //float x = XMVectorGetX(position_);
    //float y = XMVectorGetY(position_);
    //float z = XMVectorGetZ(position_);
    //float w = XMVectorGetW(position_);
}

Transform::~Transform()
{
}

void Transform::Calculation()
{
    //SRT�̏��ԂŊ|����ƃ��[���h�ϊ��ɂȂ�

    //�ړ��s��̌v�Z
    matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);

    //��]�s��̌v�Z   Z*X*Y�̏��ԌŒ�
    //digree->radians
    XMMATRIX rx = XMMatrixRotationX(rotate_.x);
    XMMATRIX ry = XMMatrixRotationY(rotate_.y);
    XMMATRIX rz = XMMatrixRotationZ(rotate_.z);
    matRotate_ = rz * rx * ry;

    //�g��s��̌v�Z
    matScale_ = XMMatrixScaling(scale_.x,scale_.y,scale_.z);


}

XMMATRIX Transform::GetWorldMatrix()
{
    //return matScale_ * matRotate_ * matTranslate_;
    if (pParent_ != nullptr) {
        return matScale_ * matRotate_ * matTranslate_ * pParent_->GetWorldMatrix();
    }
    else
    {
        return matScale_ * matRotate_ * matTranslate_;
    }
}

XMMATRIX Transform::GetNormalMatrix()
{
    //���s�ړ��͖����@��]�͂�����@�X�P�[���͌��ɖ߂�
    return (matRotate_ * XMMatrixInverse(nullptr, matScale_));
}

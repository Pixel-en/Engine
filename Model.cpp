#include "Model.h"
#include "Engine/Direct3D.h"

//�l�[���X�y�[�X�͕ʂ̂Ƃ��납��ł��ǉ��ł���]�I�I
namespace Model {
	std::vector<ModelData*> modelList;
}

int Model::Load(std::string filename)
{

	ModelData* pData = new ModelData;

	pData->filename_ = filename;

	for (auto& e : modelList) {
		//�����̃t�@�C�����������ꍇ�V�����ۑ����Ȃ�
		if (e->filename_ == filename) {
			pData->pFbx_ = e->pFbx_;
			break;
		}
	}
	//�����̃t�@�C�����Ȃ������ꍇ
	if (pData->pFbx_ == nullptr) {
		pData->pFbx_ = new FBX;
		pData->pFbx_->Load(filename);
	}

	modelList.push_back(pData);

	return modelList.size() - 1;

}

void Model::SetTransform(int hModel, Transform transform)
{
	modelList[hModel]->transform_ = transform;
}

void Model::Draw(int hModel)
{
	modelList[hModel]->pFbx_->Draw(modelList[hModel]->transform_);
}

void Model::Release()
{
	bool isReferred = false;
	//���f���̔ԍ��𒲂ׂĎQ�Ƃ���Ă���̂�����Ώ����Ă���
	for (int j = 0; j < modelList.size(); j++) {
		for (int i = j + 1; i < modelList.size(); i++) {
			if (modelList[j]->pFbx_ == modelList[i]->pFbx_)
			{
				isReferred = true;
				break;
			}
		}
		if (!isReferred) {
			SAFE_DELETE(modelList[j]->pFbx_);;
		}
		SAFE_DELETE(modelList[j]);
	}
	modelList.clear();
}

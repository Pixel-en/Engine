#pragma once
#include <DirectXMath.h>
#include <fbxsdk.h>
#include "Direct3D.h"
#include <DirectXMath.h>
#include "Texture.h"
#include <vector>
#include "Transform.h"
#include "filesystem"

#pragma comment(lib, "LibFbxSDK-MD.lib")
//#pragma comment(lib, "LibFbxSDK-MT.lib")
#pragma comment(lib, "LibXml2-MT.lib")
#pragma comment(lib, "zlib-MT.lib")


class FBX
{
	//�}�e���A��
	struct MATERIAL
	{
		Texture* pTexture;
		XMFLOAT4 diffuse;
	};


	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;		//���[���h�r���[
		XMMATRIX	matNormal;	//�@���x�N�g��
		XMFLOAT4	diffuseColor;
		int		isTextured;	//�e�N�X�`�����\���Ă��邩�ǂ���
	};

	//���_���
	struct VERTEX
	{
		XMVECTOR position;
		XMVECTOR uv;
		XMVECTOR normal;
	};

	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer** pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@
	std::vector<MATERIAL> pMaterialList_;	

	int vertexCount_;	//���_��
	int polygonCount_;	//�|���S����
	int materialCount_;	//�}�e���A���̌�

	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void InitConstantBuffer();
	void InitMaterial(fbxsdk::FbxNode* pNode);

	std::vector<int> indexcount;

public:

	FBX();
	HRESULT Load(std::string fileName);
	void Draw(Transform& transform);
	void Release();

};


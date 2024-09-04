#pragma once
#include <DirectXMath.h>
#include "Direct3D.h"
#include "Texture.h"
#include <vector>
#include "Transform.h"

using std::vector;
using namespace DirectX;

struct CONSTANT_BUFFER2D
{
	XMMATRIX	matW;
};

//���_���
struct VERTEX2D
{
	XMVECTOR position;
	XMVECTOR uv;
};

class Sprite
{
private:
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture* pTexture_;		//�e�N�X�`���ւ̃|�C���^

	uint64_t vertexNum_;		//���_��
	vector<VERTEX2D> vertices_;	//���_���
	uint64_t indexNum_;			//�C���f�b�N�X��
	vector<int> indices_;		//�C���f�b�N�X���

public:

	Sprite();
	~Sprite();
	HRESULT Load(std::string fileName);
	void Draw(Transform& transform);
	void Release();

private:

	//--------Initialize�֐�����Ă΂��֐�--------

	void InitVertexData();			//���_���̏���
	HRESULT CreateVertexBuffer();	//���_�o�b�t�@���쐬

	void InitIndexData();			//�C���f�b�N�X��������
	HRESULT CreateIndexBuffer();	//�C���f�b�N�X�o�b�t�@���쐬

	HRESULT CreateConstantBuffer();	//�R���X�^���g�o�b�t�@���쐬

	HRESULT LoadTexture(std::string fineName);			//�e�N�X�`�������[�h


	//--------Draw�֐�����Ă΂��֐�--------

	void PassDataToCB(DirectX::XMMATRIX worldMatrix);	//�R���X�^���g�o�b�t�@�Ɋe�����n��
	void SetBufferToPipeline();							//�e�o�b�t�@���p�C�v���C���ɃZ�b�g

};
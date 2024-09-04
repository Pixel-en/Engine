#pragma once
#include <d3d11.h>
#include <assert.h>	//����җp�̃f�o�b�O

enum SHADER_TYPE {
	SHADER_2D,
	SHADER_3D,
	SHADER_MAX,
};

#define SAFE_DELETE(p) if(p != nullptr){ delete p; p = nullptr;}
#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}

//�����J
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

const int WINDOW_WIDTH = 800;  //�E�B���h�E�̕�
const int WINDOW_HEIGHT = 600; //�E�B���h�E�̍���


namespace Direct3D
{

	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pContext;

	//������
	HRESULT Initialize(int winW, int winH, HWND hWnd);

	//�V�F�[�_�[����
	HRESULT InitShader();
	HRESULT InitShader3D();
	HRESULT InitShader2D();

	void SetShader(SHADER_TYPE type);

	//�`��J�n
	void BeginDraw();

	//�`��I��
	HRESULT EndDraw();

	//���
	void Release();
};
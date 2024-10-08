#include "Input.h"

namespace Input
{
	//�L�[�{�[�h
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256] = { 0 };
	BYTE prevKeyState[256];    //�O�t���[���ł̊e�L�[�̏��

	//�}�E�X
	LPDIRECTINPUTDEVICE8 pMouDevice = nullptr;
	DIMOUSESTATE mouseState;
	DIMOUSESTATE prevmouseState;

	XMVECTOR mousePosition;

	HRESULT Initialize(HWND hWnd)
	{
		HRESULT hr=S_OK;

		hr = DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);

		if (FAILED(hr)) {
			MessageBox(NULL, L"�_�C���N�g�C���v�b�g�̍쐬�Ɏ��s���܂���", L"�G���[", MB_OK);
		}

		//�L�[�{�[�h�̏���
		hr = pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
		
		if (FAILED(hr)) {
			MessageBox(NULL, L"�L�[�{�[�h�̍쐬�Ɏ��s���܂���", L"�G���[", MB_OK);
		}

		//�}�E�X�̏���
		hr = pDInput->CreateDevice(GUID_SysMouse, &pMouDevice, nullptr);
		pMouDevice->SetDataFormat(&c_dfDIMouse);
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

		if (FAILED(hr)) {
			MessageBox(NULL, L"�}�E�X�̍쐬�Ɏ��s���܂���", L"�G���[", MB_OK);
		}

		return hr;
	}

	void Update()
	{
		memcpy(&prevKeyState, &keyState, sizeof(keyState));

		pKeyDevice->Acquire();
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);	//�����ŏ�Ԃ�����


		memcpy(&prevmouseState, &mouseState, sizeof(mouseState));
		pMouDevice->Acquire();
		pMouDevice->GetDeviceState(sizeof(mouseState),&mouseState);
	}

	bool IsKey(int keyCode)
	{
		if (keyState[keyCode] & 0x80)	//�r�b�g�̉��Z�q���Ă郈
		{
			return true;
		}
		return false;
	}

	bool IsKeyDown(int keyCode)
	{
		if (IsKey(keyCode) && keyState[keyCode] != prevKeyState[keyCode])
		{
			return true;
		}
		return false;
	}

	bool IsKeyUp(int keyCode)
	{
		if (!IsKey(keyCode) && keyState[keyCode] != prevKeyState[keyCode])
		{
			return true;
		}
		return false;
	}

	//�}�E�X
	bool IsMouse(int buttonCode)
	{
		if (mouseState.rgbButtons[buttonCode] & 0x80)	//�r�b�g�̉��Z�q���Ă郈
		{
			return true;
		}
		return false;
	}

	bool IsMouseDown(int buttonCode)
	{
		if (IsMouse(buttonCode) && mouseState.rgbButtons[buttonCode] != prevmouseState.rgbButtons[buttonCode])
		{
			return true;
		}
		return false;
	}

	bool IsMouseUp(int buttonCode)
	{
		if (!IsMouse(buttonCode) && mouseState.rgbButtons[buttonCode] != prevmouseState.rgbButtons[buttonCode])
		{
			return true;
		}
		return false;
	}

	XMVECTOR GetMousePosition()
	{
		return mousePosition;
	}

	void SetMousePosition(int x, int y)
	{
		mousePosition = XMVectorSet((float)x, (float)y, 0, 0);
	}

	void Release()
	{
		SAFE_RELEASE(pDInput);
		SAFE_RELEASE(pKeyDevice);
		SAFE_RELEASE(pMouDevice);
	}

}
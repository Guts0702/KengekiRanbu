#include "Header.h"
#include "Sengen.h"

LPDIRECTINPUTDEVICE8 pKeyDevice = NULL;
LPDIRECTINPUT8 pDinput = NULL;

static HRESULT hr;

KEYSTATE Key[KEYMAX];

int PreKey[KEYMAX] = { 0 };

int KeyState[5] = { 0 };

void KeyCheck(int VK, KEYKIND st) {
	if ((GetKeyState(VK) & 0x8000) != 0) {
		if (PreKey[st] == 0) {
			Key[st] = PUSH;
		}
		else {
			Key[st] = ON;
		}
		PreKey[st] = 1;
	}
	else {
		if (PreKey[st] == 0) {
			Key[st] = OFF;
		}
		else {
			Key[st] = RELEASE;
		}
		PreKey[st] = 0;
	}
}
/**
*制御処理
*/
HRESULT InitDinput(HWND hWnd) {

	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDinput, NULL)))
	{
		return hr;
	}
	if (FAILED(hr = pDinput->CreateDevice(GUID_SysKeyboard,
		&pKeyDevice, NULL)))
	{
		return hr;
	}
	if (FAILED(hr = pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return hr;
	}
	if (FAILED(hr = pKeyDevice->SetCooperativeLevel(
		hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return hr;
	}
	pKeyDevice->Acquire();
	return S_OK;
}
// ゲームシーンの制御関数
void GameScene()
{
	// キーのチェック関数群
	KeyCheck(VK_LEFT, LEFT);
	KeyCheck(VK_RIGHT, RIGHT);
	KeyCheck(VK_UP, UP);
	KeyCheck(VK_DOWN, DOWN);
	KeyCheck(VK_SPACE, SPACE);
	KeyCheck('A', A);
	KeyCheck('S', S);
	KeyCheck('D', D);
	KeyCheck('F', F);
}
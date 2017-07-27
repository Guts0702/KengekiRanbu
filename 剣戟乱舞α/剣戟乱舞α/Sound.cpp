#include<dsound.h>
#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>
#include"Sub.h"
#include"Sound.h"

#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dsound.lib")
#pragma comment(lib,"winmm.lib")


LPDIRECTSOUND8  pDS8 = NULL;


bool Soundinit(HWND hWnd)
{
	HRESULT ret;

	//COMの初期化
	CoInitialize(NULL);

	//DirectSound8を作成
	ret = DirectSoundCreate8(NULL, &pDS8, NULL);
	if (FAILED(ret))
	{
//		DEBUG("サウンドオブジェクト作成失敗\n");
		return FALSE;
	}

	//強調モード
	ret = pDS8->SetCooperativeLevel(hWnd, DSSCL_EXCLUSIVE | DSSCL_PRIORITY);
	if (FAILED(ret))
	{
//		DEBUG("強調レベル設定失敗\n");
		return FALSE;
	}
 }

void SoundLoad()
{
	
};

void Soundplay()
{

};

void SoundRelease()
{

};

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

	//COM�̏�����
	CoInitialize(NULL);

	//DirectSound8���쐬
	ret = DirectSoundCreate8(NULL, &pDS8, NULL);
	if (FAILED(ret))
	{
//		DEBUG("�T�E���h�I�u�W�F�N�g�쐬���s\n");
		return FALSE;
	}

	//�������[�h
	ret = pDS8->SetCooperativeLevel(hWnd, DSSCL_EXCLUSIVE | DSSCL_PRIORITY);
	if (FAILED(ret))
	{
//		DEBUG("�������x���ݒ莸�s\n");
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

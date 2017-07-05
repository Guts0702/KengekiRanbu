#ifndef HEADER
#define HEADER

#include <windows.h>
#include <d3dx9.h>
#include <dinput.h>

#define TITLE 	TEXT("Step4")
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define DISPLAY_WIDTH 1920
#define DISPLAY_HIGHT 1080
#define MOVE_SPEED 10.f
#define JUMP_POWER -27.f
#define GRAVITY 2.0f
#define BGMoveSpeed 7.f

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")    
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "Dinput8.lib")

#define SAFE_RELEASE(p) {if(p){(p)->Release(); (p)=NULL;}}

struct PLAYER_STATE
{
	float x, y, scale;
};

struct BACKGROUND_STATE
{
	float x, y, Width, Height;
};

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

enum TEXTURE
{
	BACKGROUND_TEX,
	BACKGROUND2_TEX,
	PLAYER_TEX,
	ZANGEKI_TEX,
	ZANGEKI2_TEX,
	KIRISAGE_TEX,
	KIRINUKE_TEX,
	TEXMAX
};

enum KEYSTATE
{
	PUSH,
	RELEASE,
	ON,
	OFF
};

enum KEYKIND
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	SPACE,
	A,
	S,
	D,
	F,
	KEYMAX
};

//Directx関係----------------------------
extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為のポインタ配列
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス
												//---------------------------------------

extern LPDIRECTINPUTDEVICE8 pKeyDevice;
extern LPDIRECTINPUT8 pDinput;

extern KEYSTATE Key[KEYMAX];

#endif

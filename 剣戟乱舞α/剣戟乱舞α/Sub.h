#ifndef MAIN
#define MAIN

#define SAFE_RELEASE(p){if(p){(p)->Release();(p)=NULL;}}

#include<windows.h>
#include<d3dx9.h>

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

struct PLAYER_STATE
{
	float x, y, scale;
};

enum TEXTURE
{
	BACKGROUND_TEX,
	PLAYER_TEX,
	PLAYER_LEFT_TEX,
	BACKGROUND2_TEX,
	ENEMY_TEX,
	ENEMY2_TEX,
	life_TEX,
	combo_TEX,
	MAP_GROUND_TEX,
	ZANGEKI_TEX,
	ZANGEKI_LEFT_TEX,
	TEXMAX
};

//キーの状態
enum KEYSTATE
{
	PUSH,
	RELEASE,
	ON,
	OFF
};

//キーの種類
enum KEYKIND
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	FIRE,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	SPACE,
	ESC,
	LSHIFT,
	RSHIFT,
	ESCAPE,
	KEYMAX
};

extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為の配列
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス

#endif
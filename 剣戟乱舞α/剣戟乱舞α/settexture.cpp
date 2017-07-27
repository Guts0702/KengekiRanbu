#include<Windows.h>
#include<d3dx9.h>
#include"Sub.h"
#include"Player.h"

void settexture()
{
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

void set()   //読み込む画像の名前
{
	//頂点に入れるデータを設定
	g_pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		TEXT("壁紙2.png"),
		&g_pTexture[BACKGROUND_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		TEXT("クリア.png"),
		&g_pTexture[BACKGROUND2_TEX]);

	// マップチップの読み込み
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"瓦.png",
		&g_pTexture[MAP_GROUND_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("player.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[PLAYER_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("player左.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[PLAYER_LEFT_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("敵a統合.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[ENEMY_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("ハシュマル.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[ENEMY2_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("ライフ.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[life_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("時間.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[combo_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("zangeki.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[ZANGEKI_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("zangeki左.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[ZANGEKI_LEFT_TEX]);
}
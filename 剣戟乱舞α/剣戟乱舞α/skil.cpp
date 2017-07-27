#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>
#include<dinput.h>
#include"Sub.h"
#include"skil.h"
#include"Player.h"

PLAYER_STATE		g_Zangeki = { 0, 0, 64.f };

bool zangekiflag = false;

/*斬撃の速度*/
int zx = 0;
int zy = 0;

/*斬撃にも方向を作る*/
bool zangekiLeft = false;

/*斬撃が消えたらもう一発撃てるように*/
bool zangekiactiv = true;

/*作り直す時ここを消せるように*/
extern float g_scx;
extern float g_scy;
extern float x;
extern float y;
extern float g_scx;
extern float g_scy;

extern PLAYER_STATE g_Player;

void skildraw()
{
	/*Aボタンが押されたら、斬撃がとぶ*/
	if (zangekiflag == true)
	{
		zangekiactiv = false;

		CUSTOMVERTEX Zangeki[4]
		{
			{ g_Zangeki.x - g_Zangeki.scale + zx - g_scx, g_Zangeki.y - g_Zangeki.scale + zy - g_scy,       1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ g_Zangeki.x + g_Zangeki.scale + zx - g_scx, g_Zangeki.y - g_Zangeki.scale + zy - g_scy,       1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ g_Zangeki.x + g_Zangeki.scale + zx - g_scx, g_Zangeki.y + g_Zangeki.scale * 1.5 + zy - g_scy, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ g_Zangeki.x - g_Zangeki.scale + zx - g_scx, g_Zangeki.y + g_Zangeki.scale * 1.5 + zy - g_scy, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};

		/*もし左に向いていればplayerが左向きになるように*/
		if (zangekiLeft)
		{
			g_pD3Device->SetTexture(0, g_pTexture[ZANGEKI_LEFT_TEX]);
		}

		/*その逆*/
		else
		{
			g_pD3Device->SetTexture(0, g_pTexture[ZANGEKI_TEX]);
		}

		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Zangeki, sizeof(CUSTOMVERTEX));
	}
	else
	{
		/*ここで斬撃の位置を一旦初期化して、そこにプレイヤーの座標を入れている。*/
		zx = 0;
		zy = 0;
		/*プレイヤーの場所に服従させているのでプレイヤーと接触しても敵が消える。*/
		g_Zangeki.x = g_Player.x + x + g_scx;
		g_Zangeki.y = g_Player.y + y + g_scy;
	}

	/*画面外に行くと消える*/
	if (g_Zangeki.x + g_Zangeki.scale + zx - g_scx >= 1280)
	{
		if (zangekiflag == true)
		{
		   zangekiflag = false;
		   zangekiactiv = true;
		}
	}

	/*画面外左に行くと消える*/
	else if (g_Zangeki.x + g_Zangeki.scale + zx - g_scx <= 0)
	{
		if (zangekiflag == true)
		{
			zangekiflag = false;
			zangekiactiv = true;
		}
	}

}

void skilcontrol()
{
	/*もしAボタンが押されたら斬撃が発動*/
	if (zangekiflag == true)
	{
		if (zangekiLeft)
		{
			zx -= 25;
		}
		else
		{
			zx += 25;
		}
	}

}


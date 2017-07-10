#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>
#include<dinput.h>
#include"Sub.h"
#include"skil.h"
#include"Player.h"

PLAYER_STATE		g_Zangeki = { 0, 0, 64.f };

bool zangekiflag = false;

int zx = 0;
int zy = 0;

extern float g_scx;
extern float g_scy;
extern float x;
extern float y;
extern float g_scx;
extern float g_scy;

extern PLAYER_STATE g_Player;

extern int tipxy(float, float);

void skildraw()
{
	/*Aボタンが押されたら、斬撃がとぶ*/
	if (zangekiflag == true)
	{
		CUSTOMVERTEX Zangeki[4]
		{
			{ g_Zangeki.x - g_Zangeki.scale + zx - g_scx, g_Zangeki.y - g_Zangeki.scale + zy - g_scy,       1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ g_Zangeki.x + g_Zangeki.scale + zx - g_scx, g_Zangeki.y - g_Zangeki.scale + zy - g_scy,       1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ g_Zangeki.x + g_Zangeki.scale + zx - g_scx, g_Zangeki.y + g_Zangeki.scale * 1.5 + zy - g_scy, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ g_Zangeki.x - g_Zangeki.scale + zx - g_scx, g_Zangeki.y + g_Zangeki.scale * 1.5 + zy - g_scy, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};

		g_pD3Device->SetTexture(0, g_pTexture[ZANGEKI_TEX]);
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

	if (g_Zangeki.x + g_Zangeki.scale + zx - g_scx >= 1280)
	{
		if (zangekiflag == true)
		{
		   zangekiflag = false;
		}
	}

}

void skilcontrol()
{
	if (zangekiflag == true)
	{
		zx += 25;
	}
}


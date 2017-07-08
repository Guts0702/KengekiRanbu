#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>
#include<dinput.h>
#include"Sub.h"
#include"Player.h"

PLAYER_STATE		g_Player = { 150.f, 530.f, 64.f};

#define SCROOLMAX 1000
#define SCROOL 280

static float x = 0;
static float y = 0;
static float Mspeed = 5.0;
static bool ueflag = false;
static bool sitaflag = false;
static bool AtattaFlag = false;

static int cx = 320 - 16;
static float cy = 448.0f;
static float sy = 0.0f;

static float jumpPower = 43;
static float Gravity = 1;
static float Gravity2 = 15;
static float Time = 0;
static bool IsJump = false;

float g_scx = 0;
float g_scy = 0;

int tipxy(float, float);
void KeyCheckDinput(KEYSTATE* Key, int);

void Playerdraw()
{

	CUSTOMVERTEX player[]
	{
		{ g_Player.x - g_Player.scale + x, g_Player.y - g_Player.scale + y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Player.x + g_Player.scale + x, g_Player.y - g_Player.scale + y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Player.x + g_Player.scale + x, g_Player.y + g_Player.scale + y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Player.x - g_Player.scale + x, g_Player.y + g_Player.scale + y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[PLAYER_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
}

void Playercontrol()
{
	KEYSTATE key[256];
	KeyCheckDinput(&key[DIK_LEFT], DIK_LEFT);
	KeyCheckDinput(&key[DIK_RIGHT], DIK_RIGHT);
	KeyCheckDinput(&key[DIK_UP], DIK_UP);
	KeyCheckDinput(&key[DIK_DOWN], DIK_DOWN);
	KeyCheckDinput(&key[DIK_Z], DIK_Z);
	KeyCheckDinput(&key[DIK_A], DIK_A);
	KeyCheckDinput(&key[DIK_W], DIK_W);
	KeyCheckDinput(&key[DIK_SPACE], DIK_SPACE);

	/*重力*/

	if (tipxy(g_Player.x + g_Player.scale + x + g_scx, g_Player.y + g_Player.scale + y + g_scy) != 1 &&
		tipxy(g_Player.x - g_Player.scale + x + g_scx, g_Player.y + g_Player.scale + y + g_scy) != 1)
	{
		y += Gravity2;

	}

	/*jumpします。*/

	

	if (IsJump)
	{

		y -= (jumpPower - Time * Gravity);
		Time++;

		//上行ったとき
		if (tipxy(g_Player.x + g_Player.scale + x + g_scx, g_Player.y - g_Player.scale + y + g_scy) != 0 ||
			tipxy(g_Player.x - g_Player.scale + x + g_scx, g_Player.y - g_Player.scale + y + g_scy) != 0)
		{
			IsJump = false;
			Time = 0;
		}

		if (tipxy(g_Player.x + g_Player.scale + x + g_scx, g_Player.y + g_Player.scale + y + g_scy) != 0 &&
			tipxy(g_Player.x - g_Player.scale + x + g_scx, g_Player.y + g_Player.scale + y + g_scy) != 0)
		{
			IsJump = false;
			Time = 0;
		}
	}
	else
	{
		if (key[DIK_SPACE] == PUSH)
		{
			IsJump = true;
		}
	}


	/*端に行ったら操作できないように*/

	if (tipxy(g_Player.x + g_Player.scale + x + g_scx, g_Player.y + y + g_scy) != 1)
	{
		if (key[DIK_LEFT] == ON)
		{
			float tmpx = g_Player.x;
			float tmpy = g_Player.y;
			float tmpMoveX = x;


			if (tipxy(tmpx - g_Player.scale + x + g_scx, tmpy + y + g_scy) == 0)
			{
				tmpMoveX = x - 5;

				if (SCROOL > (g_Player.x + g_Player.scale + tmpMoveX))
				{
					g_scx -= 5;
				}
				else
				{
					x = tmpMoveX;
				}
			}
		}
	}

	if (tipxy(g_Player.x + g_Player.scale + x + g_scx, g_Player.y + y + g_scy) != 1)
	{
		if (key[DIK_RIGHT] == ON)
		{
			float tmpx = g_Player.x;
			float tmpy = g_Player.y;
			float tmpMoveX = x;


			if (tipxy(tmpx + g_Player.scale + x + g_scx, tmpy + y + g_scy) == 0)
			{
				tmpMoveX = x + 5;

				if (SCROOLMAX <= (g_Player.x + g_Player.scale + tmpMoveX))
				{
					g_scx += 5;
				}
				else
				{
					x = tmpMoveX;
				}
			}
		}
	}
}
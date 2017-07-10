#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>
#include<dinput.h>
#include"Sub.h"
#include"Enemy.h"

#define ENEMY_MAX 5

PLAYER_STATE		g_enemy = { 1150.f, 500.f, 64.f };

extern float g_scx;
extern float g_scy;
static float ex[ENEMY_MAX] = { 0, 200, 400, 600, 800 };
static float ey[ENEMY_MAX] = { 0, 0, 0, 0, 0 };
static float EjumpPower = 15;
static float ETime[ENEMY_MAX] = { 0, 3, 6, 7, 2 };
static float EGravity = 1;
static bool EsJump = false;

static float tu[2] = { 0.5f, 1.0f};
static float tv[5] = {0.0f,0.25f,0.5f,0.75f,1.f};

static int index = 0;
float time = 0;

int tipxy(float, float);

void Enemydraw()
{
	time++;
	if (time >= 10)
	{
		time = 0;
		index++;
		if (index > 3)
		{
			index = 0;
		}
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{

		CUSTOMVERTEX enemy[]
		{
			{ g_enemy.x - g_enemy.scale + ex[i] - g_scx, g_enemy.y - g_enemy.scale + ey[i] - g_scy, 1.f, 1.f, 0xFFFFFFFF, tu[0],tv[index] },
			{ g_enemy.x + g_enemy.scale + ex[i] - g_scx, g_enemy.y - g_enemy.scale + ey[i] - g_scy, 1.f, 1.f, 0xFFFFFFFF, tu[1],tv[index] },
			{ g_enemy.x + g_enemy.scale + ex[i] - g_scx, g_enemy.y + g_enemy.scale + ey[i] - g_scy, 1.f, 1.f, 0xFFFFFFFF, tu[1],tv[index+1] },
			{ g_enemy.x - g_enemy.scale + ex[i] - g_scx, g_enemy.y + g_enemy.scale + ey[i] - g_scy, 1.f, 1.f, 0xFFFFFFFF, tu[0],tv[index+1] }
		};

		g_pD3Device->SetTexture(0, g_pTexture[ENEMY_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
	}
}

void Enemycontrol()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		/*�G�̋���*/
		if (EsJump == false)
		{
			ex[i] -= 1;
			ey[i] -= (EjumpPower - ETime[i] * EGravity);
			ETime[i]++;
			if (ey > 0)  /*�������Ă���Ƃ�����Ȃ��ƒ��n������s��Ȃ��B*/
			{
				if (tipxy(g_enemy.x + g_enemy.scale + ex[i], g_enemy.y + g_enemy.scale + ey[i]) != 0 &&
					tipxy(g_enemy.x - g_enemy.scale + ex[i], g_enemy.y + g_enemy.scale + ey[i]) != 0)
				{
					ETime[i] = 0;
				}
			}
		}
	}
}

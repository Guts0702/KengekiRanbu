#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>
#include<dinput.h>
#include"Sub.h"
#include"skil.h"
#include"Player.h"

PLAYER_STATE		g_Zangeki = { 0, 0, 64.f };

bool zangekiflag = false;

/*�a���̑��x*/
int zx = 0;
int zy = 0;

/*�a���ɂ����������*/
bool zangekiLeft = false;

/*�a����������������ꔭ���Ă�悤��*/
bool zangekiactiv = true;

/*��蒼����������������悤��*/
extern float g_scx;
extern float g_scy;
extern float x;
extern float y;
extern float g_scx;
extern float g_scy;

extern PLAYER_STATE g_Player;

void skildraw()
{
	/*A�{�^���������ꂽ��A�a�����Ƃ�*/
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

		/*�������Ɍ����Ă����player���������ɂȂ�悤��*/
		if (zangekiLeft)
		{
			g_pD3Device->SetTexture(0, g_pTexture[ZANGEKI_LEFT_TEX]);
		}

		/*���̋t*/
		else
		{
			g_pD3Device->SetTexture(0, g_pTexture[ZANGEKI_TEX]);
		}

		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Zangeki, sizeof(CUSTOMVERTEX));
	}
	else
	{
		/*�����Ŏa���̈ʒu����U���������āA�����Ƀv���C���[�̍��W�����Ă���B*/
		zx = 0;
		zy = 0;
		/*�v���C���[�̏ꏊ�ɕ��]�����Ă���̂Ńv���C���[�ƐڐG���Ă��G��������B*/
		g_Zangeki.x = g_Player.x + x + g_scx;
		g_Zangeki.y = g_Player.y + y + g_scy;
	}

	/*��ʊO�ɍs���Ə�����*/
	if (g_Zangeki.x + g_Zangeki.scale + zx - g_scx >= 1280)
	{
		if (zangekiflag == true)
		{
		   zangekiflag = false;
		   zangekiactiv = true;
		}
	}

	/*��ʊO���ɍs���Ə�����*/
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
	/*����A�{�^���������ꂽ��a��������*/
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


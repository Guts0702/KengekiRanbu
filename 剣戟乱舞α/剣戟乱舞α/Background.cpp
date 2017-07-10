#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>

#include"Sub.h"
#include"Background.h"

#define MAP_HEIGHT 15
#define MAP_WIDTH  60
#define TIPSIZE 64.f

static int map[MAP_HEIGHT][MAP_WIDTH];

extern float g_scx;
extern float g_scy;


int tipxy(float px, float py)
{
	int pmx = (int)px / TIPSIZE;
	int pmy = (int)py / TIPSIZE;
	return map[pmy][pmx];
}

void Backgrounddraw()
{
	CUSTOMVERTEX backGround[]
	{
		{ 0.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	CUSTOMVERTEX backGround2[]
	{
		{ 0.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	// 瓦のチップの頂点情報
	CUSTOMVERTEX g_mapTip1[] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ TIPSIZE, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
		{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
		{ 0.0f, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	// 白壁のチップの頂点情報
	CUSTOMVERTEX g_mapTip2[] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
		{ TIPSIZE, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	};

	g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	/*maptipの描画*/
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			CUSTOMVERTEX maptip[4];
			switch (map[j][i])
			{
			case 0:
				break;
			case 1:
				for (int k = 0; k < 4; k++)
				{
					maptip[k] = g_mapTip1[k];     //上で作ったmaptip[4]に最初に作った氷の情報を入れている
					maptip[k].x += TIPSIZE * i - g_scx;  //かけることによって、置く場所の座標を決めている
					maptip[k].y += TIPSIZE * j - g_scy;
				}
				g_pD3Device->SetTexture(0, g_pTexture[MAP_GROUND_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, maptip, sizeof(CUSTOMVERTEX));
				break;
			case 2:
				for (int k = 0; k < 4; k++)
				{
					maptip[k] = g_mapTip2[k];
					maptip[k].x += TIPSIZE * i - g_scx;
					maptip[k].y += TIPSIZE * j - g_scy;
				}
				g_pD3Device->SetTexture(0, g_pTexture[MAP_GROUND_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, maptip, sizeof(CUSTOMVERTEX));
				break;
			}
		}
	}
}

/*maptipの読み込み*/
void MapLoad(const char* mapdata)
{
	FILE*  fp;
	fopen_s(&fp, mapdata, "r");

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			fscanf_s(fp, "%d,", &map[i][j], _countof(map));
		}
	}
	fclose(fp);
}

#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>
#include<dinput.h>
#include"Sub.h"
#include"UI.h"

#define UI_MAX 5

static float ux[UI_MAX] = { 0, 50, 100, 150, 200 };
static float uy[UI_MAX] = { 0, 0, 0, 0, 0 };

void UIdraw()
{
	for (int i = 0; i < 5; i++)
	{
		CUSTOMVERTEX life[] = 
		{
			{ 50.f + ux[i],  0.f + uy[i], 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ 50.f + ux[i], 50.f + uy[i], 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{  0.f + ux[i], 50.f + uy[i], 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f },
			{  0.f + ux[i],  0.f + uy[i], 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f }
		};

		g_pD3Device->SetTexture(0, g_pTexture[life_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, life, sizeof(CUSTOMVERTEX));
	}
}
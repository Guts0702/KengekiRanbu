#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>
#include<dinput.h>
#include"Sub.h"
#include"UI.h"


void UIdraw()
{
	CUSTOMVERTEX life[] = {
		{0.f ,0.f , 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{100.f,0.f , 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{100.f,100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{0.f ,100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	g_pD3Device->SetTexture(0, g_pTexture[life_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, life, sizeof(CUSTOMVERTEX));
}


//void UIcontrol()
#include "Header.h"
#include "Sengen.h"

void Brender() {
	CUSTOMVERTEX backGround[4]
	{
		{ g_backGround.x, g_backGround.y, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_backGround.Width, g_backGround.y, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_backGround.Width, g_backGround.Height, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_backGround.x, g_backGround.Height, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX backGround2[4]
	{
		{ g_backGround.Width, g_backGround.y, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_backGround.Width + 1920.f, g_backGround.y, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_backGround.Width + 1920.f, g_backGround.Height, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_backGround.Width, g_backGround.Height, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND2_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround2, sizeof(CUSTOMVERTEX));
}
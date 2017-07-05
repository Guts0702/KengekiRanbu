#include "Header.h"
#include "Sengen.h"

void Srender() {
	CUSTOMVERTEX Zangeki[4]
	{
		{ g_Zangeki.x - g_Zangeki.scale, g_Zangeki.y - g_Zangeki.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Zangeki.x + g_Zangeki.scale, g_Zangeki.y - g_Zangeki.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Zangeki.x + g_Zangeki.scale, g_Zangeki.y + g_Zangeki.scale * 1.5, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Zangeki.x - g_Zangeki.scale, g_Zangeki.y + g_Zangeki.scale * 1.5, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX Zangeki2[4]
	{
		{ g_Zangeki2.x - g_Zangeki2.scale, g_Zangeki2.y - g_Zangeki2.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Zangeki2.x + g_Zangeki2.scale, g_Zangeki2.y - g_Zangeki2.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Zangeki2.x + g_Zangeki2.scale, g_Zangeki2.y + g_Zangeki2.scale * 1.5, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Zangeki2.x - g_Zangeki2.scale, g_Zangeki2.y + g_Zangeki2.scale * 1.5, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX Kirinuke[4]
	{
		{ g_Kirinuke.x - g_Kirinuke.scale, g_Kirinuke.y - g_Kirinuke.scale * 2.0, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Kirinuke.x + g_Kirinuke.scale, g_Kirinuke.y - g_Kirinuke.scale * 2.0, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Kirinuke.x + g_Kirinuke.scale, g_Kirinuke.y + g_Kirinuke.scale * 1.5, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Kirinuke.x - g_Kirinuke.scale, g_Kirinuke.y + g_Kirinuke.scale * 1.5, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX drawZangeki[4];
	for (int i = 0; i < 4; i++) {
		drawZangeki[i] = Zangeki[i];
		drawZangeki[i].x += g_Zangeki.x;
		drawZangeki[i].y += g_Zangeki.y;
	}

	CUSTOMVERTEX drawZangeki2[4];
	for (int i = 0; i < 4; i++) {
		drawZangeki2[i] = Zangeki2[i];
		drawZangeki2[i].x += g_Zangeki2.x;
		drawZangeki2[i].y += g_Zangeki2.y;
	}

	CUSTOMVERTEX drawKirinuke[4];
	for (int i = 0; i < 4; i++) {
		drawKirinuke[i] = Kirinuke[i];
		drawKirinuke[i].x += g_Kirinuke.x;
		drawKirinuke[i].y += g_Kirinuke.y;
	}

	if (AskillFlag == true) {
		g_pD3Device->SetTexture(0, g_pTexture[ZANGEKI_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawZangeki, sizeof(CUSTOMVERTEX));
	}
	if (Askill2Flag == true) {
		g_pD3Device->SetTexture(0, g_pTexture[ZANGEKI2_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawZangeki2, sizeof(CUSTOMVERTEX));
	}
	if (KFlag == true) {
		g_pD3Device->SetTexture(0, g_pTexture[KIRINUKE_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawKirinuke, sizeof(CUSTOMVERTEX));
		Kcount++;
		ControlFlag = false;
	}
}
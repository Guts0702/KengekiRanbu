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

void Prender() {
	CUSTOMVERTEX player[4]
	{
		{ g_Player.x - g_Player.scale, g_Player.y - g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Player.x + g_Player.scale, g_Player.y - g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Player.x + g_Player.scale, g_Player.y + g_Player.scale * 1.5, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Player.x - g_Player.scale, g_Player.y + g_Player.scale * 1.5, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	CUSTOMVERTEX drawplayer[4];
	for (int i = 0; i < 4; i++) {
		drawplayer[i] = player[i];
		drawplayer[i].x += g_Player.x;
		drawplayer[i].y += g_Player.y;
	}

	g_pD3Device->SetTexture(0, g_pTexture[PLAYER_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawplayer, sizeof(CUSTOMVERTEX));

}

void Erender()
{

}

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
		{ g_Kirinuke.x - g_Kirinuke.scale, g_Kirinuke.y - g_Kirinuke.scale * 0.3, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Kirinuke.x + g_Kirinuke.scale, g_Kirinuke.y - g_Kirinuke.scale * 0.3, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Kirinuke.x + g_Kirinuke.scale, g_Kirinuke.y + g_Kirinuke.scale * 0.4, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Kirinuke.x - g_Kirinuke.scale, g_Kirinuke.y + g_Kirinuke.scale * 0.4, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
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
	if (g_Player.x <= 820)
	{
		if (KFlag == true) {
			g_pD3Device->SetTexture(0, g_pTexture[KIRINUKE_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawKirinuke, sizeof(CUSTOMVERTEX));
			Kcount++;
			ControlFlag = false;
		}
		if (Kcount >= 30)
		{
			KFlag = false;
			ControlFlag = true;
			Kcount = 0;
		}
	}
}
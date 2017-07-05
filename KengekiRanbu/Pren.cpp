#include "Header.h"
#include "Sengen.h"

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

	if (SskillFlag == false) {
		g_pD3Device->SetTexture(0, g_pTexture[PLAYER_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawplayer, sizeof(CUSTOMVERTEX));
	}
}
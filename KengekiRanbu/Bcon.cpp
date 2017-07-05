#include "Header.h"
#include "Sengen.h"

BACKGROUND_STATE g_backGround = { 0.f,0.f,1920.f,980.f };
BACKGROUND_STATE g_backGround2 = { g_backGround.Width,0.f,g_backGround.Width + 1560.f,980.f };

void Bcontrol()
{
	if (g_Player.x >= 600.f) {
		g_backGround.x -= BGMoveSpeed;
		g_backGround.Width -= BGMoveSpeed;
		if (g_backGround.Width <= 0.f)
		{
			g_backGround.x = 0.f;
			g_backGround.Width = 1920.f;
		}
	}
}
#include "Header.h"
#include "Sengen.h"

BACKGROUND_STATE g_backGround = { 0.f,0.f,1760.f,1130.f };
BACKGROUND_STATE g_backGround2 = { g_backGround.Width,0.f,g_backGround.Width + 1760.f,1130.f };

void Bcontrol()
{
	if (g_Player.x >= 600.f) {
		g_backGround.x -= BGMoveSpeed;
		g_backGround.Width -= BGMoveSpeed;
		if (g_backGround.Width <= 0.f)
		{
			g_backGround.x = 0.f;
			g_backGround.Width = 1760.f;
		}
	}
}
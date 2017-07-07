#include "Header.h"
#include "Sengen.h"

PLAYER_STATE g_Zangeki = { g_Player.x, g_Player.y, 40.f };
PLAYER_STATE g_Zangeki2 = { g_Player.x, g_Player.y, 40.f };
PLAYER_STATE g_Kirisage = { g_Player.x + 30.f, g_Player.y + 30.f, 40.f };
PLAYER_STATE g_Kirinuke = { g_Player.x - 30.f, g_Player.y, 200.f };

bool AskillFlag = false;
bool Askill2Flag = false;
bool SskillFlag = false;
bool KFlag = false;
int Askillcount = 0;
int Sskillcount = 0;
int Kcount = 0;

void Scontrol() {
	if (AskillFlag == true)
	{
		g_Zangeki.x += 12.f;
	}
	if (Askill2Flag == true)
	{
		g_Zangeki2.x += 12.f;
	}
	if (g_Player.x <= 520)
	{
		if (SskillFlag == true)
		{
			int Xcount = 0;
			KFlag = true;

			for (int i = 0; i < 100; i++) {
				Xcount++;
				if (Xcount >= 5)
				{
					g_Player.x += 2.f;
					SskillFlag = false;
				}
				if (g_Player.x >= 720.f)
				{
					break;
				}
			}
		}
	}
}
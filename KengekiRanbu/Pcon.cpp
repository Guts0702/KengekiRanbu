#include "Header.h"
#include "Sengen.h"

PLAYER_STATE g_Player = { 200.f, 250.f, 60.f };

bool jumpFlag = false;
bool skyFlag = false;
bool LeftFlag = false;
bool RightFlag = false;
bool ControlFlag = true;
float jump;
int Scount = 0;

void Pcontrol()
{
	if (ControlFlag == true)
	{
		if (Key[LEFT] == ON)
		{
			RightFlag = false;
			if (LeftFlag == false)
			{
				g_Player.x -= MOVE_SPEED;
				SskillFlag = false;
				if (Key[LEFT] == PUSH || Key[LEFT] == ON)
				{
					if (g_Player.x <= 100)
					{
						LeftFlag = true;
					}
				}
			}
		}
		if (Key[RIGHT] == ON)
		{
			LeftFlag = false;
			if (RightFlag == false)
			{
				g_Player.x += MOVE_SPEED;
				SskillFlag = false;
				if (Key[RIGHT] == PUSH || Key[RIGHT] == ON)
				{
					if (g_Player.x >= 670)
					{
						RightFlag = true;
					}
				}
			}
		}
		g_pD3Device->Present(NULL, NULL, NULL, NULL);
		if (Scount % 2 == 0) {
			if (g_Player.y == 250.f) {
				if (Askillcount >= 30) {
					if (Key[A] == ON)
					{
						g_Zangeki.x = g_Player.x;
						AskillFlag = true;
						Askillcount = 0;
						Scount++;
					}
				}
			}
		}
		if (Scount % 2 == 1) {
			if (g_Player.y == 250.f) {
				if (Askillcount >= 30) {
					if (Key[A] == ON)
					{
						g_Zangeki2.x = g_Player.x;
						Askill2Flag = true;
						Askillcount = 0;
						Scount++;
					}
				}
			}
		}
		if (g_Player.y == 250.f) {
			if (Sskillcount >= 30) {
				if (Key[S] == PUSH)
				{
					g_Kirinuke.x = g_Player.x;
					SskillFlag = true;
					Sskillcount = 0;
				}
			}
		}
		if (Key[SPACE] == PUSH)
			if (skyFlag != true)
			{
				jumpFlag = true;
				skyFlag = true;
				jump = JUMP_POWER;
			}
		//ジャンプ処理中にこの処理に入る
		if (jumpFlag == true)
		{
			//初速度から重力を引く
			jump += GRAVITY;
			//速度をプレイヤーの座標に入れる
			g_Player.y += jump;

			if (g_Player.y >= 250.f) {
				if (jumpFlag == true)
				{
					g_Player.y = 250.f;
					jumpFlag = false;
					skyFlag = false;
				}
			}
		}
	}
}

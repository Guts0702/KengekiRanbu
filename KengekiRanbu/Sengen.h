#ifndef SENGEN
#define SENGEN

extern BACKGROUND_STATE g_backGround;
extern BACKGROUND_STATE g_backGround;
extern PLAYER_STATE	g_Player;
extern PLAYER_STATE	g_Zangeki;
extern PLAYER_STATE	g_Zangeki2;
extern PLAYER_STATE	g_Kirinuke;

extern bool SskillFlag;
extern bool AskillFlag;
extern bool Askill2Flag;
extern bool KFlag;
extern bool ControlFlag;
extern int Askillcount;
extern int Sskillcount;
extern int Kcount;

void Prender();

void Brender();

void Erender();

void Srender();

void Pcontrol();

void Bcontrol();

void Econtrol();

void Scontrol();

void GameScene();

void KeyCheck(int VK, KEYKIND st);

HRESULT InitDinput(HWND hWnd);

#endif
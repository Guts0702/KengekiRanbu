#include<Windows.h>
#include<d3dx9.h>
#include<stdio.h>
#include<dinput.h>
#include"Sub.h"

#define TITLE TEXT ("kengekiα")
#define D3DFVF_CUSTOMVERTEX ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

#pragma comment(lib,"winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")

//Directx関係		構造体変数宣言
LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為の配列
IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
D3DDISPLAYMODE		  g_D3DdisplayMode;
IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス

void Render();
void settexture();
void ReleaseDiput();
void ReleaseKey();
void Playerdraw();
void Playercontrol();
void MapLoad(const char* mapdata);
void Backgrounddraw();
void Enemydraw();
void Enemycontrol();
void UIdraw();
void skildraw();
void skilcontrol();

HRESULT InitDinputKey(HWND);
HRESULT InitDinput();
void KeyCheckDinput(KEYSTATE*, int);

/*ウィンドウプロシージャ*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		switch (wp)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}

void FreeDx()
{
	for (int i = 0; i <= TEXMAX; i++)
	{
		SAFE_RELEASE(g_pTexture[i]);
	}
	SAFE_RELEASE(g_pD3Device);
	SAFE_RELEASE(g_pDirect3D);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInsta, LPSTR szStr, INT iCmdShow)
{

	WNDCLASS Wndclass;	//構造体タグ名を宣言
	HWND hWnd;
	MSG msg;

	//ウィンドウの設定
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = 0;
	Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = TITLE;

	RegisterClass(&Wndclass);	//ウィンドウ情報の登録

	//ウィンドウの作成
	hWnd = CreateWindow(
		TITLE,
		TITLE,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1280,
		720,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	if (!hWnd)return 0;

	//DirectX オブジェクトの生成
	g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	//ディスプレイモードの設定
	g_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &g_D3DdisplayMode);

	ZeroMemory(&g_D3dPresentParameters, sizeof(D3DPRESENT_PARAMETERS));
	g_D3dPresentParameters.BackBufferFormat = g_D3DdisplayMode.Format;
	g_D3dPresentParameters.BackBufferCount = 1;
	g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_D3dPresentParameters.Windowed = TRUE;

	//デバイスの作成
	g_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&g_D3dPresentParameters, &g_pD3Device);

	settexture();
	MapLoad("map.csv");

	//頂点に入れるデータを設定
	g_pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		TEXT("壁紙2.png"),
		&g_pTexture[BACKGROUND_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		TEXT("クリア.png"),
		&g_pTexture[BACKGROUND2_TEX]);

	// マップチップの読み込み
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"瓦.png",
		&g_pTexture[MAP_GROUND_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("player.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[PLAYER_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("敵a統合.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[ENEMY_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("ハシュマル.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[ENEMY2_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("ライフ.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[life_TEX]);

	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT("zangeki.png"),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[ZANGEKI_TEX]);


	InitDinput();
	InitDinputKey(hWnd);

	DWORD SyncOld = timeGetTime();		//	システム時間を取得
	DWORD SyncNow = timeGetTime();

	timeBeginPeriod(1);					//時間を細かく指定している　(1)=1000/1 
	ZeroMemory(&msg, sizeof(msg));		//&msgの初期化
	while (msg.message != WM_QUIT)		//WM_QUIT(終了)メッセージが来るまで継続
	{
		Sleep(1);						//高速で回らないように1ms(0.001秒)処理を遅らせている
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	//PeekMessageでメッセージが来ていないか確認して来ていたら入る
		{
			TranslateMessage(&msg);		//メッセージをProcが読めるように翻訳する
			DispatchMessage(&msg);		//メッセージをProcに送信している
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60) //	1秒間に60回この中に入るはず
			{
				//画面の消去
				g_pD3Device->Clear(0, NULL,
					D3DCLEAR_TARGET,
					D3DCOLOR_XRGB(0x00, 0x00, 0x00),
					1.0, 0);

				//描画の開始
				g_pD3Device->BeginScene();

				Backgrounddraw();
				Playerdraw();
				Enemydraw();
				UIdraw();
				skildraw();
				skilcontrol();
				Playercontrol();
				Enemycontrol();

				//描画の終了
				g_pD3Device->EndScene();
				//表示
				g_pD3Device->Present(NULL, NULL, NULL, NULL);

				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	ReleaseDiput();
	ReleaseKey();

	FreeDx();

	return (int)msg.wParam;
}
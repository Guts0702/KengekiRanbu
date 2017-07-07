#include "Header.h"
#include "Sengen.h"

//Directx関係----------------------------
LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為のポインタ配列
IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
D3DDISPLAYMODE		  g_D3DdisplayMode;
IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス
//---------------------------------------

/*
*描画処理
*/
void Render()
{
	//画面の消去
	g_pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//描画の開始
	g_pD3Device->BeginScene();

	Brender();
	Prender();
	Srender();

	//描画の終了
	g_pD3Device->EndScene();
	//表示
	g_pD3Device->Present(NULL, NULL, NULL, NULL);

	//頂点に入れるデータを設定
	g_pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
}

/**
*メッセージ処理
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}

VOID FreeDx()
{
	if (pKeyDevice)
	{
		pKeyDevice->Unacquire();
	}
	SAFE_RELEASE(pKeyDevice);
	SAFE_RELEASE(pDinput);
	SAFE_RELEASE(g_pD3Device);
	SAFE_RELEASE(g_pDirect3D);
}
/**
*メインルーチン
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,//←Windowsアプリケーションのメイン関数　previous→prev
	PSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	WNDCLASS Wndclass;
	MSG msg;

	//Windows情報の設定
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = TITLE;	//クラス名
									//Windowの登録
	RegisterClass(&Wndclass);
	//Windowの生成
	hWnd = CreateWindow(
		TITLE,								//ウィンドウのクラス名
		TITLE, 							//ウィンドウのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//ウィンドウスタイル
		CW_USEDEFAULT,						// ウィンドウの横方向の位置x
		CW_USEDEFAULT,						// ウィンドウの縦方向の位置y
		DISPLAY_WIDTH,							// Width（幅）
		DISPLAY_HIGHT,							// Height（高さ）
		NULL,
		NULL,
		hInstance,							// アプリケーションインスタンスのハンドル
		NULL
	);
	if (!hWnd) return 0;

	//DirectX オブジェクトの生成
	g_pDirect3D = Direct3DCreate9(
		D3D_SDK_VERSION);

	//Display Mode の設定
	g_pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		&g_D3DdisplayMode);

	ZeroMemory(&g_D3dPresentParameters,
		sizeof(D3DPRESENT_PARAMETERS));
	g_D3dPresentParameters.BackBufferFormat = g_D3DdisplayMode.Format;
	g_D3dPresentParameters.BackBufferCount = 1;
	g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_D3dPresentParameters.Windowed = TRUE;

	//デバイスを作る
	g_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&g_D3dPresentParameters, &g_pD3Device);

	//描画設定
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Back.png",
		&g_pTexture[BACKGROUND_TEX]);
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"Back2.png",
		&g_pTexture[BACKGROUND2_TEX]);
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"slime.png",
		&g_pTexture[PLAYER_TEX]);
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"result_24.png",
		&g_pTexture[ZANGEKI_TEX]);
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"result_24 2.png",
		&g_pTexture[ZANGEKI2_TEX]);
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"result_31.png",
		&g_pTexture[KIRINUKE_TEX]);

	DWORD SyncOld = timeGetTime();	//	システム時間を取得
	DWORD SyncNow;//←「今の」はcurrent、「次の」はnext、「前の」はprevious、「後の」はold。

	InitDinput(hWnd);

	timeBeginPeriod(1);

	ZeroMemory(&msg, sizeof(msg));

	HRESULT hr = pKeyDevice->Acquire();

	while (msg.message != WM_QUIT)
	{
		Sleep(1);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60) //	1秒間に60回この中に入るはず
			{
				Askillcount++;
				Sskillcount++;
				GameScene();
				Render();
				Pcontrol();
				Bcontrol();
				Scontrol();

				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	FreeDx();
	return (int)msg.wParam;
}
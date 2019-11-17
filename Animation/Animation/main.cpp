#include <DxLib.h>
#include "Keyboard.h"
#include "FPS.hpp"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("アニメーション");		// アプリケーション名

	SetOutApplicationLogValidFlag(false);		// logファイルの生成
#ifdef _DEBUG
	ChangeWindowMode(true);						// スクリーン設定
#else
	ChangeWindowMode(false);					// スクリーン設定
#endif

	SetGraphMode(960, 540, 32);					// 描画範囲
	SetFontSize(16);							// 文字サイズ設定
	if (DxLib_Init() == -1)						// Dxライブラリの初期化
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// 背景描画設定
	{
		return -1;
	}
	SetMouseDispFlag(false);					// ウィンドウモードでもマウスカーソルを非表示にする

	Keyboard* key = new Keyboard();
	FPS* fps = new FPS();

	// メッセージループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_END) == 0)
	{
		ClearDrawScreen();
		key->KeyUpdate();
		fps->Update();
		fps->Draw();
		fps->Waits();
		ScreenFlip();
	}
	DEL_OBJ(fps);
	DEL_OBJ(key);

	InitGraph();
	DxLib_End();

	return 0;
}
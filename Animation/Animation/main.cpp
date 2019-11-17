#include <DxLib.h>
#include "Keyboard.h"
#include "FPS.hpp"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("�A�j���[�V����");		// �A�v���P�[�V������

	SetOutApplicationLogValidFlag(false);		// log�t�@�C���̐���
#ifdef _DEBUG
	ChangeWindowMode(true);						// �X�N���[���ݒ�
#else
	ChangeWindowMode(false);					// �X�N���[���ݒ�
#endif

	SetGraphMode(960, 540, 32);					// �`��͈�
	SetFontSize(16);							// �����T�C�Y�ݒ�
	if (DxLib_Init() == -1)						// Dx���C�u�����̏�����
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// �w�i�`��ݒ�
	{
		return -1;
	}
	SetMouseDispFlag(false);					// �E�B���h�E���[�h�ł��}�E�X�J�[�\�����\���ɂ���

	Keyboard* key = new Keyboard();
	FPS* fps = new FPS();

	// ���b�Z�[�W���[�v
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
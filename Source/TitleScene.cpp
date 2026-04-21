#include "TitleScene.h"
#include "Screen.h"
#include "Config.h"
#include <DxLib.h>

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::ChangeScene("CR_SELECT");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}

void TitleScene::Draw()
{
	SetFontSize(20);
	DrawString(  0,   0, "TITLE SCENE", Config::White);
	DrawString(100, 400, "Push [SPACE]Key To CR_Select", Config::White);
}

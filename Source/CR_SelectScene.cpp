#include "CR_SelectScene.h"
#include <DxLib.h>

CR_SelectScene::CR_SelectScene()
{
}

CR_SelectScene::~CR_SelectScene()
{
}

void CR_SelectScene::Update()
{
	if (CheckHitKey(KEY_INPUT_S)) {
		SceneManager::ChangeScene("ST_SELECT");
	}
}

void CR_SelectScene::Draw()
{
	SetFontSize(20);
	DrawString(0, 0, "CR_SELECT SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [S]Key To ST_Select", GetColor(255, 255, 255));
}

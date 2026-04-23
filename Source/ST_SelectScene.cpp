#include "ST_SelectScene.h"
#include <DxLib.h>

ST_SelectScene::ST_SelectScene()
{
}

ST_SelectScene::~ST_SelectScene()
{
}

void ST_SelectScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
}

void ST_SelectScene::Draw()
{
	SetBackgroundColor( 0, 0, 0);		//背景カラー

	SetFontSize(20);
	DrawString(0, 0, "ST_SELECT SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}

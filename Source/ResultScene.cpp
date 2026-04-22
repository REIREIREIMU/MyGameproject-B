#include "ResultScene.h"
#include <DxLib.h>

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void ResultScene::Draw()
{
	SetBackgroundColor(0, 0, 0);		//背景カラー

	SetFontSize(20);
	DrawString(0, 0, "RESULT SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}

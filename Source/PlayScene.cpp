#include "PlayScene.h"
#include <DxLib.h>

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_R)) {
		SceneManager::ChangeScene("RESULT");
	}
}

void PlayScene::Draw()
{
	SetBackgroundColor(0, 0, 0);		//背景カラー

	SetFontSize(20);
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [R]Key To Result", GetColor(255, 255, 255));
}

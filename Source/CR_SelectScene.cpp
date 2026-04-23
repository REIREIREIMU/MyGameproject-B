#include "CR_SelectScene.h"
#include "Screen.h"
#include "Config.h"
#include <DxLib.h>

CR_SelectScene::CR_SelectScene()
{
}

CR_SelectScene::~CR_SelectScene()
{
}

void CR_SelectScene::Update()
{
	//if ()
	//{

	//}

	/*if (CheckHitKey(KEY_INPUT_S)) {
		SceneManager::ChangeScene("ST_SELECT");
	}*/
}

void CR_SelectScene::Draw()
{
	SetBackgroundColor(255, 100, 100);		//背景カラー（淡い赤）

	SetFontSize(20);
	DrawString(0, 0, "CR_SELECT SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [S]Key To ST_Select", GetColor(255, 255, 255));
}

#include "CR_SelectScene.h"
#include "Screen.h"
#include "Input.h"
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
	// ============ わからなくなりそうだけど全共通 ==============
	// フレーム時間管理
	int now = GetNowCount();
	float delta = (now - Config::prevTime) / 1000.0f; // 経過秒数
	Config::prevTime = now;

	// クールタイム更新
	if (Wait_Time > 0.0f) {
		Wait_Time -= delta;
		if (Wait_Time < 0.0f) Wait_Time = 0.0f;
	}

	// 入力更新
	Input::Update();
	// =======================================================

	if (Wait_Time == 0.0f)
	{
		int axisY = Input::GetAxisY();

		if (DX_INPUT_PAD1) {
			if (axisY == Config::UP) { // 上
				Wait_Time = Config::Title_Wait_Time; // クールタイム加算
				Character_Select--;
				if (Character_Select < Character_Content::Character_A)
					Character_Select = Character_Content::Character_R;
			}
			else if (axisY == Config::DOWN) { // 下
				Wait_Time = Config::Title_Wait_Time; // クールタイム加算
				Character_Select++;
				if (Character_Select > Character_Content::Character_R)
					Character_Select = Character_Content::Character_A;
			}
		}
	}

	//if (CheckHitKey(KEY_INPUT_S)) {
	//	SceneManager::ChangeScene("ST_SELECT");
	//}
}

void CR_SelectScene::Draw()
{
	SetBackgroundColor(255, 100, 100);		//背景カラー（淡い赤）

	SetFontSize(20);
	DrawString(0, 0, "CR_SELECT SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [S]Key To ST_Select", GetColor(255, 255, 255));
}

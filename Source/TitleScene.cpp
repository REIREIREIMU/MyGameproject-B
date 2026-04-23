#include "TitleScene.h"
#include "Screen.h"
#include "Config.h"
#include "Input.h"
#include <DxLib.h>

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
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
				Title_Select--;
				if (Title_Select < Select_Content::Solo_Play)
					Title_Select = Select_Content::Exit;
			}
			else if (axisY == Config::DOWN) { // 下
				Wait_Time = Config::Title_Wait_Time; // クールタイム加算
				Title_Select++;
				if (Title_Select > Select_Content::Exit)
					Title_Select = Select_Content::Solo_Play;
			}
		}
	}

	if (DX_INPUT_PAD1 && Input::Is_SPACE())
	{
		if (Title_Select == Select_Content::Multi_Play) {
			SceneManager::ChangeScene("CR_SELECT");
		}
		else if (Title_Select == Select_Content::Exit) {
			SceneManager::Exit();
		}
	}

	// デバック用表示
	{
		SetFontSize(20);
		DrawFormatString(150, 0, Config::White, "T選択:%d", Title_Select);
		DrawFormatString(250, 0, Config::White, "入力クールタイム:%-0.2f", Wait_Time);
	}

}

void TitleScene::Draw()
{
	SetBackgroundColor(0, 100, 125);		//背景カラー（水色）

	SetFontSize(20);
	DrawString(  0,   0, "TITLE SCENE", Config::White);

	SetFontSize(100);
	DrawString(250, 220, "タイトル(仮)", Config::White);

	SetFontSize(30);		//フォントのサイズ:30
	//DrawString(Screen::WIDTH / 4, 400, "一人で開始", Config::White);
	DrawString(Screen::WIDTH / 4, 400, "-coming soon-", Config::White);
	DrawString(Screen::WIDTH / 4, 450, "二人で開始", Config::White);
	DrawString(Screen::WIDTH / 4, 500, "終了", Config::White);
}

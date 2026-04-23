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
	// フレーム時間管理
	int now = GetNowCount();
	float delta = (now - Config::prevTime) / 1000.0f; // 経過秒数
	Config::prevTime = now;
	
	// クールタイム更新
	if (Wait_Time > 0.0f) {
		Wait_Time -= delta;
		if (Wait_Time < 0.0f) Wait_Time = 0.0f;
	}

	if (Wait_Time == 0.00f && CheckHitKey(KEY_INPUT_UP))
	{
		Wait_Time += Config::Title_Wait_Time;	// クールタイム加算
		Title_Select--;
		if (Title_Select < Select_Content::Solo_Play) Title_Select = Select_Content::Exit;
	}
	else if (Wait_Time == 0.00f && CheckHitKey(KEY_INPUT_DOWN))
	{
		Wait_Time += Config::Title_Wait_Time;	// クールタイム加算
		Title_Select++;
		if (Title_Select > Select_Content::Exit) Title_Select = Select_Content::Solo_Play;
	}

	if (Title_Select == Select_Content::Multi_Play && CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::ChangeScene("CR_SELECT");
	}
	if (Title_Select == Select_Content::Exit && CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::Exit();
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

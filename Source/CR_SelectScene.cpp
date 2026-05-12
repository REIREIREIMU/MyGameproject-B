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

	int axisX = Input::GetAxisX();
	int axisY = Input::GetAxisY();

	if (Wait_Time == 0.0f && DX_INPUT_PAD1) {
		// キャラを選択の操作(キャラクターが選ばれていない時)
		{
			// 左移動
			if (Select_Player_1 == false && axisX == Config::LEFT) {
				Wait_Time = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_X--;
				if (Character_Select_X < Character_Content_X::Character_X1) {
					Character_Select_X = Character_Content_X::Character_X3;
				}
			}
			// 右移動
			else if (Select_Player_1 == false && axisX == Config::RIGHT) {
				Wait_Time = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_X++;
				if (Character_Select_X > Character_Content_X::Character_X3)
					Character_Select_X = Character_Content_X::Character_X1;
			}
			// 上移動
			else if (Select_Player_1 == false && axisY == Config::UP) {
				Wait_Time = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_Y--;
				if (Character_Select_Y < Character_Content_Y::Character_Y1) {
					Character_Select_Y = Character_Content_Y::Character_Y3;
				}
			}
			// 下移動
			else if (Select_Player_1 == false && axisY == Config::DOWN) {
				Wait_Time = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_Y++;
				if (Character_Select_Y > Character_Content_Y::Character_Y3)
					Character_Select_Y = Character_Content_Y::Character_Y1;
			}
		}
		// キャラ決定処理
		if (Select_Player_1 == false && Input::Is_SPACE())
		{
			Wait_Time = Config::Cr_Sel_Wait_Time; // クールタイム加算
			Select_Player_1 = true;		// 決定
		}
		else if(Select_Player_1 == true && Input::Is_SPACE())
		{
			Wait_Time = Config::Cr_Sel_Wait_Time; // クールタイム加算
			Select_Player_1 = false;	// 決定解除
		}
	}
	
	// 二人のプレイヤーのキャラが決まったらステージセレクトに進む
	if (Select_Player_1 == true && Select_Player_2 == true)
	{
		SceneManager::ChangeScene("ST_SELECT");
	}

	// デバック用表示
	{
		SetFontSize(20);
		DrawFormatString( 0, 20, Config::White, "C選択: %d, %d", Character_Select_X, Character_Select_Y);
		DrawFormatString( 0, 40, Config::White, "入力クールタイム:%-0.2f", Wait_Time);
		//DrawFormatString( 0, 60, Config::White, "キャラ決定1:%d", Select_Player_1);
		//DrawFormatString( 0, 80, Config::White, "キャラ決定2:%d", Select_Player_2);
		if		(Select_Player_1 == true)	DrawFormatString(0, 60, Config::White, "キャラ決定1:true");
		else if (Select_Player_1 == false)	DrawFormatString(0, 60, Config::White, "キャラ決定1:false");
		if		(Select_Player_2 == true)	DrawFormatString(0, 80, Config::White, "キャラ決定2:true");
		else if (Select_Player_2 == false)	DrawFormatString(0, 80, Config::White, "キャラ決定2:false");
	}

}

void CR_SelectScene::Draw()
{
	SetBackgroundColor(255, 100, 100);		//背景カラー（淡い赤）

	SetFontSize(20);
	DrawString(0, 0, "CR_SELECT SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [S]Key To ST_Select", GetColor(255, 255, 255));
}

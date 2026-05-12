#include "ST_SelectScene.h"
#include "Screen.h"
#include "Config.h"
#include "Input.h"
#include <DxLib.h>

ST_SelectScene::ST_SelectScene()
{
}

ST_SelectScene::~ST_SelectScene()
{
}

void ST_SelectScene::Update()
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
		// ステージを選択の操作(キャラクターが選ばれていない時)
		{
			// 左移動
			if (Select_Player == false && axisX == Config::LEFT) {
				Wait_Time = Config::St_Sel_Wait_Time; // クールタイム加算
				Stage_Select[0]--;
				if (Stage_Select[0] < Stage_Content_X::Stage_X1) {
					Stage_Select[0] = Stage_Content_X::Stage_X3;
				}
			}
			// 右移動
			else if (Select_Player == false && axisX == Config::RIGHT) {
				Wait_Time = Config::St_Sel_Wait_Time; // クールタイム加算
				Stage_Select[0]++;
				if (Stage_Select[0] > Stage_Content_X::Stage_X3)
					Stage_Select[0] = Stage_Content_X::Stage_X1;
			}
			// 上移動
			else if (Select_Player == false && axisY == Config::UP) {
				Wait_Time = Config::St_Sel_Wait_Time; // クールタイム加算
				Stage_Select[1]--;
				if (Stage_Select[1] < Stage_Content_Y::Stage_Y1) {
					Stage_Select[1] = Stage_Content_Y::Stage_Y3;
				}
			}
			// 下移動
			else if (Select_Player == false && axisY == Config::DOWN) {
				Wait_Time = Config::St_Sel_Wait_Time; // クールタイム加算
				Stage_Select[1]++;
				if (Stage_Select[1] > Stage_Content_Y::Stage_Y3)
					Stage_Select[1] = Stage_Content_Y::Stage_Y1;
			}
		}
		// ステージ決定処理
		if (Select_Player == false)
		{
			if (Input::Is_SPACE()) {
				Wait_Time = Config::St_Sel_Wait_Time; // クールタイム加算
				Select_Player = true;		// 決定
			}
		}
		else if(Select_Player == true)
		{
			SceneManager::ChangeScene("PLAY");
		}
	}

	// デバック用表示
	{
		SetFontSize(20);
		DrawFormatString(0, 20, Config::White, "S選択: %d, %d", Stage_Select[0], Stage_Select[1]);
		DrawFormatString(0, 40, Config::White, "入力クールタイム:%-0.2f", Wait_Time);
		if      (Select_Player == true)	 DrawFormatString(0, 60, Config::White, "ステージ決定:true");
		else if (Select_Player == false) DrawFormatString(0, 60, Config::White, "ステージ決定:false");

	}
}

void ST_SelectScene::Draw()
{
	SetBackgroundColor( 0, 0, 0);		//背景カラー

	SetFontSize(20);
	DrawString(0, 0, "ST_SELECT SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}

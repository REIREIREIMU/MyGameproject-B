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
	// ==========[0]はプレイヤー１、[1]はプレイヤー２============
	// ============ わからなくなりそうだけど全共通 ==============
	// フレーム時間管理
	int now = GetNowCount();
	float delta = (now - Config::prevTime) / 1000.0f; // 経過秒数
	Config::prevTime = now;

	// クールタイム更新(1P用)
	if (Wait_Time[0] > 0.0f) {
		Wait_Time[0] -= delta;
		if (Wait_Time[0] < 0.0f) Wait_Time[0] = 0.0f;
	}

	// クールタイム更新(2P用)
	if (Wait_Time[1] > 0.0f) {
		Wait_Time[1] -= delta;
		if (Wait_Time[1] < 0.0f) Wait_Time[1] = 0.0f;
	}

	// 入力更新
	Input::Update();
	// =======================================================

	int axisX = Input::GetAxisX();
	int axisY = Input::GetAxisY();

	// １プレイヤー用
	if (Wait_Time[0] == 0.0f && DX_INPUT_PAD1) {
		// キャラを選択の操作(キャラクターが選ばれていない時)
		{ 
			// 左移動
			if (Select_Player[0] == false && axisX == Config::LEFT) {
				Wait_Time[0] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_X[0]--;
				if (Character_Select_X[0] < Character_Content_X::Character_X1) {
					Character_Select_X[0] = Character_Content_X::Character_X3;
				}
			}
			// 右移動
			else if (Select_Player[0] == false && axisX == Config::RIGHT) {
				Wait_Time[0] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_X[0]++;
				if (Character_Select_X[0] > Character_Content_X::Character_X3)
					Character_Select_X[0] = Character_Content_X::Character_X1;
			}
			// 上移動
			else if (Select_Player[0] == false && axisY == Config::UP) {
				Wait_Time[0] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_Y[0]--;
				if (Character_Select_Y[0] < Character_Content_Y::Character_Y1) {
					Character_Select_Y[0] = Character_Content_Y::Character_Y3;
				}
			}
			// 下移動
			else if (Select_Player[0] == false && axisY == Config::DOWN) {
				Wait_Time[0] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_Y[0]++;
				if (Character_Select_Y[0] > Character_Content_Y::Character_Y3)
					Character_Select_Y[0] = Character_Content_Y::Character_Y1;
			}
		}
		// キャラ決定処理
		if (Select_Player[0] == false && Input::Is_SPACE())
		{
			Wait_Time[0] = Config::Cr_Sel_Wait_Time; // クールタイム加算
			Select_Player[0] = true;		// 決定
		}
		else if(Select_Player[0] == true && Input::Is_SPACE())
		{
			Wait_Time[0] = Config::Cr_Sel_Wait_Time; // クールタイム加算
			Select_Player[0] = false;	// 決定解除
		}
	}

	// ２プレイヤー用
	/*
	if (Wait_Time[1] == 0.0f && DX_INPUT_PAD2) {
		// キャラを選択の操作(キャラクターが選ばれていない時)
		{
			// 左移動
			if (Select_Player[1] == false && axisX == Config::LEFT) {
				Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_X[1]--;
				if (Character_Select_X[1] < Character_Content_X::Character_X1) {
					Character_Select_X[1] = Character_Content_X::Character_X3;
				}
			}
			// 右移動
			else if (Select_Player[1] == false && axisX == Config::RIGHT) {
				Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_X[1]++;
				if (Character_Select_X[1] > Character_Content_X::Character_X3)
					Character_Select_X[1] = Character_Content_X::Character_X1;
			}
			// 上移動
			else if (Select_Player[1] == false && axisY == Config::UP) {
				Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_Y[1]--;
				if (Character_Select_Y[1] < Character_Content_Y::Character_Y1) {
					Character_Select_Y[1] = Character_Content_Y::Character_Y3;
				}
			}
			// 下移動
			else if (Select_Player[1] == false && axisY == Config::DOWN) {
				Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_Y[1]++;
				if (Character_Select_Y[1] > Character_Content_Y::Character_Y3)
					Character_Select_Y[1] = Character_Content_Y::Character_Y1;
			}
		}
		// キャラ決定処理
		if (Select_Player[1] == false && Input::Is_SPACE())
		{
			Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
			Select_Player[1] = true;		// 決定
		}
		else if (Select_Player[1] == true && Input::Is_SPACE())
		{
			Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
			Select_Player[1] = false;	// 決定解除
		}
	}*/
	// =================== ↓ここの下は消す↓ ===================
	if (Wait_Time[1] == 0.0f) {
		// キャラを選択の操作(キャラクターが選ばれていない時)
		{
			// 左移動
			if (Select_Player[1] == false && CheckHitKey(KEY_INPUT_J)) {
				Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_X[1]--;
				if (Character_Select_X[1] < Character_Content_X::Character_X1) {
					Character_Select_X[1] = Character_Content_X::Character_X3;
				}
			}
			// 右移動
			else if (Select_Player[1] == false && CheckHitKey(KEY_INPUT_L)) {
				Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_X[1]++;
				if (Character_Select_X[1] > Character_Content_X::Character_X3)
					Character_Select_X[1] = Character_Content_X::Character_X1;
			}
			// 上移動
			else if (Select_Player[1] == false && CheckHitKey(KEY_INPUT_I)) {
				Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_Y[1]--;
				if (Character_Select_Y[1] < Character_Content_Y::Character_Y1) {
					Character_Select_Y[1] = Character_Content_Y::Character_Y3;
				}
			}
			// 下移動
			else if (Select_Player[1] == false && CheckHitKey(KEY_INPUT_K)) {
				Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
				Character_Select_Y[1]++;
				if (Character_Select_Y[1] > Character_Content_Y::Character_Y3)
					Character_Select_Y[1] = Character_Content_Y::Character_Y1;
			}
		}
		// キャラ決定処理
		if (Select_Player[1] == false && CheckHitKey(KEY_INPUT_RETURN))
		{
			Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
			Select_Player[1] = true;		// 決定
		}
		else if (Select_Player[1] == true && CheckHitKey(KEY_INPUT_RETURN))
		{
			Wait_Time[1] = Config::Cr_Sel_Wait_Time; // クールタイム加算
			Select_Player[1] = false;	// 決定解除
		}
	}
	// =================== ↑ここの上は消す↑ ===================
	// 二人のプレイヤーのキャラが決まったらステージセレクトに進む
	if (Select_Player[0] == true && Select_Player[1] == true)
	{
		SceneManager::ChangeScene("ST_SELECT");
	}

	// デバック用表示
	{
		SetFontSize(20);
		// 1P
		{
			DrawFormatString(0, 20, Config::White, "1P_C選択: %d, %d", Character_Select_X[0], Character_Select_Y[0]);
			DrawFormatString(0, 40, Config::White, "1P_入力クールタイム:%-0.2f", Wait_Time[0]);
			if		(Select_Player[0] == true)	DrawFormatString(0, 60, Config::White, "1P_キャラ決定:true");
			else if (Select_Player[0] == false)	DrawFormatString(0, 60, Config::White, "1P_キャラ決定:false");
		}
		// 2P
		{
			DrawFormatString(400, 20, Config::White, "2P_C選択: %d, %d", Character_Select_X[1], Character_Select_Y[1]);
			DrawFormatString(400, 40, Config::White, "2P_入力クールタイム:%-0.2f", Wait_Time[1]);
			if		(Select_Player[1] == true)	DrawFormatString(400, 60, Config::White, "2P_キャラ決定:true");
			else if (Select_Player[1] == false)	DrawFormatString(400, 60, Config::White, "2P_キャラ決定:false");
		}
	}
}

void CR_SelectScene::Draw()
{
	SetBackgroundColor(255, 100, 100);		//背景カラー（淡い赤）

	SetFontSize(20);
	DrawString(0, 0, "CR_SELECT SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [S]Key To ST_Select", GetColor(255, 255, 255));
}

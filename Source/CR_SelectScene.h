#pragma once
#include "../Library/SceneBase.h"

class CR_SelectScene : public SceneBase
{
public:
	CR_SelectScene();
	~CR_SelectScene();
	void Update() override;
	void Draw() override;
private:
	int  Character_Select_X[2] = { 0,0 }; // キャラクター選択変数（X軸）※ [2]はプレイヤーの人数
	int  Character_Select_Y[2] = { 0,0 }; // キャラクター選択変数（Y軸）※ [2]はプレイヤーの人数

	enum Character_Content_X
	{
		Character_X1,
		Character_X2,
		Character_X3
	};
	enum Character_Content_Y
	{
		Character_Y1,
		Character_Y2,
		Character_Y3
	};

	bool Select_Player[2] = { true , false };	// プレイヤーのキャラを決定（false = 決まってない/true = 決定）※プレイヤー１は、ここでtrueにしないと即決定になる
	float Wait_Time[2] = { 0.00f , 0.00f };		// 入力クールタイム
};

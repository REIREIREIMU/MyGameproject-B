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
	int  Character_Select_X = 0; // キャラクター選択変数
	int  Character_Select_Y = 0; // キャラクター選択変数

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

	bool Select_Player_1 = true;	// プレイヤー1のキャラを決定（false = 決まってない/true = 決定）※ここでtrueにしないと即決定になる
	bool Select_Player_2 = true;	// プレイヤー2のキャラを決定（false = 決まってない/true = 決定）

	float Wait_Time = 0.00f; // 入力クールタイム
};

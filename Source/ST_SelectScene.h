#pragma once
#include "../Library/SceneBase.h"

class ST_SelectScene : public SceneBase
{
public:
	ST_SelectScene();
	~ST_SelectScene();
	void Update() override;
	void Draw() override;

private:
	int  Stage_Select[2] = { 0,0 }; // キャラクター選択変数
	enum Stage_Content_X
	{
		Stage_X1,
		Stage_X2,
		Stage_X3
	};
	enum Stage_Content_Y
	{
		Stage_Y1,
		Stage_Y2,
		Stage_Y3
	};

	bool  Select_Player = true;		// ステージの決定フラグ（false = 決まってない/true = 決定）※プレイヤー１は、ここでtrueにしないと即決定になる
	float Wait_Time     = 0.00f;	// 入力クールタイム
};
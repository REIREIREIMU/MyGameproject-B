#pragma once
#include "../Library/SceneBase.h"

class ST_SelectScene : public SceneBase
{
public:
	ST_SelectScene();
	~ST_SelectScene();
	void Update() override;
	void Draw() override;

	void StageSelecting();

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

	// セレクトの状態
	enum SelectState
	{
		Init_Wait,
		Selecting,
		Preparation_OK
	};

	SelectState state;

	bool  Stage_Decision; // ステージの決定フラグ（false = 決まってない/true = 決定）※プレイヤー１は、ここでtrueにしないと即決定になる
	float Wait_Time;      // 入力クールタイム
	float Common_Wait;    // 最初の待機時間
};
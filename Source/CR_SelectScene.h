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
	int  Character_Select = 0; // キャラクター選択変数
	enum Character_Content
	{
		Character_A,
		Character_B,
		Character_C,
		Character_D,
		Character_E,
		Character_F,
		Character_G,
		Character_H,
		Character_R
		//Exit		// 退出
	};

	float Wait_Time = 0.00f; // 入力クールタイム
};

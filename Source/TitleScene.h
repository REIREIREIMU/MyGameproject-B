#pragma once
#include "../Library/SceneBase.h"

/// <summary>
/// タイトルシーン
/// 
/// タイトルを表示して、キーを押したらプレイシーンに移行する。
/// </summary>
class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
private:
	int  Title_Select = 0; // 選択変数
	enum Select_Content
	{
		Solo_Play,  // ソロプレイ
		Multi_Play, // マルチプレイ
		Exit        // 退出
	};

	float Wait_Time    = 0.00f; // 入力クールタイム
};

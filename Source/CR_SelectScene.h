#pragma once
#include "../Library/SceneBase.h"

class CR_SelectScene : public SceneBase
{
public:
    CR_SelectScene();
    ~CR_SelectScene();
    void Update() override;
    void Draw() override;

    void CharacterSelecting();

private:
    int  Character_Select_X[2] = { 0,0 }; // キャラクター選択変数（X軸）※ [2]はプレイヤーの人数
    int  Character_Select_Y[2] = { 0,0 }; // キャラクター選択変数（Y軸）※ [2]はプレイヤーの人数

    // キャラ選択X軸
    enum Character_Content_X
    {
        Character_X1,
        Character_X2,
        Character_X3
    };
    // キャラ選択Y軸
    enum Character_Content_Y
    {
        Character_Y1,
        Character_Y2,
        Character_Y3
    };

    // キャラクター種類
    enum Character
    {
        Chara_A,
        Chara_B,
        Chara_C,
        Chara_D,
        Chara_E,
        Chara_F,
        Chara_G,
        Chara_H,
        Chara_I
    };

    // セレクトの状態
    enum SelectState
    {
        Init_Wait,
        Selecting,
        Preparation_OK
    };

    SelectState state;

    bool Select_Player[2]; // プレイヤーのキャラを決定（false = 決まってない/true = 決定）※プレイヤー１は、ここでtrueにしないと即決定になる
    float Wait_Time[2];    // 入力クールタイム
    float Common_Wait;     // 最初の待機時間
};
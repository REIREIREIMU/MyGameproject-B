#pragma once
#include "../Library/GameObject.h"
#include <vector>

class CR_SelectScene;

class Character : public GameObject
{
public:
    Character();
    ~Character();
    void Update() override;
    void Draw() override;

    void Attack();

    // プレイヤー１の当たり判定
    float PositionX_UP_1P()   const { return position_UP_X[0]; }
    float PositionY_UP_1P()   const { return position_UP_Y[0]; }
    float PositionX_DOWN_1P() const { return position_DOWN_X[0]; }
    float PositionY_DOWN_1P() const { return position_DOWN_Y[0]; }

    // プレイヤー2の当たり判定
    float PositionX_2P() const { return position_UP_X[1]; }
    float PositionY_2P() const { return position_UP_Y[1]; }

private:
    int hImage[2];

    // 座標・　キャラのサイズ関係
    float position_UP_X[2], position_UP_Y[2];
    float position_DOWN_X[2], position_DOWN_Y[2];

    // キャラクターステータス
    float HP[2];            // キャラクターの体力
    float Guard_Point[2];   // ガードポイント
    float Attack_Power[2];  // 攻撃力
    float Speed[2];         // 移動速度
    float Jump_Power[2];    // ジャンプ力

    // キャラの行動パターン
    enum State {
        Idol,   // 待機
        Jump,   // ジャンプ
        Left,   // 左移動
        Right,  // 右移動
        squat,  // しゃがむ
        Guard,  // 防御
        Attack1,// 攻撃A
        Attack2,// 攻撃B
        Attack3,// 攻撃C
        Attack4,// 攻撃D
    };
    State action[2]; // キャラの行動状態(2人分)

    //int Chara_id[2];

    // ======= ポインター群 =======
    CR_SelectScene * charState = nullptr;     // CR_SelectSceneのポインタを作成
};
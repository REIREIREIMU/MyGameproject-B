#pragma once
#include "../Library/GameObject.h"
#include <vector>

// キャラクターのステータスを定義
enum class FatState {
    Character_A,
};

class Character : public GameObject
{
public:
    Character();
    ~Character();
    void Update() override;
    void Draw() override;

    // プレイヤー１の当たり判定
    float PositionX_1P() const { return positionX[0]; }
    float PositionY_1P() const { return positionY[0]; }

    // プレイヤー2の当たり判定
    float PositionX_2P() const { return positionX[1]; }
    float PositionY_2P() const { return positionY[1]; }

private:
    int hImage[2];

    // 座標・　キャラのサイズ関係
    float positionX[2], positionY[2];
    float Width[2];         // 幅

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

};
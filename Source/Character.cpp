#include "Character.h"
#include "CR_SelectScene.h"
#include "Config.h"
#include "Input.h"

static const float Ground = 600.0f;

Character::Character() :
    action{ (Idol),(Idol) },
    // =========================================
    position_UP_X  { (/*120.0f*/ 0.0f),(0.0f) },
    position_UP_Y  { (/*300.0f*/ 0.0f),(0.0f) },
    position_DOWN_X{ (/*280.0f*/ 0.0f),(0.0f) },
    position_DOWN_Y{ (/*600.0f*/ 0.0f),(0.0f) },
    // =========================================
    HP           { (0.0f),(0.0f) },
    Guard_Point  { (0.0f),(0.0f) },
    Attack_Power { (0.0f),(0.0f) },
    Speed        { (0.0f),(0.0f) },
    Jump_Power   { (0.0f),(0.0f) }
{
    if (CR_SelectScene::Instance().Chara_id[0] == CR_SelectScene::Chara_A) {
        position_UP_X[0] = 120.0f;
        position_UP_Y[0] = 300.0f;
        position_DOWN_X[0] = 280.0f;
        position_DOWN_Y[0] = 600.0f;
    }
    else if (CR_SelectScene::Instance().Chara_id[0] == CR_SelectScene::Chara_B) {
        position_UP_X[0] = 0.0f;
        position_UP_Y[0] = 0.0f;
        position_DOWN_X[0] = 0.0f;
        position_DOWN_Y[0] = 0.0f;
    }
    else if (CR_SelectScene::Instance().Chara_id[0] == CR_SelectScene::Chara_C) {
        position_UP_X[0] = 0.0f;
        position_UP_Y[0] = 0.0f;
        position_DOWN_X[0] = 0.0f;
        position_DOWN_Y[0] = 0.0f;
    }
    else if (CR_SelectScene::Instance().Chara_id[0] == CR_SelectScene::Chara_D) {
        position_UP_X[0] = 0.0f;
        position_UP_Y[0] = 0.0f;
        position_DOWN_X[0] = 0.0f;
        position_DOWN_Y[0] = 0.0f;
    }
    else if (CR_SelectScene::Instance().Chara_id[0] == CR_SelectScene::Chara_E) {
        position_UP_X[0] = 0.0f;
        position_UP_Y[0] = 0.0f;
        position_DOWN_X[0] = 0.0f;
        position_DOWN_Y[0] = 0.0f;
    }
    else if (CR_SelectScene::Instance().Chara_id[0] == CR_SelectScene::Chara_F) {
        position_UP_X[0] = 0.0f;
        position_UP_Y[0] = 0.0f;
        position_DOWN_X[0] = 0.0f;
        position_DOWN_Y[0] = 0.0f;
    }
    else if (CR_SelectScene::Instance().Chara_id[0] == CR_SelectScene::Chara_G) {
        position_UP_X[0] = 0.0f;
        position_UP_Y[0] = 0.0f;
        position_DOWN_X[0] = 0.0f;
        position_DOWN_Y[0] = 0.0f;
    }
    else if (CR_SelectScene::Instance().Chara_id[0] == CR_SelectScene::Chara_H) {
        position_UP_X[0] = 0.0f;
        position_UP_Y[0] = 0.0f;
        position_DOWN_X[0] = 0.0f;
        position_DOWN_Y[0] = 0.0f;
    }
    else if (CR_SelectScene::Instance().Chara_id[0] == CR_SelectScene::Chara_I) {
        position_UP_X[0] = 0.0f;
        position_UP_Y[0] = 0.0f;
        position_DOWN_X[0] = 0.0f;
        position_DOWN_Y[0] = 0.0f;
    }

}

Character::~Character()
{
}

void Character::Update()
{
    int axisX = Input::GetAxisX();
    int axisY = Input::GetAxisY();

    // １プレイヤー用
    if (DX_INPUT_PAD1) {
        // キャラを選択の操作(キャラクターが選ばれていない時)
        {
            // 左移動
            if (axisX == Config::LEFT) {
                action[0] = Left;
                position_UP_X[0]--;
                position_DOWN_X[0]--;
            }
            // 右移動
            else if (axisX == Config::RIGHT) {
                action[0] = Right;
                position_UP_X[0]++;
                position_DOWN_X[0]++;
            }
            // 上移動
            else if (axisY == Config::UP) {
                position_UP_Y[0]--;
                position_DOWN_Y[0]--;
            }
            // 下移動
            else if (axisY == Config::DOWN) {
                position_UP_Y[0]++;
                position_DOWN_Y[0]++;
            }

            if (Input::Is_SPACE()) {
                Attack();
            }
        }
    }
}

void Character::Draw()
{
    // デバック用表示
    {
        SetFontSize(20);
        // 1P
        {
            DrawFormatString(0, 20, Config::White, "1P選択キャラID:%d", CR_SelectScene::Instance().Chara_id[0]);
        }
        // 2P
        {
            DrawFormatString(400, 20, Config::White, "2P選択キャラID:%d", CR_SelectScene::Instance().Chara_id[1]);
        }

        // プレイヤーの判定
        DrawBox(position_UP_X[0], position_UP_Y[0], position_DOWN_X[0], position_DOWN_Y[0], Config::Green, false);
    }
}

void Character::Attack()
{
    // デバック用表示
    {
        // プレイヤーの判定
        DrawBox( position_DOWN_X[0], position_DOWN_Y[0] / 3, position_DOWN_X[0], position_DOWN_Y[0] / 6, Config::Red, false);
    }
}

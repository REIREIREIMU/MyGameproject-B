#include "Input.h"
#include "Config.h"

const int Analog_DeadZone = 200;  // スティックのデッドゾーン

int Input::padState[2] = { 0, 0 };

void Input::Update() {
        padState[0] = GetJoypadInputState(DX_INPUT_PAD1);
        padState[1] = GetJoypadInputState(DX_INPUT_PAD2);
}

// 左右移動（左スティック or キーボード）
int Input::GetAxisX() {
    int x = 0, y = 0;

    // アナログスティックによる左右判定（デッドゾーン適用）
    {
        GetJoypadAnalogInput(&x, &y, DX_INPUT_PAD1);
        if (x < -Analog_DeadZone) return Config::LEFT;
        if (x >  Analog_DeadZone) return Config::RIGHT;

        GetJoypadAnalogInput(&x, &y, DX_INPUT_PAD2);
        if (x < -Analog_DeadZone) return Config::LEFT;
        if (x >  Analog_DeadZone) return Config::RIGHT;
    }

    // キーボード
    if (CheckHitKey(KEY_INPUT_LEFT)  || CheckHitKey(KEY_INPUT_A)) return Config::LEFT;
    if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) return Config::RIGHT;

    return 0;
}

int Input::GetAxisY()
{
    int x = 0, y = 0;
    // アナログスティックによる上下判定（デッドゾーン適用）
    {
        GetJoypadAnalogInput(&x, &y, DX_INPUT_PAD1);
        if (y < -Analog_DeadZone) return Config::UP;
        if (y >  Analog_DeadZone) return Config::DOWN;

        GetJoypadAnalogInput(&x, &y, DX_INPUT_PAD2);
        if (y < -Analog_DeadZone) return Config::UP;
        if (y >  Analog_DeadZone) return Config::DOWN;
    }

    if (CheckHitKey(KEY_INPUT_UP)   || CheckHitKey(KEY_INPUT_W)) return Config::UP;
    if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) return Config::DOWN;
}

// ENTER（B / ENTER）
bool Input::Is_ENTER() {
    // PAD1, PAD2 の B ボタン
    if (padState[0] & PAD_INPUT_2) return true;
    if (padState[1] & PAD_INPUT_2) return true;

    // キーボード
    if (CheckHitKey(KEY_INPUT_RETURN)) return true;

    return false;
}

// SPACE（A / SPACE）
bool Input::Is_SPACE() {
    // PAD1, PAD2 の A ボタン
    if (padState[0] & PAD_INPUT_1) return true;
    if (padState[1] & PAD_INPUT_1) return true;

    // キーボード
    if (CheckHitKey(KEY_INPUT_SPACE)) return true;

    return false;
}

// デバッグ表示（押されたボタンを出す）
//void Input::DebugPrint() {
//    if (padState & PAD_INPUT_1) {
//        DrawString(50, 100, "PAD_INPUT_1: (Xbox=A)", GetColor(255, 255, 255));
//    }
//    if (padState & PAD_INPUT_2) {
//        DrawString(50, 120, "PAD_INPUT_2: (Xbox=B)", GetColor(255, 255, 255));
//    }
//}

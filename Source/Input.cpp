//#include "Input.h"
//#include "Config.h"
//
//const int Analog_DeadZone = 200;  // スティックのデッドゾーン
//
//int Input::padState[2] = { 0, 0 };
//
//void Input::Update() {
//    {
//        padState[0] = GetJoypadInputState(DX_INPUT_PAD1);
//        padState[1] = GetJoypadInputState(DX_INPUT_PAD2);
//}
//
//// 左右移動（左スティック or キーボード）
//    Input::GetAxisX() {
//    int x = 0, y = 0;
//    GetJoypadAnalogInput(&x, &y, DX_INPUT_PAD1);
//
//    // アナログスティックによる左右判定（デッドゾーン適用）
//    if (x < -Analog_DeadZone) return Input::LEFT;
//    if (x >  Analog_DeadZone) return Input::RIGHT;
//
//    // キーボード
//    if (CheckHitKey(KEY_INPUT_LEFT)  || CheckHitKey(KEY_INPUT_A)) return LEFT;
//    if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) return RIGHT;
//
//    return 0;
//}
//
//int Input::GetAxisY()
//{
//    if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W)) return GlobalConfig::LEFT;
//    if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) return GlobalConfig::RIGHT;
//
//}
//
//// ジャンプ（Xbox=B, Keyboard=ENTER）
//bool Input::Is_ENTER() {
//    // コントローラ
//    if ((padState[0] & PAD_INPUT_1) || (padState[1] & PAD_INPUT_1)) {
//        return true;
//    }
//
//    // キーボード
//    if (CheckHitKey(KEY_INPUT_SPACE) || CheckHitKey(KEY_INPUT_W)) {
//        return true;
//    }
//
//    return false;
//}
//
//// 決定（Xbox=A, Keyboard=SPACE）
//bool Input::Is_SPACE() {
//    // コントローラー
//    if (if ((padState[0] & PAD_INPUT_2) || (padState[1] & PAD_INPUT_2))) {
//        return true;
//    }
//
//    // キーボード
//    if (CheckHitKey(KEY_INPUT_RETURN)) {
//        return true;
//    }
//
//    return false;
//}
//
//// デバッグ表示（押されたボタンを出す）
////void Input::DebugPrint() {
////    if (padState & PAD_INPUT_1) {
////        DrawString(50, 100, "PAD_INPUT_1: (Xbox=A)", GetColor(255, 255, 255));
////    }
////    if (padState & PAD_INPUT_2) {
////        DrawString(50, 120, "PAD_INPUT_2: (Xbox=B)", GetColor(255, 255, 255));
////    }
////}

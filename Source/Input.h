#pragma once
#include <DxLib.h>

// 入力設定
class Input {
public:
    static void Update();

    // 左右移動
    static int GetAxisX(); // -1: 左, 1: 右, 0: 無し
    static int GetAxisY(); // -1: 上, 1: 下, 0: 無し

    // ボタン入力
    static bool Is_ENTER(); //（ B / ENTER）
    static bool Is_SPACE(); //（ A / SPACE）

    // デバッグ表示
    //static void DebugPrint();

private:
    static int padState[2];  // ジョイパッド状態
};
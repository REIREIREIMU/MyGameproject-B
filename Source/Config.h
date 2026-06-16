#pragma once
#include "../ImGui/imgui.h"

namespace Config {
    // 配色定数
    const int Default_Color = GetColor(200, 200, 200);  // デフォルト色
    const int Brown         = GetColor(139,  69,  19);  // 茶色
    const int Light_Brown   = GetColor(160,  82,  45);  // 明るい茶色
    const int Red           = GetColor(255, 100, 100);  // 赤
    const int Yellow        = GetColor(255, 255,   0);  // 黄色
    const int Cyan          = GetColor(  0, 255, 255);  // 水色
    const int Light_Cyan    = GetColor( 50, 150, 170);  // 明るい水色
    const int Green         = GetColor(  0, 255,   0);  // 緑
    const int Black         = GetColor(  0,   0,   0);	// 黒
    const int White         = GetColor(255, 255, 255);  // 白

    static int prevTime = GetNowCount();  // 前フレームの時間を記録

    // 入力クールタイム管理
    static constexpr float Title_Wait_Time  = 1.0f;
    static constexpr float Cr_Sel_Wait_Time = 1.0f;
    static constexpr float St_Sel_Wait_Time = 1.0f;
    static constexpr float Play_Wait_Time   = 1.0f;
    static constexpr float Result_Wait_Time = 1.0f;

    // 定数管理
    static const int  LEFT = -1,   UP = -1;   // 左&上
    static const int RIGHT =  1, DOWN =  1;   // 右&下
}

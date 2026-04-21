#pragma once
#include "../ImGui/imgui.h"

namespace Config {
    // 配色定数
    const int Default_Color = GetColor(200, 200, 200);  // デフォルト色
    const int Brown         = GetColor(139,  69,  19);  // 茶色
    const int Light_Brown   = GetColor(160,  82,  45);  // 明るい茶色
    const int Red           = GetColor(255, 100, 100);  // 赤っぽいレンガ
    const int Yellow        = GetColor(255, 255,   0);  // 黄色
    const int Cyan          = GetColor(  0, 255, 255);  // 水色
    const int Light_Cyan    = GetColor( 50, 150, 170);  // 明るい水色
    const int Green         = GetColor(  0, 255,   0);  // 緑
    const int Black         = GetColor(  0,   0,   0);	// 黒
    const int White         = GetColor(255, 255, 255);  // 白
}

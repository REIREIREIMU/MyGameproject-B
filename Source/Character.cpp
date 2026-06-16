#include "Character.h"
#include "Config.h"

static const float Ground = 600.0f;

Character::Character() :
    action{ (Idol),(Idol) },
    // =========================================
    positionX{ (120.0f),(0.0f) },
    positionY{ (180.0f),(0.0f) },
    Width    { ( 80.0f),(0.0f) },
    // =========================================
    HP          { (0.0f),(0.0f) },
    Guard_Point { (0.0f),(0.0f) },
    Attack_Power{ (0.0f),(0.0f) },
    Speed       { (0.0f),(0.0f) },
    Jump_Power  { (0.0f),(0.0f) }
{
}

Character::~Character()
{
}

void Character::Update()
{
}

void Character::Draw()
{
    // デバック用表示
    {
        // プレイヤーの判定
        DrawBox(positionX[0], Ground - positionY[0], positionX[0] + Width[0], Ground, Config::Green, false);
    }
}

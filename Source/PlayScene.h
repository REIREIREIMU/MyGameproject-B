#pragma once
#include "../Library/SceneBase.h"
#include <vector>

class Character;

class PlayScene : public SceneBase
{
public:
    PlayScene();
    ~PlayScene();
    void Update() override;
    void Draw() override;

private:
    static const int Ground = 600; //ステージの地面

    // ======= ポインター群 =======
    Character* character = nullptr;     // Characterのポインタを作成

};

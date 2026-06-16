#pragma once
#include "../Library/SceneBase.h"

class PlayScene : public SceneBase
{
public:
    PlayScene();
    ~PlayScene();
    void Update() override;
    void Draw() override;

private:
    static const int Ground = 600; //ステージの地面
};

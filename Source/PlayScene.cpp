#include "PlayScene.h"
#include "Screen.h"
#include "Config.h"
#include <DxLib.h>
#include "Character.h"

PlayScene::PlayScene()
{
    character = new Character();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
    character->Update();

    if (CheckHitKey(KEY_INPUT_R)) {
        SceneManager::ChangeScene("RESULT");
    }
}

void PlayScene::Draw()
{
    SetBackgroundColor(0, 0, 0);    // 背景カラー

    character->Draw();

    SetFontSize(20);
    DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
    DrawString(100, 400, "Push [R]Key To Result", GetColor(255, 255, 255));

    // デバック用表示
    {
        // 地面の判定
        DrawLine(0, Ground, Screen::WIDTH, Ground, Config::Red);
    }

}

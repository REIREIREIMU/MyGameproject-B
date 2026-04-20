#pragma once
#include "../Library/SceneBase.h"

class CR_SelectScene : public SceneBase
{
public:
	CR_SelectScene();
	~CR_SelectScene();
	void Update() override;
	void Draw() override;
};

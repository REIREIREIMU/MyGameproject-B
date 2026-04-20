#pragma once
#include "../Library/SceneBase.h"

class ST_SelectScene : public SceneBase
{
public:
	ST_SelectScene();
	~ST_SelectScene();
	void Update() override;
	void Draw() override;
};

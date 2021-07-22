#pragma once
#include <cocos2d.h>
#include "../other_nodes/TestAlertProtocol.hpp"
#include "../pch.h"
#include <gd.h>

using namespace cocos2d;
using namespace gd;

class GameInGDLayer : public CCLayerGradient, prismdll::TestAlertProtocol {
	GameInGDLayer() = default;
	bool init();

	virtual void keyBackClicked(void);
public:
	static GameInGDLayer* create();
	void returnToMenu(CCObject* sender);
	void testCallback(CCObject* sender);
};

class ChangeTextButton : public CCMenuItemSpriteExtra {
public:
	void callback(CCObject* pSender);
	inline static int state;
};

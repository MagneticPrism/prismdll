#pragma once
#include <cocos2d.h>
#include "../other_nodes/TestAlertProtocol.hpp"
#include "../pch.h"
#include <gd.h>

using namespace cocos2d;
using namespace gd;

class HackOptionsLayer : public CCLayerGradient, FLAlertLayerProtocol {
	HackOptionsLayer() = default;
	bool init();

	virtual void keyBackClicked(void);
public:
	static HackOptionsLayer* create();
	void returnToMenu(CCObject* sender);
	void testCallback(CCObject* sender);
	void onCreatorHacksLayer(CCObject* sender);
	virtual void FLAlert_Clicked(gd::FLAlertLayer* layer, bool btn2);
};

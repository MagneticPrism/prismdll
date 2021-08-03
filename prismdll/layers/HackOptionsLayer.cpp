#include "HackOptionsLayer.h"
#include "MenuLayer.hpp"
#include "../util/CCDirectorModified.h"

bool HackOptionsLayer::init() {
	if (!CCLayer::init()) {
		return false;
	}

	CCDirector* director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	this->setTag(0);

	auto sprite2 = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
	auto retnbtn = CCMenuItemSpriteExtra::create(sprite2, this, menu_selector(HackOptionsLayer::returnToMenu));
	retnbtn->setTag(1);

	retnbtn->setPosition((-winSize.width / 2) + 25.0f, (winSize.height / 2) - 25.0f);

	auto buttonSprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");

	auto button = CCMenuItemSpriteExtra::create(buttonSprite, this, menu_selector(HackOptionsLayer::testCallback));
	button->setPosition(265, 142.5f);
	button->setTag(2);

	auto menu = CCMenu::create();

	menu->setTag(3);

	addChild(menu, 5);

	auto buttonSprite4 = gd::ButtonSprite::create("Decode Log File", 0, false, "goldFont.fnt", "GJ_button_01.png", 0, 0.8f);

	auto button4 = gd::CCMenuItemSpriteExtra::create(buttonSprite4, this, (cocos2d::SEL_MenuHandler)&HackOptionsLayer::onCreatorHacksLayer);

	button4->setPosition(-220, 40);

	menu->addChild(button4);

	auto topLeft = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	auto bottomLeft = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	auto topRight = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	auto bottomRight = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");

	topLeft->setFlipY(true);
	topRight->setFlipY(true);
	topRight->setFlipX(true);
	bottomRight->setFlipX(true);

	CCSize size = bottomLeft->getScaledContentSize();

	bottomLeft->setPosition({ size.width / 2, size.height / 2 });

	topLeft->setPosition({ size.width / 2, (winSize.height) - (size.height / 2) });

	topRight->setPosition({ (winSize.width) - (size.width / 2), (winSize.height) - (size.height / 2) });

	bottomRight->setPosition({ (winSize.width) - (size.width / 2), size.height / 2 });

	addChild(topLeft, 1);
	addChild(bottomLeft, 1);
	addChild(topRight, 1);
	addChild(bottomRight, 1);

	menu->addChild(retnbtn, 2);
	menu->addChild(button, 2);

	this->setKeypadEnabled(true);

	return true;
}

void HackOptionsLayer::keyBackClicked(void) {
	HackOptionsLayer::returnToMenu(nullptr);
}

void HackOptionsLayer::returnToMenu(CCObject* pSender) {
	CCDirectorModified* director = (CCDirectorModified*)CCDirectorModified::sharedDirector();

	director->replaceScene(
		CCTransitionFade::create(0.5f, director->getPreviousScene())
	);
}

void HackOptionsLayer::testCallback(CCObject* sender) {
	gd::FLAlertLayer::create(0,
		"Mod Info",
		"Close",
		nullptr,
		460.0f,
		"<cl>This</c> scene is currently <cr>useless</c>.\n"  \
	)->show();
}

HackOptionsLayer* HackOptionsLayer::create() {
	HackOptionsLayer* l = new HackOptionsLayer();
	l->initWithColor({ 0, 101, 253, 255 }, { 0, 46, 115, 255 });
	if (l && l->init()) {
		l->autorelease();
		return l;
	}
	else {
		CC_SAFE_DELETE(l);
		return NULL;
	}
}

void HackOptionsLayer::onCreatorHacksLayer(CCObject* sender)
{
	auto alert = gd::FLAlertLayer::create(this,
		"Mod Info",
		"Close",
		"Open",
		460.0f,
		"This is a beta version of creator hacks. Note that hacks arent implemented yet."  \
	);

	alert->setTag(110);

	alert->show();
}

void HackOptionsLayer::FLAlert_Clicked(gd::FLAlertLayer* layer, bool btn2)
{
	auto alert = reinterpret_cast<gd::FLAlertLayer*>(layer);

	if (alert->getTag() == 110)
	{
		if (btn2)
		{
			prismdll::layers::CreatorOptionsLayer::create()->show();
		}
	}
	else
	{
		FLAlert_Clicked(layer, btn2);
	}
}


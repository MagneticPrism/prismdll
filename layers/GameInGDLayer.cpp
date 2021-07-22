#include "GameInGDLayer.h"
#include "MenuLayer.hpp"
#include "../util/CCDirectorModified.h"

void ChangeTextButton::callback(CCObject* pSender) {
	CCDirector* director = CCDirector::sharedDirector();
	CCScene* scene = director->getRunningScene();
	CCLayerGradient* layer = (CCLayerGradient*)scene->getChildByTag(0);
	if (ChangeTextButton::state == 0) {
		CCLabelBMFont* label = (CCLabelBMFont*)layer->getChildByTag(1);
		label->setString("I told you. There's nothing here...");

		ChangeTextButton* btn = (ChangeTextButton*)layer->getChildByTag(3)->getChildByTag(2);
		auto sprite = CCSprite::createWithSpriteFrameName("GJ_updateBtn_001.png");
		btn->setNormalImage(sprite);
		btn->setDisabledImage(sprite);

		btn->setScale(1);

		ChangeTextButton::state = 1;
	}
	else {
		CCLabelBMFont* label = (CCLabelBMFont*)layer->getChildByTag(1);
		label->setString("Nothing to see here...");

		ChangeTextButton* btn = (ChangeTextButton*)layer->getChildByTag(3)->getChildByTag(2);
		auto sprite = CCSprite::createWithSpriteFrameName("GJ_redoBtn_001.png");
		btn->setNormalImage(sprite);
		btn->setDisabledImage(sprite);

		btn->setScale(1.25);

		ChangeTextButton::state = 0;
	}
}

bool GameInGDLayer::init() {
	if (!CCLayer::init()) {
		return false;
	}

	CCDirector* director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	this->setTag(0);

	ChangeTextButton::state = 0;

	auto sprite2 = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
	auto retnbtn = CCMenuItemSpriteExtra::create(sprite2, this, menu_selector(GameInGDLayer::returnToMenu));
	retnbtn->setTag(1);

	retnbtn->setPosition((-winSize.width / 2) + 25.0f, (winSize.height / 2) - 25.0f);

	auto buttonSprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");

	auto button = CCMenuItemSpriteExtra::create(buttonSprite, this, menu_selector(GameInGDLayer::testCallback));
	button->setTag(2);

	auto menu = CCMenu::create();

	menu->setTag(3);
	
	menu->addChild(button, 2);
	menu->addChild(retnbtn, 2);

	addChild(menu);

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

	addChild(retnbtn, 2);

	addChild(button, 2);

	this->setKeypadEnabled(true);

	return true;
}

void GameInGDLayer::keyBackClicked(void) {
	GameInGDLayer::returnToMenu(nullptr);
}

void GameInGDLayer::returnToMenu(CCObject* pSender) {
	CCDirectorModified* director = (CCDirectorModified*)CCDirectorModified::sharedDirector();

	director->replaceScene(
		CCTransitionFade::create(0.5f, director->getPreviousScene())
	);
}

void GameInGDLayer::testCallback(CCObject* sender) {
	gd::FLAlertLayer::create(0,
		"Mod Info",
		"Continue anyway",
		nullptr,
		460.0f,
		"<cl>This</c> scnene is currently <cr>useless</c>.\n"  \
	)->show();
}

GameInGDLayer* GameInGDLayer::create() {
	GameInGDLayer* l = new GameInGDLayer();
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
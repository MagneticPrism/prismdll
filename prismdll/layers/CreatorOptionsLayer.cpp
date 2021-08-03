#include "../pch.h"
#include "CreatorOptionsLayer.h"

using namespace cocos2d;
using namespace extension;

using namespace prismdll;
using namespace prismdll::layers;

bool CreatorOptionsLayer::init() {
	auto winSize = CCDirector::sharedDirector()->getWinSize();

	if (!this->initWithColor({ 0, 0, 0, 75 })) return false;

	auto bg = CCScale9Sprite::create("GJ_square01.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg->setContentSize({ 360.0f, 260.0f });
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	m_pLayer->addChild(bg);

	m_pButtonMenu = CCMenu::create();
	m_pLayer->addChild(m_pButtonMenu);

	auto title = CCLabelBMFont::create("Options", "goldFont.fnt");
	title->setScale(0.9f);
	title->setPosition(winSize.width / 2, winSize.height / 2 + 110.0f);
	m_pLayer->addChild(title);

	auto creatorManager = CreatorOptionsManager::sharedManager();

	this->addToggle("Object Bypass",
		creatorManager->m_objectBypass,
		"Increases the object limit in the level editor.\n"
		"Disable if performance is lost while playing.");

	auto closeBtn = gd::CCMenuItemSpriteExtra::create(
		CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
		this,
		(SEL_MenuHandler)&CreatorOptionsLayer::onClose
	);
	m_pButtonMenu->addChild(closeBtn);
	closeBtn->setPosition(
		closeBtn->convertToNodeSpace({ (winSize.width / 2) - 198.0f, (winSize.height / 2) + 102.0f })
	);
	closeBtn->setSizeMult(1.5f);

	this->setKeypadEnabled(true);
	this->setTouchEnabled(true);
	return true;
}

CreatorOptionsLayer::CreatorOptionsLayer() {
	m_fLastX = -140.0f;
	m_fLastY = 65.0f;

	m_pLayer = CCLayer::create();
	this->addChild(m_pLayer);
}

void CreatorOptionsLayer::onClose(cocos2d::CCObject*) {
	this->setKeypadEnabled(false);
	this->removeFromParentAndCleanup(true);
}

void CreatorOptionsLayer::addToggle(const char* title, bool& toggle, const char* description) {

	if (m_fLastY <= -100.0f) {
		m_fLastY = 65.0f;
		m_fLastX += 170.0f;
	}
	if (m_fLastX >= 40.0f) {
		//handle this when u have >10 settings
	}

	auto offSprite = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
	offSprite->setScale(0.75f);
	auto onSprite = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
	onSprite->setScale(0.75f);
	auto toggler = gd::CCMenuItemToggler::create(
		offSprite,
		onSprite,
		this,
		(SEL_MenuHandler)&CreatorOptionsLayer::toggleToggler
	);
	toggler->setUserData(&toggle);
	//idk why this doesnt work
	toggler->toggle(toggle);
	toggler->setPosition(0.0f + m_fLastX, 0.0f + m_fLastY);
	m_pButtonMenu->addChild(toggler);

	if (description) {
		auto infoSprite = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
		infoSprite->setScale(0.5f);
		auto info = gd::CCMenuItemSpriteExtra::create(
			infoSprite,
			this,
			(SEL_MenuHandler)&CreatorOptionsLayer::viewTogglerDescription
		);
		//i know this isn't gonna be modified anyway
		info->setUserData(const_cast<char*>(description));
		info->setPosition(-20.0f + m_fLastX, 20.0f + m_fLastY);
		m_pButtonMenu->addChild(info);
	}

	auto label = CCLabelBMFont::create(title, "bigFont.fnt");
	label->setPosition(75.0f + m_fLastX, 0.0f + m_fLastY);
	label->limitLabelWidth(110.0f, 15.0f, 0.0f);
	m_pButtonMenu->addChild(label);

	m_fLastY -= 40.0f;
}

void CreatorOptionsLayer::toggleToggler(cocos2d::CCObject* toggler) {
	bool* toggle = static_cast<bool*>(static_cast<CCNode*>(toggler)->getUserData());
	*toggle = !*toggle;
}

void CreatorOptionsLayer::viewTogglerDescription(cocos2d::CCObject* info) {
	gd::FLAlertLayer::create(nullptr, "Info", "Ok", 0, 425.0f,
		static_cast<const char*>(static_cast<CCNode*>(info)->getUserData()))->show();
}

CreatorOptionsLayer* CreatorOptionsLayer::create() {
	CreatorOptionsLayer* pRet = new CreatorOptionsLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return nullptr;
	}
}
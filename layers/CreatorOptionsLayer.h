#ifndef __LOADEROPTIONSLAYER_H__
#define __LOADEROPTIONSLAYER_H__

#include "../pch.h"
#include "../util/CreatorOptionsManager.h"
#include <gd.h>

class CreatorOptionsLayer : public gd::FLAlertLayer {
protected:
	float m_fLastX;
	float m_fLastY;

protected:
	virtual bool init();

	CreatorOptionsLayer();

	void onClose(cocos2d::CCObject*);

	void addToggle(const char* title, bool& toggle, const char* description);
	void toggleToggler(cocos2d::CCObject* toggler);
	void viewTogglerDescription(cocos2d::CCObject* info);

public:
	static CreatorOptionsLayer* create();
};

#endif
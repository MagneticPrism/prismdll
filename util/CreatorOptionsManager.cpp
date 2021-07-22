#include "../pch.h"
#include "CreatorOptionsManager.h"

using namespace cocos2d;



bool CreatorOptionsManager::init()
{
	return true;
}

CreatorOptionsManager* CreatorOptionsManager::sharedManager() {
	if (!s_sharedCreatorOptionsManager) {
		s_sharedCreatorOptionsManager = new CreatorOptionsManager();
		s_sharedCreatorOptionsManager->init();
	}

	return s_sharedCreatorOptionsManager;
}

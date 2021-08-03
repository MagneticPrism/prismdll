#include "../pch.h"
#include "CreatorOptionsManager.h"
#include "Mod.h"

using namespace cocos2d;

bool CreatorOptionsManager::init()
{
	if (m_objectBypass)
	{
		writeMemory(0x73169, { 0xFF, 0xFF, 0xFF, 0x7F });
		writeMemory(0x856A4, { 0xFF, 0xFF, 0xFF, 0x7F });
		writeMemory(0x87B17, { 0xFF, 0xFF, 0xFF, 0x7F });
		writeMemory(0x87BC7, { 0xFF, 0xFF, 0xFF, 0x7F });
		writeMemory(0x87D95, { 0xFF, 0xFF, 0xFF, 0x7F });
		writeMemory(0x880F4, { 0xFF, 0xFF, 0xFF, 0x7F });
		writeMemory(0x160B06, { 0xFF, 0xFF, 0xFF, 0x7F });
	}
	else
	{
		writeMemory(0x73169, { 0x80, 0x38, 0x01, 0x00 });
		writeMemory(0x856A4, { 0x80, 0x38, 0x01, 0x00 });
		writeMemory(0x87B17, { 0x80, 0x38, 0x01, 0x00 });
		writeMemory(0x87BC7, { 0x80, 0x38, 0x01, 0x00 });
		writeMemory(0x87D95, { 0x80, 0x38, 0x01, 0x00 });
		writeMemory(0x880F4, { 0x80, 0x38, 0x01, 0x00 });
		writeMemory(0x160B06, { 0x80, 0x38, 0x01, 0x00 });
	}

	return true;
}

void CreatorOptionsManager::encodeDataTo(DS_Dictionary* data)
{
	data->setBoolForKey("objectBypass", m_objectBypass);
}

void CreatorOptionsManager::dataLoaded(DS_Dictionary* data) 
{
	data->getBoolForKey("objectBypass");
}

CreatorOptionsManager* CreatorOptionsManager::sharedManager() {
	if (!s_sharedCreatorOptionsManager) {
		s_sharedCreatorOptionsManager = new CreatorOptionsManager();
		s_sharedCreatorOptionsManager->init();
	}

	return s_sharedCreatorOptionsManager;
}

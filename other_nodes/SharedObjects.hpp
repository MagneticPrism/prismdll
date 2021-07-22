#pragma once

#include "../layers/GameInGDLayer.h"
#include "../layers/MenuLayer.hpp"

class SharedObjects : public CCNode, GameInGDLayer, ChangeTextButton, prismdll::MenuLayer
{
	static GameInGDLayer m_GameInGDLayer*;
	static ChangeTextButton m_ChangeTextButton*;
	static MenuLayer m_MenuLayer*;
public:
	static GameInGDLayer* getGameInGDLayerClass() { return m_GameInGDLayer; }
	static ChangeTextButton* getCallBackClass() { return m_ChangeTextButton; }
	static MenuLayer* getMenuLayerClass() { return m_MenuLayer; }
};

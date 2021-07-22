#ifndef __LOADERMANAGER_H__
#define __LOADERMANAGER_H__

#include "../pch.h"
#include <gd.h>

class CreatorOptionsManager : public gd::GManager {
protected:
	static inline CreatorOptionsManager* s_sharedCreatorOptionsManager = nullptr;

public:
	bool m_objectBypass;
protected:
	virtual bool init();
public:
	static CreatorOptionsManager* sharedManager();
};

#endif
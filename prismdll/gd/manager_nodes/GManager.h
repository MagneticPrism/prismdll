#ifndef __GMANAGER_H__
#define __GMANAGER_H__

#include <gd.h>

class DS_Dictionary;

namespace gd {

	enum IconType {
		kIconTypeCube = 0,
		kIconTypeShip = 1,
		kIconTypeBall = 2,
		kIconTypeUfo = 3,
		kIconTypeWave = 4,
		kIconTypeRobot = 5,
		kIconTypeSpider = 6,
		kIconTypeDeathEffect = 98,
		kIconTypeSpecial = 99,
	};

	enum UnlockType {
		kUnlockTypeUnknown = 0,
		kUnlockTypeCube = 1,
		kUnlockTypeColor1 = 2,
		kUnlockTypeColor2 = 3,
		kUnlockTypeShip = 4,
		kUnlockTypeBall = 5,
		kUnlockTypeUfo = 6,
		kUnlockTypeWave = 7,
		kUnlockTypeRobot = 8,
		kUnlockTypeSpider = 9,
		kUnlockTypeSpecial = 10,
		kUnlockTypeDeathEffect = 11,
		kUnlockTypeGlow = 12,
	};

	class GManager : public cocos2d::CCNode {
	protected:
		std::string m_sFileName;
		bool m_bSetup;
		bool m_bSaved;

	public:
		void save() {
			return reinterpret_cast<void(__thiscall*)(GManager*, std::string)>(
				base + 0x29250
				)(this, m_sFileName);
		}
		virtual void setup() {
			return reinterpret_cast<void(__thiscall*)(GManager*)>(
				base + 0x28F60
				)(this);
		}
		virtual void encodeDataTo(DS_Dictionary* data) {}
		virtual void dataLoaded(DS_Dictionary* data) {}
		virtual void firstLoad() {}
	};
}

#endif
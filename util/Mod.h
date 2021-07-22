#pragma once
#include <cocos2d.h>

#include <gd.h>

namespace prismdll
{
	class Mod : public cocos2d::CCNode
	{
	public:
		static void startHooks();

		static void iconInit();

        std::vector<uint8_t> Base64Encoder(const std::vector<uint8_t>& data);

        std::string Base64Decoder(const std::string& data);
	};

    namespace decoder
    {
        std::vector<uint8_t> Convert(const std::string& _data);

        std::string Convert(const std::vector<uint8_t>& _data);

        std::vector<uint8_t> Base64X(const std::vector<uint8_t>& _data);
    }
}

inline bool writeMemory(
    uintptr_t const address,
    std::vector<uint8_t> const& bytes
) {
    return WriteProcessMemory(
        GetCurrentProcess(),
        reinterpret_cast<LPVOID>(gd::base + address),
        bytes.data(),
        bytes.size(),
        nullptr
    );
}

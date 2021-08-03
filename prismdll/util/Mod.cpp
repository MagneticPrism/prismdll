#include "Mod.h"
#include "Base64.hpp"
#include "../pch.h"
#include "../layers/MenuLayer.hpp"
#include "../other_nodes/AnimatedShopKeeper.hpp"
#include "../other_nodes/GJItemIcon.hpp"
#include "../other_nodes/GameManager.hpp"

using namespace prismdll;

void Mod::startHooks()
{
    Mod::iconInit();

	layers::MenuLayer::loadHook();

    GameManager::loadHook();

    GJItemIcon::loadHook();
}

void Mod::iconInit() {
    writeMemory(0x12BE64, { 0xB9, 0x8e });
    writeMemory(0x12B099, { 0x8e });
    writeMemory(0x12C766, { 0x8e });
}

std::vector<uint8_t> Mod::Base64Encoder(const std::vector<uint8_t>& _data)
{
    gdcrypto::base64::Base64 b64(gdcrypto::base64::URL_SAFE_DICT);

    std::string data = b64.encode(_data);

    return decoder::Convert(data);
}

std::string Mod::Base64Decoder(const std::string& _data) 
{
    gdcrypto::base64::Base64 b64(gdcrypto::base64::URL_SAFE_DICT);

    std::vector<uint8_t> data = b64.decode(_data);

    return decoder::Convert(data);
}

std::vector<uint8_t> decoder::Base64X(const std::vector<uint8_t>& _data) 
{
    gdcrypto::base64::Base64 b64(gdcrypto::base64::URL_SAFE_DICT);
    return b64.decode(_data);
}

std::vector<uint8_t> decoder::Convert(const std::string& _data) 
{
    return std::vector<uint8_t>(_data.begin(), _data.end());
}

std::string decoder::Convert(const std::vector<uint8_t>& _data) 
{
    return std::string(_data.begin(), _data.end());
}

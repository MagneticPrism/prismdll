#pragma once

#include "../pch.h"
#include "../menu_nodes/HorizontalSelectMenu.hpp"
#include <string>
#include <fstream>
#include "HackOptionsLayer.h"
#include "../util/CCDirectorModified.h"
#include "CreatorOptionsLayer.h"
#include "../util/Mod.h"

namespace prismdll 
{
    namespace layers
    {
        class MenuLayer : public cocos2d::CCLayer, FLAlertLayerProtocol
        {
        protected:
            static inline bool(__thiscall* init)(MenuLayer*);
            static bool __fastcall initHook(MenuLayer* self)
            {
                if (!init(self)) return false;

                auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

                auto menu = cocos2d::CCMenu::create();

                auto buttonSprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");

                auto button = gd::CCMenuItemSpriteExtra::create(buttonSprite, self, (cocos2d::SEL_MenuHandler)&MenuLayer::onModInfo);

                button->setPosition(265, 142.5f);

                menu->addChild(button);

                auto buttonSprite1 = gd::ButtonSprite::create("Test", 0, false, "goldFont.fnt", "GJ_button_01.png", 0, 0.8f);

                auto button1 = gd::CCMenuItemSpriteExtra::create(buttonSprite1, self, (cocos2d::SEL_MenuHandler)&MenuLayer::onTestSceneOpen);

                button1->setPositionY(-70);

                menu->addChild(button1);

                auto buttonSprite2 = gd::ButtonSprite::create("Log File", 0, false, "goldFont.fnt", "GJ_button_01.png", 0, 0.8f);

                auto button2 = gd::CCMenuItemSpriteExtra::create(buttonSprite2, self, (cocos2d::SEL_MenuHandler)&MenuLayer::onLogDataInfo);

                button2->setPositionX(-220);

                menu->addChild(button2);

                auto buttonSprite3 = gd::ButtonSprite::create("Decode Log File", 0, false, "goldFont.fnt", "GJ_button_01.png", 0, 0.8f);

                auto button3 = gd::CCMenuItemSpriteExtra::create(buttonSprite3, self, (cocos2d::SEL_MenuHandler)&MenuLayer::decodeLogData);

                button3->setPosition(-220, 20);

                menu->addChild(button3);

                self->addChild(menu);

                return true;
            }

            static inline void(__thiscall* FLAlert_Clicked)(MenuLayer*, gd::FLAlertLayer*, bool);
            static void __fastcall FLAlert_ClickedHook(MenuLayer* self, uintptr_t /* skip edx register */, gd::FLAlertLayer* layer, bool btn2)
            {
                auto alert = reinterpret_cast<gd::FLAlertLayer*>(layer);

                if (alert->getTag() == 100)
                {
                    if (btn2)
                    {
                        CCDirector* director = CCDirector::sharedDirector();

                        CCScene* wrapperScene = CCScene::create();

                        wrapperScene->addChild(HackOptionsLayer::create());

                        auto transition = CCTransitionFade::create(0.5f, wrapperScene);

                        director->pushScene(transition);
                    }
                }
                else
                {
                    FLAlert_Clicked(self, layer, btn2);
                }
            }

        public:
            void onCreatorHacksLayer(cocos2d::CCObject*)
            {
                auto alert = gd::FLAlertLayer::create(this,
                    "Mod Info",
                    "Close",
                    "Open",
                    460.0f,
                    "This is a beta version of creator hacks. Note that hacks arent implemented yet."  \
                );

                alert->setTag(110);

                alert->show();
            }

            void onModInfo(cocos2d::CCObject*)
            {
                gd::FLAlertLayer::create(0,
                    "Mod Info",
                    "Close",
                    nullptr,
                    460.0f,
                    "This <cg>Mod</c> was developed by <cb>MagneticPrism</c>.\n"  \
                    "You can join her <cl>Discord</c> server here:\n" \
                    "https://discord.gg/\n" \
                    "You can also visit MagneticPrism's <cl>Github</c> here:\n" \
                    "https://github.com/MagneticPrism\r" \
                )->show();
            }

            void onLogDataInfo(CCObject*)
            {
                gd::FLAlertLayer::create(0,
                    "Mod Info",
                    "Close",
                    nullptr,
                    460.0f,
                    "This currently does nothing because log data is disabled for now.\n"  \
                )->show();
            }

            void onTestSceneOpen(CCObject*)
            {
                auto alert = gd::FLAlertLayer::create(this,
                    "Mod Info",
                    "Close",
                    "Ok",
                    460.0f,
                    "This button will take you to a new scene.\n" \
                    "Althugh it does not do anything useful.\n" \
                    "You can view the scene by clicking the <cg>Ok</c> button." \
                );

                alert->setTag(100);

                alert->show();
            }

            void decodeLogData(cocos2d::CCObject*)
            {
                gd::FLAlertLayer::create(0,
                    "Mod Info",
                    "Close",
                    nullptr,
                    460.0f,
                    "This currently does nothing because log data is disabled for now.\n"  \
                )->show();
            }

            static bool saveData(const std::string& _path, std::vector<std::string> const& _bytes) {
                std::ofstream file;
                file.open(_path, std::ios::out | std::ios::binary);
                if (file.is_open()) {
                    file.write(reinterpret_cast<const char*>(_bytes.data()), _bytes.size());
                    file.close();

                    return true;
                }
                file.close();
                return false;
            }

            static bool saveData(const std::string& _path, std::string const& _bytes) {
                std::ofstream file;
                file.open(_path, std::ios::out | std::ios::binary);
                if (file.is_open()) {
                    file.write(reinterpret_cast<const char*>(_bytes.data()), _bytes.size());
                    file.close();

                    return true;
                }
                file.close();
                return false;
            }

            static bool saveData(const std::string& _path, std::vector<uint8_t> const& _bytes) {
                std::ofstream file;
                file.open(_path, std::ios::out | std::ios::binary);
                if (file.is_open()) {
                    file.write(reinterpret_cast<const char*>(_bytes.data()), _bytes.size());
                    file.close();

                    return true;
                }
                file.close();
                return false;
            }

            static std::string decodeDataString(const std::string& _path) {
                std::ifstream in(_path, std::ios::in | std::ios::binary);
                if (in)
                    return std::string(std::istreambuf_iterator<char>(in), {});
                return {};
            }

            static std::vector<uint8_t> decodeDataVector(const std::string& _path) {
                std::ifstream in(_path, std::ios::in | std::ios::binary);
                if (in)
                    return std::vector<uint8_t>(std::istreambuf_iterator<char>(in), {});
                return {};
            }

            static void loadHook()
            {
                MH_CreateHook(
                    (PVOID)(gd::base + 0x1907b0),
                    (LPVOID)MenuLayer::initHook,
                    (LPVOID*)&MenuLayer::init
                );

                MH_CreateHook(
                    (PVOID)(gd::base + 0x192150),
                    (LPVOID)MenuLayer::FLAlert_ClickedHook,
                    (LPVOID*)&MenuLayer::FLAlert_Clicked
                );
            }
        };
    }
}

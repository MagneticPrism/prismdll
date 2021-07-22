#pragma once

#include <gd.h>

namespace prismdll
{
    class TestAlertProtocol : public gd::FLAlertLayerProtocol
    {
    public:
        int test;
        PAD(100);
        std::string string;
    public:
        virtual void FLAlert_Clicked(gd::FLAlertLayer* layer, bool btn2)
        {
            auto alert = reinterpret_cast<gd::FLAlertLayer*>(layer);

            if (alert->getTag() == 100)
            {
                if (btn2)
                {
                }
            }
            else
            {
                FLAlert_Clicked(layer, btn2);
            }
        }
    };

}
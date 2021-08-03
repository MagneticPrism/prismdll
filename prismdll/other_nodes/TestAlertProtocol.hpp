#pragma once

#include <gd.h>
#include "../layers/CreatorOptionsLayer.h"

namespace prismdll
{
    class TestAlertProtocol : public gd::FLAlertLayerProtocol
    {
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

            if (alert->getTag() == 110)
            {
                if (btn2)
                {
                    prismdll::layers::CreatorOptionsLayer::create()->show();
                }
            }
            else
            {
                FLAlert_Clicked(layer, btn2);
            }
        }
    };
}
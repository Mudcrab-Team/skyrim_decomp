// Source exposure: mixed
// Code origin: original reconstruction from the pinned image listing, shaped after the sibling.
// 0x5c9560 LightEffect::Update
// Adapted bodies: LightEffect::Update follows momusdigital/fnv_decomp@91e1b6e8 src/fallout/magic/lighteffect.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout/magic/lighteffect.cpp:62
#include "LightEffect_5c9560.h"

void LightEffect::Update(float)
{
    if (light) {
        ShadowSceneNode* node = defaultShadowScene;
        if (node) {
            if (!node->FindActiveLight(light.get())) {
                node->AddLight(light.get(), true);
            }
        }
    } else if (Actor* actor = GetTargetActor()) {
        AttachBestLightEffect(&actor->magicTarget);
    }
}

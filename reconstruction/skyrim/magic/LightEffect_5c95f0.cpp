// Source exposure: mixed
// Code origin: original reconstruction from the pinned image listing, shaped after the sibling.
// 0x5c95f0 LightEffect::Finish
// Adapted bodies: LightEffect::Finish follows momusdigital/fnv_decomp@91e1b6e8 src/fallout/magic/lighteffect.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout/magic/lighteffect.cpp:171
#include "LightEffect_5c95f0.h"

void LightEffect::Finish()
{
    DetachLight();
    Actor* actor = GetTargetActor();
    if (actor) {
        AttachBestLightEffect(&actor->magicTarget);
    }
    if (spell->GetDelivery() != MagicSystem::Delivery::kSelf) {
        PlayerCharacter::singleton->SetLightTarget(nullptr);
    }
}

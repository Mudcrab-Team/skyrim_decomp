// Source exposure: mixed
// Code origin: original reconstruction from the pinned image listing, shaped after the sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x6d4510 Actor::SetAlpha
// Adapted bodies: Actor::SetAlpha follows momusdigital/fnv_decomp@91e1b6e8 src/fallout/ai/actor_magic.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout/ai/actor_magic.cpp:590
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Magic.cpp:314
#include "Actor_6d4510.h"

void Actor::SetAlpha(float a_alpha)
{
    if (GetProcessLevel() == 0) {
        currentProcess->SetMaxAlpha(a_alpha);
        NiAVObject* object;
        if (this == playerSingleton) {
            object = Get3D1(false);
            if (object) {
                object->fadeAmount = a_alpha;
            }
            object = Get3D1(true);
        } else {
            object = Get3D2();
        }
        if (object) {
            object->fadeAmount = a_alpha;
        }
    }
}

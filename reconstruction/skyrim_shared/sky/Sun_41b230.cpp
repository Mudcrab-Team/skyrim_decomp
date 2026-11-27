// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x41b230 Sun::Function41b230
#include "Sun_41b230.h"

float Sun::Function41b230()
{
    SunNode* node = unk30->unk128;
    if (node && node->GetRTTI() == &kLightType)
    {
        LightNode* light = static_cast<LightNode*>(unk30->unk128);
        if (light)
        {
            return light->unk94;
        }
    }
    return 0.0f;
}

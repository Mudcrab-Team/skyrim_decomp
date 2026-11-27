// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the pinned listing for 0x41cbb0; no adapted bodies.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x41cbb0 Sun::GetSunPositionData
#include "Sun.h"

// kDefaultSunX, kDefaultSunY, kDefaultSunZ: GUESS(low); the listing does not give these values.
float kDefaultSunX = 0.5f;
float kDefaultSunY = 0.25f;
float kDefaultSunZ = 0.75f;

void Sun::GetSunPositionData(NiPoint3* a_out)
{
    NiNode* node = this->root._ptr;
    if (node != nullptr)
    {
        a_out->x = node->translate.x;
        a_out->y = node->translate.y;
        a_out->z = node->translate.z;
        return;
    }
    a_out->x = kDefaultSunX;
    a_out->y = kDefaultSunY;
    a_out->z = kDefaultSunZ;
}

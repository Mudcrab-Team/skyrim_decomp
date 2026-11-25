// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original handwritten reconstruction
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xee0f70 NiAVObject::ProcessClone
#include "NiAVObject_ee0f70.h"

void NiAVObject::ProcessClone(NiCloningProcess& cloning)
{
    NiObjectNET::ProcessClone(cloning);
    if (collisionObject)
        collisionObject->ProcessClone(cloning);
}

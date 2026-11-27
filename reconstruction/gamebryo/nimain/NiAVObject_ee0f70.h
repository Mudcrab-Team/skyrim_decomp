// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original handwritten reconstruction
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject::ProcessClone, NiAVObject::collisionObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject::unknown30: GUESS(low)
#pragma once
#include <cstdint>
#include "declarations/NiObjectNET.h"

class NiAVObject : public NiObjectNET
{
public:
    void ProcessClone(NiCloningProcess& cloning) override;
    std::uint8_t unknown30[0x10];
    NiObject* collisionObject;  // Minimal view of the collision object reference.
};

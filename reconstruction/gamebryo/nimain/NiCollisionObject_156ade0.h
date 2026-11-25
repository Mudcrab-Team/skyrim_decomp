// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; body reconstructed from local target observations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCollisionObject, NiCollisionObject::RegisterStreamables, sceneObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include "declarations/NiAVObject.h"
#include <cstddef>
class NiCollisionObject : public NiObject
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    NiAVObject* sceneObject;
};
static_assert(offsetof(NiCollisionObject, sceneObject) == 0x10, "scene object offset");

// CastToSkinInstance: GUESS(low)
// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x21cba0 NiAVObject::Function21cba0
// Adapted bodies: none
#include "NiAVObject_21cba0.h"

static NiObject* CastToSkinInstance(NiObject* skin)
{
    bool matches;
    if (!skin) {
        matches = false;
    } else {
        matches = skin->GetRTTI() == &g_skinInstanceRTTI;
    }
    if (matches) return skin;
    return nullptr;
}

NiObject* NiAVObject::Function21cba0(NiObject* object)
{
    if (!object || !object->AsGeometry()) {
        return nullptr;
    }
    return CastToSkinInstance(static_cast<BSGeometry*>(object)->skinInstance);
}

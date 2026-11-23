// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x21cc10 NiAVObject::Function21cc10
// Adapted bodies: none
#include "NiAVObject_21cc10.h"

// CastToSkinInstance: GUESS(low)
static SkinInstance* CastToSkinInstance(NiObject* skin)
{
    bool matches;
    if (!skin) matches = false;
    else matches = skin->GetRTTI() == &g_skinInstanceRTTI;
    if (matches) return static_cast<SkinInstance*>(skin);
    return nullptr;
}

SkinInstance* NiAVObject::Function21cc10(NiObject* object)
{
    if (!object || !object->AsGeometry()) {
        return nullptr;
    }
    SkinInstance* cast = CastToSkinInstance(static_cast<BSGeometry*>(object)->skinInstance);
    if (!cast) return nullptr;
    if ((cast->flags & 0x400) > 0) return cast;
    if ((cast->flags & 0x200000) > 0) return cast;
    return nullptr;
}

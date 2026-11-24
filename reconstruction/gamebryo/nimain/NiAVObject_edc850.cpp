// Source exposure: mixed (sibling source and pinned image listing).
// Code origin: original reconstruction shaped after the cited sibling method.
// Adapted bodies: NiAVObject::Clone follows momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00a40000_o2.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00a40000_o2.cpp:3206
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xedc850 NiAVObject::Clone
#include "NiAVObject_edc850.h"

NiAVObject* NiAVObject::Clone()
{
    NiCloningProcess cloning;
    NiObject* clone = CreateClone(cloning);
    ProcessClone(cloning);
    return static_cast<NiAVObject*>(clone);
}

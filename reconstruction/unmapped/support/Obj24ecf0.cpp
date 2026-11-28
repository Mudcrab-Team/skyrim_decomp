// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Map24ecf0::GetAt, treated as adapted: shaped like NiTMapBase::GetAt in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:6
// SPDX-License-Identifier: CC0-1.0
// 0x24ecf0 Obj24ecf0::Dispatch
#include "Obj24ecf0.h"

// Look up a key in the map, dispatch the handler if found, and finish.
bool Obj24ecf0::Dispatch(void* ctx, const void* key)
{
    context = ctx;
    bool result = false;
    flag08 = false;
    void* value = nullptr;
    if (map.GetAt(key, value) && value != nullptr)
    {
        result = OnFound(value);
    }
    OnFinish();
    return result;
}

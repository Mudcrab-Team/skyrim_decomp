// Source exposure: mixed (community headers; the pinned image listing; sibling decompilation shape).
// Code origin: adapted from the sibling decompilation; adapted bodies: Unk360c20::Function360c20.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00500000_o2.cpp:6966
// 0x360c20 Unk360c20::Function360c20
#include "Unk360c20_360c20.h"

// Resolves a value and a scale through the lookup helper and applies them when it succeeds.
bool Unk360c20::Function360c20(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7, void* a8)
{
    void* value = nullptr;
    float scale = 1.0f;
    if (!ResolveLookupParameter(a1, a2, a8, a3, a4, a5, a6, &value, &scale))
    {
        return false;
    }
    ApplyLookupScale(value, scale, nullptr);
    return true;
}

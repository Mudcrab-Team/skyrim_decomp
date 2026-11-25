// Source exposure: mixed (community headers; the pinned image listing; sibling decompilation shape).
// Code origin: adapted from the sibling decompilation; adapted bodies: Unk35d370::Function35d370.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00500000_o2.cpp:5346
// 0x35d370 Unk35d370::Function35d370
#include "Unk35d370_35d370.h"

// Resolves a value through the lookup helper and falls back to the player's base when it yields none.
bool Unk35d370::Function35d370(void* a1, void* a2, void* object, void* a4, void* a5, void* a6, double* out, void* a8)
{
    *out = 0;
    TESBoundObject* value = nullptr;
    if (!ResolveLookupParameter(a1, a2, a8, object, a4, a5, a6, &value))
    {
        return false;
    }
    if (!value)
    {
        value = PlayerCharacter::singleton->data.objectReference;
    }
    ApplyLookupValue(object, value, 0, out);
    return true;
}

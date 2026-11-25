// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction; IsKindOf helper adapted from the CC0 sibling.
// IsKindOf: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00b40000_o2.cpp:14582
// Adapted bodies: IsKindOf
// 0x2163f0 DynamicCastLeaf2163f0::Cast
#include "DynamicCastLeaf2163f0_2163f0.h"

static bool IsKindOf(const CastTypeLeaf2163f0* current, const CastTypeLeaf2163f0* type)
{
    while (current) {
        if (current == type) {
            return true;
        }
        current = current->parent;
    }
    return false;
}

CastObjectLeaf2163f0* DynamicCastLeaf2163f0::Cast(const CastTypeLeaf2163f0* type, CastObjectLeaf2163f0* object)
{
    if (!object) {
        return nullptr;
    }
    return IsKindOf(object->GetType(), type) ? object : nullptr;
}

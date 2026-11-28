// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x155ea0 Function155ea0
// Adapted bodies: none
#include "FreeFunction_155ea0.h"

// Returns true when rhs is null or any of key, id, or weight differs from lhs.
bool Function155ea0(const Record155ea0* lhs, const Record155ea0* rhs)
{
    if (rhs == nullptr)
    {
        return true;
    }
    if (lhs->key != rhs->key)
    {
        return true;
    }
    if (lhs->id != rhs->id)
    {
        return true;
    }
    return lhs->weight != rhs->weight;
}

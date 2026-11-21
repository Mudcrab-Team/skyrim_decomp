// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x89dc50 ClassTypeLeaf89dc50::QClassType
#include "ClassTypeLeaf89dc50.h"

// Return the lazily constructed class type descriptor.
ClassTypeLeaf89dc50::Type* ClassTypeLeaf89dc50::QClassType()
{
    static Type instance("CombatBehaviorTreeNodeObject");
    return &instance;
}

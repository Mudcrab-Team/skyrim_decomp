// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x89dce0 ClassTypeLeaf89dce0::QClassType
#include "ClassTypeLeaf89dce0.h"

// Return the lazily constructed class type descriptor.
ClassTypeLeaf89dce0::Type* ClassTypeLeaf89dce0::QClassType()
{
    static Type instance("CombatBehaviorTreeNodeObject");
    return &instance;
}

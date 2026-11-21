// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x89daa0 ClassTypeLeaf89daa0::QClassType
#include "ClassTypeLeaf89daa0.h"

// Return the lazily constructed class type descriptor.
ClassTypeLeaf89daa0::Type* ClassTypeLeaf89daa0::QClassType()
{
    static Type instance("CombatBehaviorTreeConditionalNode");
    return &instance;
}

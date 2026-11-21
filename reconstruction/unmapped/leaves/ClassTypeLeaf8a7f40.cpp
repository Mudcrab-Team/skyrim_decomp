// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8a7f40 ClassTypeLeaf8a7f40::QClassType
#include "ClassTypeLeaf8a7f40.h"

// Return the lazily constructed class type descriptor.
ClassTypeLeaf8a7f40::Type* ClassTypeLeaf8a7f40::QClassType()
{
    static Type instance("CombatBehaviorTreeCreateContextNode");
    return &instance;
}

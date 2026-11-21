// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x89db30 ClassTypeLeaf89db30::QClassType
#include "ClassTypeLeaf89db30.h"

// Return the lazily constructed class type descriptor.
ClassTypeLeaf89db30::Type* ClassTypeLeaf89db30::QClassType()
{
    static Type instance("CombatBehaviorTreeCreateContextNode");
    return &instance;
}

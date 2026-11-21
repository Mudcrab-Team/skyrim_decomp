// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8a8060 ClassTypeLeaf8a8060::QClassType
#include "ClassTypeLeaf8a8060.h"

// Return the lazily constructed class type descriptor.
ClassTypeLeaf8a8060::Type* ClassTypeLeaf8a8060::QClassType()
{
    static Type instance("CombatBehaviorTreeNodeEvaluateFunction");
    return &instance;
}

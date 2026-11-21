// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8a8180 ClassTypeLeaf8a8180::QClassType
#include "ClassTypeLeaf8a8180.h"

// Return the lazily constructed class type descriptor.
ClassTypeLeaf8a8180::Type* ClassTypeLeaf8a8180::QClassType()
{
    static Type instance("CombatBehaviorTreeNodeEvaluateFunction");
    return &instance;
}

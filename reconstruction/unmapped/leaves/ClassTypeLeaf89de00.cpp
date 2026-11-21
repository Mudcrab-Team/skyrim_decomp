// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x89de00 ClassTypeLeaf89de00::QClassType
#include "ClassTypeLeaf89de00.h"

// Return the lazily constructed class type descriptor.
ClassTypeLeaf89de00::Type* ClassTypeLeaf89de00::QClassType()
{
    static Type instance("CombatBehaviorTreeNodeObject");
    return &instance;
}

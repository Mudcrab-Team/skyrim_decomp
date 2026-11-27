// Source exposure: binary-analysis (class names from the image's RTTI; the destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// RVA 0x87c0b0, 64 bytes: CombatBehaviorTreeNodeObject2 scalar deleting destructor; the member and base destructors stay out of line.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x87c0b0 ??_GCombatBehaviorTreeNodeObject2@@UEAAPEAXI@Z
#include "CombatBehaviorTreeNodeObject2_87c0b0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
CombatBehaviorTreeNodeObject2::CombatBehaviorTreeNodeObject2()
{
}

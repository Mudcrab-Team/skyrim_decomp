// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x80f970, 62 bytes: CombatAreaHoldPosition scalar deleting destructor; the inline destructors chain to the out-of-line CombatObject destructor.
// Adapted bodies: none
// CI hash: 0x80f970 ??_GCombatAreaHoldPosition@@UEAAPEAXI@Z
#include "CombatAreaHoldPosition_80f970.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
CombatAreaHoldPosition::CombatAreaHoldPosition()
{
}

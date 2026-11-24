// Source exposure: binary-analysis (sizes and the destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// RVA 0x1386ec0, 56 bytes: CombatTargetReservation scalar deleting destructor; the member destructor stays out of line and the class stores no vftable of its own.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x1386ec0 ??_GCombatTargetReservation@@UEAAPEAXI@Z
#include "CombatTargetReservation_1386ec0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
CombatTargetReservation::CombatTargetReservation()
{
}

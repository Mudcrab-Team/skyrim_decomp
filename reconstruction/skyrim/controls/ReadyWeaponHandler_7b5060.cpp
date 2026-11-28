// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x7b5060 ReadyWeaponHandler::CanProcess
#include "ReadyWeaponHandler_7b5060.h"

// Return whether the input event matches the ready-weapon user event.
bool ReadyWeaponHandler::CanProcess(InputEvent* a_event)
{
    return a_event->QUserEvent() == gUserEvents->readyWeapon;
}

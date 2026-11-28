// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x25e600 BGSConstructibleObject::PlayerPassesConditions
// Adapted bodies: none
#include "BGSConstructibleObject_25e600.h"

// Evaluates the constructible object's condition list against the player singleton.
bool BGSConstructibleObject::PlayerPassesConditions() const
{
    if (!conditions.head ||
        conditions.IsTrue(PlayerCharacter25e600::singleton, PlayerCharacter25e600::singleton)) {
        return true;
    }
    return false;
}

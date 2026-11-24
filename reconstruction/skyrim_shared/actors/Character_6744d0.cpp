// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6744d0 Character::IsInCombatOrAlarmed
// Adapted bodies: none
#include "Character_6744d0.h"

bool Character::IsInCombatOrAlarmed() const
{
    bool result = false;
    if (IsInCombat()) {
        result = true;
    } else if (currentProcess) {
        TESPackage* package = currentProcess->currentPackage.package;
        if (package && package->packData.packType == PACKAGE_PROCEDURE_TYPE::kAlarm) {
            result = true;
        }
    }
    return result;
}

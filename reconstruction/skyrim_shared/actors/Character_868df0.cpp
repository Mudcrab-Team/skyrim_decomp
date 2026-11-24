// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x868df0 Character::IsWieldingMeleeOrUnarmed
// Adapted bodies: none
#include "Character_868df0.h"

bool Character::IsWieldingMeleeOrUnarmed()
{
    bool result = false;
    if (currentProcess) {
        TESForm* right = currentProcess->GetEquippedRightHand();
        if (right) {
            if (right->formType == FormType::Weapon) {
                std::int32_t type = static_cast<TESObjectWEAP*>(right)->animationType;
                if (type >= -1 && type <= 6) {
                    result = true;
                }
            }
        } else if (!currentProcess->GetEquippedLeftHand()) {
            result = true;
        }
    }
    return result;
}

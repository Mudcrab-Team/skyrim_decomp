// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x6dd720 Actor::GetItemEquipSlot
// Adapted bodies: none
#include "Actor_6dd720.h"

// Return the equip slot holding the given item on the actor, or null if not equipped in hands or voice.
BGSEquipSlot* Actor::GetItemEquipSlot(void*, Actor* a_actor, TESForm* a_item)
{
    if (a_actor && a_actor->currentProcess) {
        if (a_item == a_actor->currentProcess->GetEquippedRightHand()) {
            return GetRightHandSlot();
        }
        if (a_item == a_actor->currentProcess->GetEquippedLeftHand()) {
            return GetLeftHandSlot();
        }
        if (a_item == a_actor->GetEquippedVoice()) {
            return GetVoiceSlot();
        }
    }
    return nullptr;
}

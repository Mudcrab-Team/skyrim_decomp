// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original body from the pinned image listing; declarations are stand-in guesses.
// 0x82f150 CombatInventoryItemStaff::Function82f150
// Adapted bodies: none for Function82f150.
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// CombatInventoryItemStaff: EXE_RTTI
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#include "CombatInventoryItemStaff.h"

// Body from the pinned image listing; names are stand-ins.
// 0x82f150 CombatInventoryItemStaff::Function82f150
// Adapted bodies: none
std::uint64_t CombatInventoryItemStaff::Function82f150()
{
    if (owner) {
        return owner->value;
    }
    return 0;
}

// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t CombatInventoryItemStaff::GetType() const
{
    return 0x6;
}

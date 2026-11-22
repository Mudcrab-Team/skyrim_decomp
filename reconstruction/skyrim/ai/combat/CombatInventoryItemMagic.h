// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// CombatInventoryItemMagic: EXE_RTTI
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class CombatInventoryItemMagic
{
public:
    virtual std::uint32_t GetType() const;
    // CombatInventoryItemMagic::Function82ed80: GUESS(low); true when both pointers are set
    bool Function82ed80() const;

    // members: GUESS(low); storage at the offsets the compared test reads
    std::uint8_t pad08[0x8];  // 08
    void* member10;           // 10
    std::uint8_t pad18[0x30]; // 18
    void* member48;           // 48
};

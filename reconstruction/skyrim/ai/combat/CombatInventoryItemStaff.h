// Source exposure: mixed (local binary analysis and public names).
// 0x82f150 compared function
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// CombatInventoryItemStaff: EXE_RTTI
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function82f150, owner, OwnerView: GUESS(low); names invented, offsets read from the listing.
struct OwnerView
{
    std::uint8_t unknown00[0x90];  // 00
    std::uint64_t value;           // 90
};

class CombatInventoryItemStaff
{
public:
    virtual std::uint32_t GetType() const;
    std::uint64_t Function82f150();  // compared: 0x82f150

    std::uint8_t unknown08[0x8];  // 08
    OwnerView* owner;             // 10
};

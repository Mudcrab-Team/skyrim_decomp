// Source exposure: mixed (local binary analysis and public names).
// 0x82d6e0 compared function
// Code origin: original reconstruction; body written from the listing.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemRanged: EXE_RTTI
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function82d6e0, padding, member: GUESS(low)
#pragma once

#include <cstdint>

class CombatInventoryItemRanged
{
public:
    virtual std::uint32_t GetType() const;
    void* Function82d6e0() const;

    std::uint8_t padding[0x28];  // 08
    void*        member;         // 30
};

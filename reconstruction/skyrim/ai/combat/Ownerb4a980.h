// Source exposure: mixed (local binary analysis and public names).
// Code origin: original reconstruction; body written from the listing. Stamped as a twin of matched 0x82d6e0 (skyrim/ai/combat/CombatInventoryItemRanged): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionb4a980, Ownerb4a980: GUESS(low) STANDIN
// GetType, padding, member: GUESS(low) STANDIN
#pragma once
#include "CombatInventoryItemRanged.h"

class Ownerb4a980
{
public:
    virtual std::uint32_t GetType() const;
    void* Functionb4a980() const;

    std::uint8_t padding[0x28];  // 08
    void*        member;         // 30
};


// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x38ea80 (skyrim_shared/perks/BGSEntryPointFunctionDataActivateChoice): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSPerk: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Owner159b500: GUESS(low) STANDIN
// perk10, field22, unknown08, unknown18, unknown24: GUESS(low) STANDIN
#pragma once
#include "BGSEntryPointFunctionDataActivateChoice.h"

class Owner159b500 : public BGSEntryPointFunctionData
{
public:
    virtual std::uint16_t Unk_05();
    virtual void SetPerk(BGSPerk* a_perk);
    virtual BGSPerk* GetPerk();

    std::uint8_t unknown08[0x8];  // 08
    BGSPerk* perk10;  // 10
    std::uint8_t unknown18[0xA];  // 18
    std::uint16_t field22;  // 22
    std::uint8_t unknown24[0x4];  // 24
};
static_assert(sizeof(Owner159b500) == 0x28, "Owner159b500 size");

// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x29e6b0 (skyrim_shared/world/BGSLocationRefType): source copied, names replaced by placeholders.
// Owner10ac8d0: GUESS(low) STANDIN
// BGSKeyword: GUESS(low) STANDIN
#pragma once
#include "BGSLocationRefType.h"

class Owner10ac8d0 : public BGSKeyword
{
public:
    virtual ~Owner10ac8d0();
    void InitItemImpl() override;  // 13
    Owner10ac8d0();
};
static_assert(sizeof(Owner10ac8d0) == 0x28, "Owner10ac8d0 size");

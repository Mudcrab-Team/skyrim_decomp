// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0xeebf20 (skyrim/ai/combat/CombatGroupDetectionListener): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Ownercc2ed0: GUESS(low) STANDIN
// DetectionListener, unknown10: GUESS(low) STANDIN
#pragma once
#include "CombatGroupDetectionListener.h"

class Ownercc2ed0 : public DetectionListener
{
public:
    ~Ownercc2ed0() override;  // 00
    virtual void Unk_02();
    virtual void Unk_05(void);  // 01

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0x8];  // 10
};
static_assert(sizeof(Ownercc2ed0) == 0x18, "Ownercc2ed0 size");

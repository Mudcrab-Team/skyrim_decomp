// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and the community declarations only
// CombatGroupDetectionListener, CombatGroupDetectionListener::Unk_02: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low); padding to the class size
#pragma once

#include <cstdint>

class CombatGroupDetectionListener
{
public:
    virtual ~CombatGroupDetectionListener();  // 00
    virtual void Unk_02();  // 01, compared: 0xeebf20

    std::uint8_t unknown08[0x10];  // 08
};
static_assert(sizeof(CombatGroupDetectionListener) == 0x18, "layout");

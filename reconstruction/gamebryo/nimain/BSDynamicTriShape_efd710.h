// Source exposure: mixed (community headers; the pinned image listing)
// Code origin: shape adapted from the community BSSpinLock::Unlock, member offsets checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSDynamicTriShape, UnlockGeometry, pad00, owningThread, lockCount: GUESS(low); stand-in class view, an inlined spin-lock member at 0x168
// Adapted bodies: BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp, MIT) inlined on a member lock.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>

class BSDynamicTriShape
{
public:
    void UnlockGeometry();  // compared: 0xefd710

    std::uint8_t pad00[0x168];  // 00
    std::uint32_t owningThread;  // 168
    std::uint32_t lockCount;     // 16C
};

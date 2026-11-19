// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf5f840 NiInterpController::ResetTimeExtrema
// 0xf5f860 NiInterpController::GetCtlrID
// Adapted bodies: none
#include "NiInterpController.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

void NiInterpController::ResetTimeExtrema()
{
    if (!TestBit(flags, 5)) {
        loKeyTime = 0.0f;
        hiKeyTime = 0.0f;
    }
}

const char* NiInterpController::GetCtlrID()
{
    return nullptr;
}

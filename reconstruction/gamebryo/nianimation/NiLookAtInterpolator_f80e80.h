// Source exposure: mixed (pinned image; cited community declarations and symbol layouts).
// Code origin: original partial declaration from observed fields and cited interfaces
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiLookAtInterpolator, GetActiveTimeRange: CRASHLOGGER_PDB(59818@2026.10.24)
// childInterpolators: GUESS(low)
#pragma once

#include "NiInterpolator.h"

class NiLookAtInterpolator : public NiInterpolator
{
public:
    void GetActiveTimeRange(float& begin, float& end) const override;

private:
    std::uint8_t unknown18[0x38];
    NiInterpolator* childInterpolators[3];
};

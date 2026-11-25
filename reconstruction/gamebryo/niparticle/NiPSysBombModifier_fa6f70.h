// Source exposure: mixed (pinned image; cited community declarations and symbol layouts).
// Code origin: original partial declaration from observed fields and cited interfaces
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysBombModifier, IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// bombObject, bombAxis, decay, deltaV, decayType, symmetryType: GUESS(low)
#pragma once

#include "NiPSysModifier.h"

class NiPSysBombModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* object) override;

private:
    NiObject* bombObject;
    float bombAxis[3];
    float decay;
    float deltaV;
    std::uint32_t decayType;
    std::uint32_t symmetryType;
};
static_assert(sizeof(NiPSysBombModifier) == 0x58, "observed modifier extent");

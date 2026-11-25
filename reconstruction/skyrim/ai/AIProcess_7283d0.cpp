// Source exposure: mixed (community declarations, community PDB names, and local binary analysis).
// Code origin: original handwritten reconstruction from the assigned local listing; minimal declarations use cited name and layout sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7283d0 AIProcess::HasPerkEntries
#include "AIProcess_7283d0.h"

bool AIProcess::HasPerkEntries(std::uint8_t entryPoint) const
{
    if (middleHigh && middleHigh->perkData && entryPoint < 92 &&
        middleHigh->perkData->perkEntryArrays[entryPoint].size > 0) {
        return true;
    }
    return false;
}

// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ExtraAttachedArrows3D, startTime, g_arrowDelay, Function18a870: GUESS(low)
// ExtraAttachedArrows3D::Function18a870: CRASHLOGGER_PDB(59818@2026.10.24); size only
// GetTickCount: OBSERVED; the Windows import the listing calls through the import table
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) std::uint32_t GetTickCount();

extern float g_arrowDelay;

class ExtraAttachedArrows3D
{
public:
    bool Function18a870();  // compared: 0x18a870

    std::uint8_t pad00[0x8];
    std::uint64_t startTime;  // 0x08
};

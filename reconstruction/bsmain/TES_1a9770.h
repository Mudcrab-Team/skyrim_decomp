// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TES, TES::ResetCellTracking, gTrackedCellMinA, gTrackedCellA, gTrackedCellB, gTrackedCellMinB, gTrackedCellCount: GUESS(low); globals at RVAs 0x20776ac, 0x219e5f8, 0x219e600, 0x20776b0, 0x20776b4
#pragma once

#include <cstdint>
#include <cstddef>

extern std::int32_t gTrackedCellMinA;
extern void* gTrackedCellA;
extern void* gTrackedCellB;
extern std::int32_t gTrackedCellMinB;
extern std::int32_t gTrackedCellCount;

class TES
{
public:
    static void ResetCellTracking();  // compared: 0x1a9770
};

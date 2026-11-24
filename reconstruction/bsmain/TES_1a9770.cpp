// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1a9770 TES::ResetCellTracking
// Adapted bodies: none
#include "TES_1a9770.h"

void TES::ResetCellTracking()
{
    gTrackedCellMinA = 0x7FFFFFFF;
    gTrackedCellA = nullptr;
    gTrackedCellB = nullptr;
    gTrackedCellMinB = 0x7FFFFFFF;
    gTrackedCellCount = 5;
}

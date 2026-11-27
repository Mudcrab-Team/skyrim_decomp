// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x1530d70 GetVLTemporalAccumulationFactor
#include "FreeFunction_1530d70.h"

float GetVLTemporalAccumulationFactor()
{
    if (g_vlTemporalEnabled) {
        return g_vlTemporalFactor;
    }
    return 0.0f;
}

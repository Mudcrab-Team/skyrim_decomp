// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// GetVLTemporalAccumulationFactor: CRASHLOGGER_PDB(59818@2026.10.24)
// g_vlTemporalEnabled, g_vlTemporalFactor: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern bool g_vlTemporalEnabled;
extern float g_vlTemporalFactor;

float GetVLTemporalAccumulationFactor();  // compared: 0x1530d70

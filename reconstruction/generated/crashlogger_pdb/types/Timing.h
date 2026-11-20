// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Timing; size 0x8
#pragma once

#include "Interval.h"
struct Timing {
    Interval sunrise;
    Interval sunset;
    unsigned char volatility;
    unsigned char moonPhaseLength;  // MoonPhaseLength in the PDB is wider than this slot
    unsigned char unk6;
    unsigned char unk7;
};
static_assert(sizeof(Timing) == 8, "Timing layout differs from the PDB");

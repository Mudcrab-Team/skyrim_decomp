// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MaxSpeeds; size 0x2c
#pragma once
struct MaxSpeeds {
    float speeds[2][5];
    float rotateWhileMovingRun;
};
static_assert(sizeof(MaxSpeeds) == 44, "MaxSpeeds layout differs from the PDB");

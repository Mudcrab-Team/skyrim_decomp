// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HandleEntry; size 0x20
#pragma once
struct HandleEntry {
    unsigned char sound_raw[16];
    unsigned long long timestamp;
    float squaredAudibleFactor;
    unsigned char undefined_1c[4];
};
static_assert(sizeof(HandleEntry) == 32, "HandleEntry layout differs from the PDB");

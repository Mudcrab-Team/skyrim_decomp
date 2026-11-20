// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Interval; size 0x2
#pragma once
struct Interval {
    unsigned char begin;
    unsigned char end;
};
static_assert(sizeof(Interval) == 2, "Interval layout differs from the PDB");

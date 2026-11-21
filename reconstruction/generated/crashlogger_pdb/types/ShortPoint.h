// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ShortPoint; size 0x4
#pragma once
struct ShortPoint {
    short x;
    short y;
};
static_assert(sizeof(ShortPoint) == 4, "ShortPoint layout differs from the PDB");

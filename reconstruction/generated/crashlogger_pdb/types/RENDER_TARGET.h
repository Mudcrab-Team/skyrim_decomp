// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RENDER_TARGET; size 0x1
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct RENDER_TARGET {
    unsigned char _pad_0[1];
};
static_assert(sizeof(RENDER_TARGET) == 1, "RENDER_TARGET layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveLoadBuffer; size 0x8
#pragma once
struct BGSSaveLoadBuffer {
    unsigned char* buffer;
};
static_assert(sizeof(BGSSaveLoadBuffer) == 8, "BGSSaveLoadBuffer layout differs from the PDB");

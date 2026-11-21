// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ADDON_DATA; size 0x4
#pragma once
struct ADDON_DATA {
    unsigned short masterParticleCap;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char pad3;
};
static_assert(sizeof(ADDON_DATA) == 4, "ADDON_DATA layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: VOICE_TYPE_DATA; size 0x1
#pragma once
struct VOICE_TYPE_DATA {
    unsigned char flags;  // Flag in the PDB is wider than this slot
};
static_assert(sizeof(VOICE_TYPE_DATA) == 1, "VOICE_TYPE_DATA layout differs from the PDB");

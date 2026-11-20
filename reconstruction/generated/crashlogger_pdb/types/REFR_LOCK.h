// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: REFR_LOCK; size 0x20
#pragma once

struct TESKey;
struct REFR_LOCK {
    unsigned char baseLevel;
    unsigned char pad01;
    unsigned short pad02;
    unsigned int pad04;
    TESKey* key;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char pad11;
    unsigned short pad12;
    unsigned int numTries;
    unsigned int unk18;
    unsigned int pad1C;
};
static_assert(sizeof(REFR_LOCK) == 32, "REFR_LOCK layout differs from the PDB");

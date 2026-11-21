// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CriticalData; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct SpellItem_847bf892;
struct CriticalData {
    float prcntMult;
    unsigned int pad04;
    SpellItem_847bf892* effect;
    unsigned short damage;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char pad13;
    unsigned int pad14;
};
static_assert(sizeof(CriticalData) == 24, "CriticalData layout differs from the PDB");

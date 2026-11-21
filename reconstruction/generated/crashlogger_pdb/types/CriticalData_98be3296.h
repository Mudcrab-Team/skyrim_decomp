// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CriticalData; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "EnumSet_RE__TESObjectWEAP__CriticalData__Flag_unsigned_char_d419cc9b.h"
struct SpellItem;
struct CriticalData_98be3296 {
    float prcntMult;
    unsigned int pad04;
    SpellItem* effect;
    unsigned short damage;
    EnumSet_RE__TESObjectWEAP__CriticalData__Flag_unsigned_char_d419cc9b flags;
    unsigned char pad13;
    unsigned int pad14;
};
static_assert(sizeof(CriticalData_98be3296) == 24, "CriticalData_98be3296 layout differs from the PDB");

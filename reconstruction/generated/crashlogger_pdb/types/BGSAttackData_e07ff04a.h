// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAttackData; size 0x50
// one of 2 different PDB types sharing this name
#pragma once

#include "AttackData.h"
#include "BSFixedString_char_83b572b4.h"
#include "NiRefObject_f24a9221.h"
struct BGSAttackData_e07ff04a {
    NiRefObject_f24a9221 _base;
    BSFixedString_char_83b572b4 event;
    AttackData data;
};
static_assert(sizeof(BGSAttackData_e07ff04a) == 80, "BGSAttackData_e07ff04a layout differs from the PDB");

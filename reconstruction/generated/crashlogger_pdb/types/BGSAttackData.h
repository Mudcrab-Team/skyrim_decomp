// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAttackData; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AttackData.h"
#include "NiRefObject.h"
struct BGSAttackData {
    NiRefObject _base;
    unsigned char event_raw[8];
    AttackData data;
};
static_assert(sizeof(BGSAttackData) == 80, "BGSAttackData layout differs from the PDB");

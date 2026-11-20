// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatSearchDoor; size 0xc
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
struct CombatSearchDoor {
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 doorHandle;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 linkedDoorHandle;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char undefined_b[1];
};
static_assert(sizeof(CombatSearchDoor) == 12, "CombatSearchDoor layout differs from the PDB");

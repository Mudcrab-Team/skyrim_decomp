// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESQuestTarget; size 0x60
#pragma once

#include "EnumSet_RE__TESQuestTarget__Flag_unsigned_char_d72d72a2.h"
#include "TESCondition.h"
#include "TeleportPath.h"
struct TESQuestTarget {
    EnumSet_RE__TESQuestTarget__Flag_unsigned_char_d72d72a2 flags;
    unsigned char pad01[7];
    TESCondition conditions;
    unsigned int alias;
    unsigned int pad14;
    TeleportPath teleportPath;
};
static_assert(sizeof(TESQuestTarget) == 96, "TESQuestTarget layout differs from the PDB");

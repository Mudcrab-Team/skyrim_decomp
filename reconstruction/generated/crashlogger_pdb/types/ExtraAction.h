// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraAction; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
struct TESObjectREFR_b225f218;
struct ExtraAction {
    BSExtraData_4ca6af76 _base;
    unsigned char action;  // OBJECT_ACTION in the PDB is wider than this slot
    unsigned char pad11;
    unsigned short pad12;
    unsigned int pad14;
    TESObjectREFR_b225f218* actionRef;
};
static_assert(sizeof(ExtraAction) == 32, "ExtraAction layout differs from the PDB");

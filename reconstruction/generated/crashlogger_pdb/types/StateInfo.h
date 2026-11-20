// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StateInfo; size 0x78
#pragma once

#include "hkbBindable_7236c8b2.h"
struct hkReferencedObject_2e7f2489;
struct StateInfo {
    hkbBindable_7236c8b2 _base;
    unsigned long long unk30;
    unsigned long long unk38;
    unsigned long long unk40;
    unsigned long long unk48;
    unsigned long long unk50;
    hkReferencedObject_2e7f2489* fld58;
    unsigned long long unk60;
    unsigned long long unk68;
    unsigned long long unk70;
};
static_assert(sizeof(StateInfo) == 120, "StateInfo layout differs from the PDB");

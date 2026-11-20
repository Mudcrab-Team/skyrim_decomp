// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DataItem; size 0x18
#pragma once

#include "NiPointer_RE__NiAVObject_9e3aa701.h"
struct BGSProjectile_dfe2d43e;
struct DataItem {
    NiPointer_RE__NiAVObject_9e3aa701 arrow3D;
    unsigned long long timeStamp;
    BGSProjectile_dfe2d43e* source;
};
static_assert(sizeof(DataItem) == 24, "DataItem layout differs from the PDB");

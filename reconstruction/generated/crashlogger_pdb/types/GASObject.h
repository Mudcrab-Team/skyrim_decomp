// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GASObject; size 0x68
#pragma once

#include "GASObjectInterface.h"
#include "GASRefCountBase_RE__GASObject_199d9b3b.h"
struct GASObject {
    GASRefCountBase_RE__GASObject_199d9b3b _base;
    GASObjectInterface _base_GASObjectInterface;
    unsigned long long unk38;
    unsigned long long unk40;
    unsigned long long unk48;
    unsigned long long unk50;
    unsigned long long unk58;
    unsigned long long unk60;
};
static_assert(sizeof(GASObject) == 104, "GASObject layout differs from the PDB");

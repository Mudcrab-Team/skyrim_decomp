// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GASStringManager; size 0x58
#pragma once

#include "GRefCountBase_RE__GASStringManager_323_e7461307.h"
#include "GStringHash_RE__GASString_3732f1e4.h"
struct GMemoryHeap;
struct GASStringManager {
    GRefCountBase_RE__GASStringManager_323_e7461307 _base;
    GStringHash_RE__GASString_3732f1e4 unk10;
    GMemoryHeap* heap;
    unsigned long long unk20;
    void* unk28;
    unsigned long long unk30;
    unsigned long long unk38;
    unsigned long long unk40;
    unsigned long long unk48;
    unsigned long long unk50;
};
static_assert(sizeof(GASStringManager) == 88, "GASStringManager layout differs from the PDB");

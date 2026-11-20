// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HeapLimit; size 0x30
#pragma once

#include "LimitHandler.h"
struct HeapLimit {
    LimitHandler _base;
    unsigned long long unk08;
    unsigned long long unk10;
    unsigned long long unk18;
    unsigned long long unk20;
    unsigned long long unk28;
};
static_assert(sizeof(HeapLimit) == 48, "HeapLimit layout differs from the PDB");

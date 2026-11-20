// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSStream; size 0x638
#pragma once

#include "NiPointer_RE__BSNodeReferences_6915673c.h"
#include "NiStream.h"
struct BSStream {
    NiStream _base;
    void* objectRefMap;
    NiPointer_RE__BSNodeReferences_6915673c nodeReferences;
    unsigned long long unk630;
};
static_assert(sizeof(BSStream) == 1592, "BSStream layout differs from the PDB");

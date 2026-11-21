// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Record; size 0x28
#pragma once

#include "NiPoint3.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
struct Record {
    NiPointer_RE__NiAVObject_9e3aa701 object;
    NiPoint3 intersect;
    NiPoint3 normal;
    float distance;
    unsigned int pad24;
};
static_assert(sizeof(Record) == 40, "Record layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EntryData; size 0x8
#pragma once

#include "ENTRY_POINT.h"
#include "ENTRY_POINT_FUNCTION.h"
struct EntryData {
    ENTRY_POINT entryPoint;
    ENTRY_POINT_FUNCTION function;
    unsigned char numArgs;
    unsigned char unk3;
    unsigned int unk4;
};
static_assert(sizeof(EntryData) == 8, "EntryData layout differs from the PDB");

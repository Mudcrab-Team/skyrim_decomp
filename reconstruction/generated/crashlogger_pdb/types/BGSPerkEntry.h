// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPerkEntry; size 0x10
#pragma once

#include "Header.h"
struct BGSPerkEntry_vtbl;
struct BGSPerkEntry {
    BGSPerkEntry_vtbl* __vftable;
    Header header;
};
static_assert(sizeof(BGSPerkEntry) == 16, "BGSPerkEntry layout differs from the PDB");

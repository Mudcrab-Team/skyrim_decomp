// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::BSPortal *>; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct BSPortal;
struct BSTArray_RE__BSPortal_c410012f_69b7877c {
    BSPortal** _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__BSPortal_c410012f_69b7877c) == 24, "BSTArray_RE__BSPortal_c410012f_69b7877c layout differs from the PDB");

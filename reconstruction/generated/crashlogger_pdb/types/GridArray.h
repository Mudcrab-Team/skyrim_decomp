// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GridArray; size 0x18
#pragma once

struct GridArray_vtbl;
struct GridArray {
    GridArray_vtbl* __vftable;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int length;
    unsigned int pad14;
};
static_assert(sizeof(GridArray) == 24, "GridArray layout differs from the PDB");

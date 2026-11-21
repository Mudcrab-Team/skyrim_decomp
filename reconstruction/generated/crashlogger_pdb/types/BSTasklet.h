// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTasklet; size 0x10
#pragma once

struct BSTasklet_vtbl;
struct BSTasklet {
    BSTasklet_vtbl* __vftable;
    unsigned char undefined_8[8];
};
static_assert(sizeof(BSTasklet) == 16, "BSTasklet layout differs from the PDB");

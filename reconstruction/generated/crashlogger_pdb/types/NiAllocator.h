// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiAllocator; size 0x8
#pragma once

struct NiAllocator_vtbl;
struct NiAllocator {
    NiAllocator_vtbl* __vftable;
};
static_assert(sizeof(NiAllocator) == 8, "NiAllocator layout differs from the PDB");

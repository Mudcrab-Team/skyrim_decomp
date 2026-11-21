// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMemoryAllocator; size 0x8
#pragma once

struct hkMemoryAllocator_vtbl;
struct hkMemoryAllocator {
    hkMemoryAllocator_vtbl* __vftable;
};
static_assert(sizeof(hkMemoryAllocator) == 8, "hkMemoryAllocator layout differs from the PDB");

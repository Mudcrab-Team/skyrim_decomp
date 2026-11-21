// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiMemManager; size 0x8
#pragma once

struct NiAllocator;
struct NiMemManager {
    NiAllocator* allocator;
};
static_assert(sizeof(NiMemManager) == 8, "NiMemManager layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMemoryRouter; size 0x78
#pragma once

#include "hkLifoAllocator.h"
struct hkMemoryAllocator;
struct hkMemoryRouter {
    hkLifoAllocator Stack;
    hkMemoryAllocator* Temp;
    hkMemoryAllocator* Heap;
    hkMemoryAllocator* Debug;
    hkMemoryAllocator* Solver;
    void* UserData;
};
static_assert(sizeof(hkMemoryRouter) == 120, "hkMemoryRouter layout differs from the PDB");

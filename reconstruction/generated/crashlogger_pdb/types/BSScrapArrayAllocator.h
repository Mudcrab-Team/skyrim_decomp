// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSScrapArrayAllocator; size 0x18
#pragma once

struct ScrapHeap_aea37981;
struct BSScrapArrayAllocator {
    ScrapHeap_aea37981* _allocator;
    void* _data;
    unsigned int _capacity;
    unsigned char undefined_14[4];
};
static_assert(sizeof(BSScrapArrayAllocator) == 24, "BSScrapArrayAllocator layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MegaBlockPage; size 0x200000
#pragma once

struct BlockPage;
struct MegaBlockPage {
    unsigned char mem[2088960];
    unsigned char blockPages_raw[8160];
    MegaBlockPage* left;
    MegaBlockPage* right;
    BlockPage* freeBlockPages;
    unsigned short numFreeBlockPages;
    unsigned short nextBlockPageAlloc;
    bool decommitted;
    unsigned char pad1FFFFD;
    unsigned short pad1FFFFE;
};
static_assert(sizeof(MegaBlockPage) == 2097152, "MegaBlockPage layout differs from the PDB");

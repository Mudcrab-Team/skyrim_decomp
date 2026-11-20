// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BlockPage; size 0x20
#pragma once

struct FreeBlock;
struct BlockPage {
    BlockPage* left;
    BlockPage* right;
    FreeBlock* blocks;
    unsigned short totalElem;
    unsigned short freeElem;
    unsigned int pad1C;
};
static_assert(sizeof(BlockPage) == 32, "BlockPage layout differs from the PDB");

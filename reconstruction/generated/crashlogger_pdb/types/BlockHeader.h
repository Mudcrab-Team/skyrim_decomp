// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BlockHeader; size 0x1
#pragma once
struct BlockHeader {
    unsigned char _pad_0[1];
};
static_assert(sizeof(BlockHeader) == 1, "BlockHeader layout differs from the PDB");

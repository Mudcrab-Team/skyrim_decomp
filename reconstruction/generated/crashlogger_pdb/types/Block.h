// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Block; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct Block {
    unsigned long long sizeFlags;
    Block* prev;
};
static_assert(sizeof(Block) == 16, "Block layout differs from the PDB");

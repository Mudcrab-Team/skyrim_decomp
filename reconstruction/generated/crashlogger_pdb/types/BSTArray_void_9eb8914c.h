// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<void *>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct BSTArray_void_9eb8914c {
    void** _data;
    unsigned int _capacity;
    unsigned int pad0C;
    unsigned int _size;
    unsigned int pad14;
};
static_assert(sizeof(BSTArray_void_9eb8914c) == 24, "BSTArray_void_9eb8914c layout differs from the PDB");

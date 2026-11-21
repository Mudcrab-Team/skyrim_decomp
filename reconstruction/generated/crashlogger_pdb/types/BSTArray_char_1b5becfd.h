// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<char *>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct BSTArray_char_1b5becfd {
    unsigned char** _data;
    unsigned int _capacity;
    unsigned int pad0C;
    unsigned int _size;
    unsigned int pad14;
};
static_assert(sizeof(BSTArray_char_1b5becfd) == 24, "BSTArray_char_1b5becfd layout differs from the PDB");

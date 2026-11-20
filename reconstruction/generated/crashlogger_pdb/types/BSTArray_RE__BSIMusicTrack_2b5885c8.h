// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::BSIMusicTrack *>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSIMusicTrack;
struct BSTArray_RE__BSIMusicTrack_2b5885c8 {
    BSIMusicTrack** _data;
    unsigned int _capacity;
    unsigned int pad0C;
    unsigned int _size;
    unsigned int pad14;
};
static_assert(sizeof(BSTArray_RE__BSIMusicTrack_2b5885c8) == 24, "BSTArray_RE__BSIMusicTrack_2b5885c8 layout differs from the PDB");

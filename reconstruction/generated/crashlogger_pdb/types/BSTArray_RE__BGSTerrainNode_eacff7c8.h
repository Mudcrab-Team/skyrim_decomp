// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::BGSTerrainNode *>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BGSTerrainNode;
struct BSTArray_RE__BGSTerrainNode_eacff7c8 {
    BGSTerrainNode** _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__BGSTerrainNode_eacff7c8) == 24, "BSTArray_RE__BGSTerrainNode_eacff7c8 layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::TESObjectSTAT *>; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct TESObjectSTAT_9b49bb32;
struct BSTArray_RE__TESObjectSTAT_b213d88b_a60fa518 {
    TESObjectSTAT_9b49bb32** _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__TESObjectSTAT_b213d88b_a60fa518) == 24, "BSTArray_RE__TESObjectSTAT_b213d88b_a60fa518 layout differs from the PDB");

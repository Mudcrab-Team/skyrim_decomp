// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFadeNodeMap; size 0x20
#pragma once
struct BSFadeNodeMap {
    char32_t* vftable;
    unsigned int hashSize;
    unsigned char undefined_c[4];
    char32_t** buckets;
    unsigned int count;
    unsigned char undefined_1c[4];
};
static_assert(sizeof(BSFadeNodeMap) == 32, "BSFadeNodeMap layout differs from the PDB");

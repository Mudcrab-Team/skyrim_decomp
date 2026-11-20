// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSStreamHeader; size 0xc8
#pragma once
struct BSStreamHeader {
    unsigned int version;
    unsigned char author[64];
    unsigned char processScript[64];
    unsigned char exportScript[64];
    unsigned int padC4;
};
static_assert(sizeof(BSStreamHeader) == 200, "BSStreamHeader layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BigTriangle; size 0x10
#pragma once
struct BigTriangle {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short pad06;
    unsigned int material;
    unsigned short weldingInfo;
    unsigned short transformIndex;
};
static_assert(sizeof(BigTriangle) == 16, "BigTriangle layout differs from the PDB");

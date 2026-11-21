// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkVector4Comparison; size 0x10
#pragma once
struct hkVector4Comparison {
    unsigned char mask[16];
};
static_assert(sizeof(hkVector4Comparison) == 16, "hkVector4Comparison layout differs from the PDB");

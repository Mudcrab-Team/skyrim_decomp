// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CachedValueData; size 0x8
#pragma once
struct CachedValueData {
    float value;
    bool invalid;
    unsigned char pad5;
    unsigned short pad6;
};
static_assert(sizeof(CachedValueData) == 8, "CachedValueData layout differs from the PDB");

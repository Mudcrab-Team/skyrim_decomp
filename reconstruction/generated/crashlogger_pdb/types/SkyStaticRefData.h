// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SkyStaticRefData; size 0x8
#pragma once
struct SkyStaticRefData {
    int refrHandle;
    unsigned int unk4;
};
static_assert(sizeof(SkyStaticRefData) == 8, "SkyStaticRefData layout differs from the PDB");

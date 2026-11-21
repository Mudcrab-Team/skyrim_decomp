// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GenericFillData; size 0x18
#pragma once
struct GenericFillData {
    unsigned char nearAlias_raw[24];
};
static_assert(sizeof(GenericFillData) == 24, "GenericFillData layout differs from the PDB");

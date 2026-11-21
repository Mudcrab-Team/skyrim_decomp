// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UnusedExtensionData; size 0x10
#pragma once
struct UnusedExtensionData {
    unsigned int extUnitId;
    unsigned char pad04;
    unsigned char dataLength;
    unsigned char data[10];
};
static_assert(sizeof(UnusedExtensionData) == 16, "UnusedExtensionData layout differs from the PDB");

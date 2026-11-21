// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GUID; size 0x10
#pragma once
struct GUID {
    unsigned int data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};
static_assert(sizeof(GUID) == 16, "GUID layout differs from the PDB");

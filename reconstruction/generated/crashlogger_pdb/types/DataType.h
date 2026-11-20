// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DataType; size 0x10
#pragma once
struct DataType {
    float minDistance;
    float maxDistance;
    unsigned char curve[5];
    unsigned char pad15;
    unsigned short pad16;
};
static_assert(sizeof(DataType) == 16, "DataType layout differs from the PDB");

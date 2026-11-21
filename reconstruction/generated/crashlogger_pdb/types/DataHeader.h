// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DataHeader; size 0x8
#pragma once
struct DataHeader {
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char unk09;
    unsigned char priority;
    unsigned char unk0B;
    unsigned int unk0C;
};
static_assert(sizeof(DataHeader) == 8, "DataHeader layout differs from the PDB");

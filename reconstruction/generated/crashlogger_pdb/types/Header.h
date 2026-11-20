// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Header; size 0x8
#pragma once
struct Header {
    unsigned char rank;
    unsigned char priority;
    unsigned short unk2;
    unsigned int unk4;
};
static_assert(sizeof(Header) == 8, "Header layout differs from the PDB");

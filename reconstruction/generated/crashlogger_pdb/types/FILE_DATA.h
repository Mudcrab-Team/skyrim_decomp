// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FILE_DATA; size 0x10
#pragma once
struct FILE_DATA {
    unsigned char* buffer;
    unsigned int bufferSize;
    unsigned int pad0C;
};
static_assert(sizeof(FILE_DATA) == 16, "FILE_DATA layout differs from the PDB");

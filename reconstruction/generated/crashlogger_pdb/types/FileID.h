// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FileID; size 0x8
#pragma once
struct FileID {
    unsigned int file;
    unsigned char ext[4];
};
static_assert(sizeof(FileID) == 8, "FileID layout differs from the PDB");

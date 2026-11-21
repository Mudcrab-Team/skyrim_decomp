// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ArchiveFile; size 0x1
#pragma once
struct ArchiveFile {
    unsigned char _pad_0[1];
};
static_assert(sizeof(ArchiveFile) == 1, "ArchiveFile layout differs from the PDB");

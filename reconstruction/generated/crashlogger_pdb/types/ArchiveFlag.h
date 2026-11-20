// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ArchiveFlag; size 0x4
#pragma once
struct ArchiveFlag {
    unsigned int flag;
};
static_assert(sizeof(ArchiveFlag) == 4, "ArchiveFlag layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: _iobuf; size 0x8
#pragma once
struct iobuf {
    void* _Placeholder;
};
static_assert(sizeof(iobuf) == 8, "iobuf layout differs from the PDB");

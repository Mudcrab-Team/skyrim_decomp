// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBinaryStream; size 0x20
#pragma once

struct NiBinaryStream_vtbl;
struct NiBinaryStream {
    NiBinaryStream_vtbl* __vftable;
    unsigned int _absoluteCurrentPos;
    unsigned int _pad0C;
    unsigned char _readFn_raw[8];
    unsigned char _writeFn_raw[8];
};
static_assert(sizeof(NiBinaryStream) == 32, "NiBinaryStream layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StreamBase; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct StreamBase_vtbl;
struct StreamBase {
    StreamBase_vtbl* __vftable;
    unsigned int totalSize;
    unsigned int pad0C;
    unsigned int flags;
    unsigned char undefined_14[4];
};
static_assert(sizeof(StreamBase) == 24, "StreamBase layout differs from the PDB");

// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSStorage; size 0x20
#pragma once

#include "BSIntrusiveRefCounted.h"
struct BSStorage_vtbl;
struct WriteBuffer;
struct BSStorage {
    BSStorage_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    bool swapBytes;
    bool unk0D;
    unsigned short unk0E;
    WriteBuffer* buffer;
    bool bWriteToBuffer;
    unsigned char undefined_19[7];
};
static_assert(sizeof(BSStorage) == 32, "BSStorage layout differs from the PDB");

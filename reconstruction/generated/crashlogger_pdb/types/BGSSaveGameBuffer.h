// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveGameBuffer; size 0x18
#pragma once

struct BGSSaveGameBuffer_vtbl;
struct BGSSaveGameBuffer {
    BGSSaveGameBuffer_vtbl* __vftable;
    void* buffer;
    unsigned int size;
    unsigned int bufferPosition;
};
static_assert(sizeof(BGSSaveGameBuffer) == 24, "BGSSaveGameBuffer layout differs from the PDB");

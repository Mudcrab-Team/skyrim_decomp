// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIntrusiveRefCounted; size 0x4
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct BSIntrusiveRefCounted {
    unsigned int _refCount;
};
static_assert(sizeof(BSIntrusiveRefCounted) == 4, "BSIntrusiveRefCounted layout differs from the PDB");

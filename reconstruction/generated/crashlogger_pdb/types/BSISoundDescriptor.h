// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSISoundDescriptor; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSISoundDescriptor_vtbl;
struct BSISoundDescriptor {
    BSISoundDescriptor_vtbl* __vftable;
};
static_assert(sizeof(BSISoundDescriptor) == 8, "BSISoundDescriptor layout differs from the PDB");

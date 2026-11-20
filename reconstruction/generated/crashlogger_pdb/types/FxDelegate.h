// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FxDelegate; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "GHash_RE__GString_RE__FxDelegate__CallbackDefn_RE__FxDelegate__CallbackHashFunctor_9b72e017.h"
struct FxDelegate__VFTable;
struct GFxState__VFTable;
#pragma pack(push, 4)
struct FxDelegate {
    FxDelegate__VFTable* vftable_FxDelegate_0;
    GFxState__VFTable* vftable_GFxState_8;
    int RefCount_10;
    GHash_RE__GString_RE__FxDelegate__CallbackDefn_RE__FxDelegate__CallbackHashFunctor_9b72e017 callbacks;
    unsigned char _pad_0[4];
};
#pragma pack(pop)
static_assert(sizeof(FxDelegate) == 32, "FxDelegate layout differs from the PDB");

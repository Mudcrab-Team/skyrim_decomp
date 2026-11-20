// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSExtraData_vtbl; size 0x18
#pragma once

#include "hkpPhantomType.h"
struct BSExtraData_vtbl {
    void (*_dtor_BSExtraData)(void);
    hkpPhantomType (*GetType)(void);
    bool (*IsNotEqual)(char32_t* );
};
static_assert(sizeof(BSExtraData_vtbl) == 24, "BSExtraData_vtbl layout differs from the PDB");

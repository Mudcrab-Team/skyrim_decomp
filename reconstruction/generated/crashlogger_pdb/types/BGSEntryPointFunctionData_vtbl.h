// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEntryPointFunctionData_vtbl; size 0x40
#pragma once

#include "hkpPhantomType.h"
struct BGSEntryPointFunctionData_vtbl {
    void (*_dtor_BGSEntryPointFunctionData)(void);
    hkpPhantomType (*GetType)(void);
    void (*LoadImpl)(char32_t* , unsigned int);
    void (*InitItem)(char32_t* );
    void (*ApplyOnAdd)(char32_t* , char32_t* );
    unsigned short (*GetID)(void);
    void (*SetParentPerk)(char32_t* );
    char32_t*(*GetParentPerk)(void);
};
static_assert(sizeof(BGSEntryPointFunctionData_vtbl) == 64, "BGSEntryPointFunctionData_vtbl layout differs from the PDB");

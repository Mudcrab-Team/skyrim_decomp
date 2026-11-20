// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: KeyInterface_vtbl; size 0x38
#pragma once

#include "KeyType.h"
struct KeyInterface_vtbl {
    void (*_dtor_KeyInterface)(void);
    unsigned int (*AddRef)(void);
    unsigned int (*Release)(void);
    KeyType (*GetKeyType)(unsigned short);
    void (*GetHashCode)(char32_t* );
    bool (*KeyEquals)(char32_t* , char32_t* );
    unsigned char*(*GetFileURL)(char32_t* );
};
static_assert(sizeof(KeyInterface_vtbl) == 56, "KeyInterface_vtbl layout differs from the PDB");

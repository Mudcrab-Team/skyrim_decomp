// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderMaterial_vtbl; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Feature.h"
#include "hkpPhantomType.h"
struct BSShaderMaterial_vtbl {
    void (*_dtor_BSShaderMaterial)(void);
    char32_t*(*Create)(char32_t* );
    void (*CopyMembers)(char32_t* );
    bool (*DoIsCopy)(char32_t* );
    unsigned int (*ComputeCRC32)(unsigned int);
    char32_t*(*GetDefault)(void);
    Feature (*GetFeature)(void);
    hkpPhantomType (*GetType)(void);
};
static_assert(sizeof(BSShaderMaterial_vtbl) == 64, "BSShaderMaterial_vtbl layout differs from the PDB");

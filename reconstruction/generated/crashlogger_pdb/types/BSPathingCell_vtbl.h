// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingCell_vtbl; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ErrorCode.h"
#include "hkpPhantomType.h"
struct BSPathingCell_vtbl {
    void (*_dtor_BSPathingCell)(void);
    hkpPhantomType (*GetType)(void);
    ErrorCode (*Write)(unsigned long long, unsigned char* );
    ErrorCode (*Read)(unsigned long long, unsigned char* );
    void (*FixupNumericID)(char32_t* );
    void (*GetSpace)(char32_t* );
    char32_t*(*GetBhkWorld)(void);
    bool (*QValid)(void);
    bool (*QAttached)(void);
    bool (*QLoaded)(void);
    bool (*IsInSameSpace)(char32_t* );
};
static_assert(sizeof(BSPathingCell_vtbl) == 88, "BSPathingCell_vtbl layout differs from the PDB");

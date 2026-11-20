// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingRequest_vtbl; size 0x38
#pragma once

#include "ErrorCode.h"
#include "hkpPhantomType.h"
struct BSPathingRequest_vtbl {
    void (*_dtor_BSPathingRequest)(void);
    hkpPhantomType (*GetType)(void);
    void (*CopyTo)(char32_t* );
    ErrorCode (*Write)(unsigned long long, unsigned char* );
    ErrorCode (*Read)(unsigned long long, unsigned char* );
    void (*CheckValid)(void);
    void (*PrintDebugText)(char32_t* );
};
static_assert(sizeof(BSPathingRequest_vtbl) == 56, "BSPathingRequest_vtbl layout differs from the PDB");
